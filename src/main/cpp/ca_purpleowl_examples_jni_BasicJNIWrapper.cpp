//
// Created by Mighty Chip on 2018-02-18.
//

#include <string>
#include "basicCalc.h"
#include "ca_purpleowl_examples_jni_BasicJNIWrapper.h"

JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_genericHello
        (JNIEnv *env, jobject) {
    const char* greeting = "Hello";
    return env->NewStringUTF(greeting);
}

JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_personalHello
        (JNIEnv *env, jobject, jstring name) {
    std::string cName = env->GetStringUTFChars(name, nullptr);
    cName = "Hello " + cName + "!";
    return env->NewStringUTF(cName.c_str());
}

JNIEXPORT jint JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_addNumbers
        (JNIEnv *, jobject, jint numOne, jint numTwo) {
    return basicCalc::addThese(numOne, numTwo);
}

JNIEXPORT jint JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_subtractNumbers
        (JNIEnv *, jobject, jint numOne, jint numTwo) {
    return basicCalc::subtract(numOne, numTwo);
}