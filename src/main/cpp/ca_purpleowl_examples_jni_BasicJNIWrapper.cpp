//
// Created by Mighty Chip on 2018-02-18.
//

#include <string>
#include "ca_purpleowl_examples_jni_BasicJNIWrapper.h"
#include "basicCalc.h"
#include "simpleFunction.h"

JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_genericHello
        (JNIEnv *env, jobject) {
    //We'll just implement a simple method here.  This is the very basic thing that
    //led me down the path of learning JNI!
    const char* greeting = sayHello();
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

JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_concatenateMe
        (JNIEnv *env, jobject, jobjectArray array) {
    std::string sentence;
    int count = env->GetArrayLength(array);
    for(int i=0; i < count; i++) {
        //We're going to need to cast here... we know this is an array of strings, anyways.
        auto element = (jstring)env->GetObjectArrayElement(array, i);
        if(env->ExceptionOccurred()) {
            //Oops, we did something bad!!
            break;
        }

        std::string word = env->GetStringUTFChars(element, nullptr);

        sentence += word + " ";

        env->DeleteLocalRef(element);
    }

    return env->NewStringUTF(sentence.c_str());
}