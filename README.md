## BingBong
Bing Bong is a garbage bin device that follows a person and helps the user hold garbage. Bing Bong is activated through an Android app. When the trash inside Bing Bong hits a certain weight or overflows, Bing Bong dumps the trash into the trash can and returns to its docking station.

## Android app
https://github.com/DreadSirius/BingBongApp

## Setting up github
    git remote add origin git@github.com:eric-foy/BingBong.git
    git checkout -b yourname
    
## Setting up tflite model
    https://github.com/EdjeElectronics/TensorFlow-Lite-Object-Detection-on-Android-and-Raspberry-Pi/blob/master/deploy_guides/Raspberry_Pi_Guide.md

    That guide did not work for me with the 16MP camera. I am now using this one and have modified it in our repo to only detect people.
    https://www.youtube.com/watch?v=3YqbO2AlepM
    https://github.com/freedomwebtech/tflite-custom-object-bookworm

    Run 'DISPLAY=:0 python detect_person.py'
