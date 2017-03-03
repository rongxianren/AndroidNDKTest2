#include "com_rongxianren_androidndktest_JNIHelper.h"
#include <stdlib.h>
#include <android/log.h>
#include <string.h>

#define TAG "NATIVE_TEST"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_rongxianren_androidndktest_JNIHelper_getStringFromC(JNIEnv *env, jobject obj){
    jstring j_srt = "I am from C code";
    return  (*env)->NewStringUTF(env, j_srt);
}

JNIEXPORT void JNICALL Java_com_rongxianren_androidndktest_JNIHelper_accessField(JNIEnv * env, jobject obj){
    jclass jclazz = (*env)->GetObjectClass(env, obj);
    jfieldID field_id = (*env)->GetFieldID(env, jclazz, "message", "Ljava/lang/String;");
    jstring j_str = (*env)->GetObjectField(env, obj, field_id);

    char* c_str = (*env)->GetStringUTFChars(env, j_str, NULL);

    char text[500] = "Native C Code  ";

    strcat( text, c_str);


    jstring content = (*env)->NewStringUTF(env, text);

    (*env)->SetObjectField(env, obj, field_id,content);

    (*env)->ReleaseStringUTFChars(env, j_str, c_str);
}


JNIEXPORT jstring JNICALL Java_com_rongxianren_androidndktest_JNIHelper_accessMethod(JNIEnv *env, jobject obj){

    jclass clazz = (*env)->GetObjectClass(env, obj);
    jmethodID methodID = (*env)->GetMethodID(env, clazz, "callFromNativeCode", "()Ljava/lang/String;");
    jstring jstr = (*env)->CallObjectMethod(env, obj, methodID);
    return jstr;
}

JNIEXPORT void JNICALL Java_com_rongxianren_androidndktest_JNIHelper_accessStaticField(JNIEnv *env, jclass clazz){
    jfieldID field_id = (*env)->GetStaticFieldID(env, clazz, "sCount", "I");
    jint sCount= (*env)->GetStaticIntField(env, clazz, field_id);
    sCount = sCount+1000;
    (*env)->SetStaticIntField(env, clazz, field_id, sCount);
}

JNIEXPORT jstring JNICALL Java_com_rongxianren_androidndktest_JNIHelper_accessStaticMethod(JNIEnv *env, jclass clazz){
    jmethodID methodID = (*env)->GetStaticMethodID(env, clazz, "callFromNativeCodeStatic", "()Ljava/lang/String;");
    jstring jstr = (*env)->CallStaticObjectMethod(env, clazz, methodID);
    return jstr;
}