package com.rongxianren.androidndktest;

/**
 * Created by wty on 2017/3/2.
 */

public class JNIHelper {

    // Ljava/lang/String;
    public String message = "I will change in C Code";

    //    I
    public static int sCount = 100;

    static {
        System.loadLibrary("jni_test");
    }


    public native String getStringFromC();

    //  ()V
    public native void accessField();

    //()V
    public native String accessMethod();

    //()V
    public native static void accessStaticField();

    //()V
    public native static String accessStaticMethod();


    //    ()Ljava/lang/String;
    public String callFromNativeCode() {
        return "I am com from Java world";
    }


    //()Ljava/lang/String;
    private static String callFromNativeCodeStatic() {
        return " I am a static method from Java World!!!";
    }

}
