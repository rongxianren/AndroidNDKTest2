package com.rongxianren.androidndktest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private JNIHelper jniHelper = new JNIHelper();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void getString(View view) {
        String str = jniHelper.getStringFromC();
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }


    public void accessField(View view) {
        System.out.println("-------调用accessField前-------message = " + jniHelper.message);
        jniHelper.accessField();
        System.out.println("-------调用accessField后-------message = " + jniHelper.message);
    }


    public void accessStaticField(View view) {
        System.out.println("-------调用accessStaticField前-------sCount = " + JNIHelper.sCount);
        jniHelper.accessStaticField();
        System.out.println("-------调用accessStaticField后-------sCount = " + JNIHelper.sCount);
    }

    public void accessMethod(View view) {
        System.out.println("-----accessMethod-------" + jniHelper.accessMethod());
    }

    public void accessStaticMethod(View view) {
        Toast.makeText(this, jniHelper.accessStaticMethod(), Toast.LENGTH_SHORT).show();
    }
}
