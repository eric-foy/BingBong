import argparse
import sys
import time
import serial

import cv2
import mediapipe as mp

from mediapipe.tasks import python
from mediapipe.tasks.python import vision

from utils import visualize
from picamera2 import Picamera2

from libcamera import Transform

import copy

# Global variables to calculate FPS
COUNTER, FPS = 0, 0
START_TIME = time.time()
WIDTH = 1280
HEIGHT = 720
picam2 = Picamera2()
#picam2.preview_configuration.main.size = (640,480)
picam2.preview_configuration.main.size = (WIDTH,HEIGHT)
#picam2.preview_configuration.main.size = (1920,1080)
#picam2.preview_configuration.main.size = (4656,3496)
picam2.preview_configuration.main.format = "RGB888"
#picam2.preview_configuration.transform = Transform(vflip=1)
picam2.preview_configuration.align()
picam2.configure("preview")
picam2.start()

def run(model: str, max_results: int, score_threshold: float, 
        camera_id: int, width: int, height: int, do_window: bool, do_serial: bool) -> None:
  """Continuously run inference on images acquired from the camera.

  Args:
    model: Name of the TFLite object detection model.
    max_results: Max number of detection results.
    score_threshold: The score threshold of detection results.
    camera_id: The camera id to be passed to OpenCV.
    width: The width of the frame captured from the camera.
    height: The height of the frame captured from the camera.
  """

  ser = None
  if (do_serial):
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)
    ser.reset_input_buffer()

  # Visualization parameters
  row_size = 50  # pixels
  left_margin = 24  # pixels
  text_color = (0, 0, 0)  # black
  font_size = 1
  font_thickness = 1
  fps_avg_frame_count = 10

  detection_frame = None
  detection_result_list = []

  def save_result(result: vision.ObjectDetectorResult, unused_output_image: mp.Image, timestamp_ms: int):
      global FPS, COUNTER, START_TIME

      # Calculate the FPS
      if COUNTER % fps_avg_frame_count == 0:
          FPS = fps_avg_frame_count / (time.time() - START_TIME)
          START_TIME = time.time()

      detection_result_list.append(result)
      COUNTER += 1

  # Initialize the object detection model
  base_options = python.BaseOptions(model_asset_path=model)
  options = vision.ObjectDetectorOptions(base_options=base_options,
                                         running_mode=vision.RunningMode.LIVE_STREAM,
                                         max_results=max_results, score_threshold=score_threshold,
                                         result_callback=save_result)
  detector = vision.ObjectDetector.create_from_options(options)


  # Continuously capture images from the camera and run inference
  while True:
    im= picam2.capture_array()  
#    success, image = cap.read()
#    image=cv2.resize(im,(640,480))
    image=cv2.resize(im,(WIDTH,HEIGHT))
    #image=cv2.resize(im,(4656,3496))
