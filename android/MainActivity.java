package com.example.hellowrld;

import android.annotation.SuppressLint;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import android.view.View;
import android.widget.Switch;
import android.widget.TextView;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.Socket;
import android.os.StrictMode;

public class MainActivity extends AppCompatActivity {

    TextView textView;
    @SuppressLint("UseSwitchCompatOrMaterialCode")
    Switch aSwitch;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        aSwitch = findViewById(R.id.switch1);
    }

    public void updateText(View view){
        if(aSwitch.isChecked()){
            textView.setText(R.string.switch_activated);
        } else {
            textView.setText(R.string.switch_not_activated);
        }
        System.out.println("Button Clicked");
    }
    @SuppressLint("SetTextI18n")
    public void takeTrash(View view) throws IOException {
        if(aSwitch.isChecked()){
            textView.setText("Taking Out Trash!");

            StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
            StrictMode.setThreadPolicy(policy);

            Socket socket = new Socket("192.168.1.145", 50505);

            PrintStream printer = new PrintStream(socket.getOutputStream(), true);
            printer.write("Hello from android\n".getBytes());
            //Thread.sleep(50000L);
            printer.close();

            socket.close();

        } else {
            textView.setText("Please turn on Power First!");
        }
    }
    @SuppressLint("SetTextI18n")
    public void followMe(View view){
        if(aSwitch.isChecked()){
            textView.setText("Following!");
        } else {
            textView.setText("Please turn on Power First!");
        }
    }
    @SuppressLint("SetTextI18n")
    public void Idle(View view){
        if(aSwitch.isChecked()){
            textView.setText("Idling!");
        } else {
            textView.setText("Please turn on Power First!");
        }
    }
}