#    image=cv2.resize(im,(1920,1080))
    #image = cv2.flip(image, -1)

    # Convert the image from BGR to RGB as required by the TFLite model.
    rgb_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

    # Run object detection using the model.
    # TODO run slower
    detector.detect_async(mp_image, time.time_ns() // 1_000_000)

    # Show the FPS
    #fps_text = 'FPS = {:.1f}'.format(FPS)
    #text_location = (left_margin, row_size)
    current_frame = image
    #cv2.putText(current_frame, fps_text, text_location, cv2.FONT_HERSHEY_DUPLEX,
    #            font_size, text_color, font_thickness, cv2.LINE_AA)

    if detection_result_list:
        #print(detection_result_list)
        #print(len(detection_result_list))
        #print(len(detection_result_list[0].detections))
        #print(detection_result_list[0].detections[0].categories[0].category_name)

        #detection_result_list2 = copy.deepcopy(detection_result_list)

        #############################################################
        # filter detected objects to only include people.
        detections_persons = []
        for i in range(len(detection_result_list[0].detections)):
            if (detection_result_list[0].detections[i].categories[0].category_name == 'person'):
                detections_persons.append(detection_result_list[0].detections[i])
                #detection_result_list2[0].detections.remove(0)

        detection_result_list[0].detections = detections_persons
        #############################################################

        #############################################################
        # get the coordinates for the box and return if it is
        # right of center of left of center.
        if (len(detections_persons) > 0):
            detected_person = detections_persons[0]
            origin_x = detected_person.bounding_box.origin_x
            origin_y = detected_person.bounding_box.origin_y
            person_width = detected_person.bounding_box.width
            person_height = detected_person.bounding_box.height
            center_width = WIDTH / 3
            ## TODO do majority voting for the last 5 detections of left, right, or center
            if (origin_x + person_width/2 > WIDTH/2 + center_width/2):
                if (do_serial):
                    print("right")
                    #ser.reset_output_buffer()
                    #ser.reset_input_buffer()
                    ser.write(b"right\n")
                    ser.flush()
                    #time.sleep(2)
                    line = ser.readline().decode('utf-8').rstrip()
                    print(line)
                else:
                    print("right")
            elif (origin_x + person_width/2 < WIDTH/2 - center_width/2):
                if (do_serial):
                    print("left")
                    #ser.reset_output_buffer()
                    #ser.reset_input_buffer()
                    ser.write(b"left\n")
                    ser.flush()
                    #time.sleep(2)
                    line = ser.readline().decode('utf-8').rstrip()
                    print(line)
                else:
                    print("left")
            else:
                if (do_serial):
                    print("center")
                    #ser.reset_output_buffer()
                    #ser.reset_input_buffer()
                    ser.write(b"center\n")
                    #time.sleep(2)
                    ser.flush()
                    line = ser.readline().decode('utf-8').rstrip()
                    print(line)
                else:
                    print("center")
        #############################################################
        
        if (do_window):
            current_frame = visualize(current_frame, detection_result_list[0])
            detection_frame = current_frame

        detection_result_list.clear()

    if (do_window):
        if detection_frame is not None:
            cv2.imshow('object_detection', detection_frame)
            pass

    # Stop the program if the ESC key is pressed.
    if cv2.waitKey(1) == 27:
      break

  detector.close()
  cap.release()
  cv2.destroyAllWindows()


def main():
  parser = argparse.ArgumentParser(
      formatter_class=argparse.ArgumentDefaultsHelpFormatter)
  parser.add_argument(
      '--model',
      help='Path of the object detection model.',
      required=False,
      default='efficientdet_lite0.tflite')
#      default='1.tflite')
  parser.add_argument(
      '--maxResults',
      help='Max number of detection results.',
      required=False,
      default=1)
#      default=5)
  parser.add_argument(
      '--scoreThreshold',
      help='The score threshold of detection results.',
      required=False,
      type=float,
      default=0.25)
  # Finding the camera ID can be very reliant on platform-dependent methods. 
  # One common approach is to use the fact that camera IDs are usually indexed sequentially by the OS, starting from 0. 
  # Here, we use OpenCV and create a VideoCapture object for each potential ID with 'cap = cv2.VideoCapture(i)'.
  # If 'cap' is None or not 'cap.isOpened()', it indicates the camera ID is not available.
  parser.add_argument(
      '--cameraId', help='Id of camera.', required=False, type=int, default=0)
  parser.add_argument(
      '--frameWidth',
      help='Width of frame to capture from camera.',
      required=False,
      type=int,
#      default=640)
#        default=4656)
        default=WIDTH)
#        default=1920)
  parser.add_argument(
      '--frameHeight',
      help='Height of frame to capture from camera.',
      required=False,
      type=int,
#      default=480)
#        default=3496)
        default=HEIGHT)
#        default=1080)
  args = parser.parse_args()

  run(args.model, int(args.maxResults),
      args.scoreThreshold, int(args.cameraId), args.frameWidth, args.frameHeight, True, False)

def detect_person(do_window=True, do_serial=True):
    run("efficientdet_lite0.tflite", 1, 0.25, 0, WIDTH, HEIGHT, do_window, do_serial)


if __name__ == '__main__':
  #main()
  detect_person(True, True)
