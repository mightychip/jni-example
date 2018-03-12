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
    //Here we're just handling some string manipulation.  Note that you need to use env to "translate" jstring into
    //something that C++ can work with.
    std::string cName = env->GetStringUTFChars(name, nullptr);
    cName = "Hello " + cName + "!";
    //Here, you have to translate back into jstrings to satisfy Java.
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
    //Handling arrays is a bit of a pain.  First, you'll need to get the length...
    int count = env->GetArrayLength(array);
    //Now you're going to use that length to make a counted loop.
    for(int i=0; i < count; i++) {
        //You work through the array one element at a time.  Make sure to cast the element from
        //a jobject into something meaningful.
        auto element = (jstring)env->GetObjectArrayElement(array, i);
        if(env->ExceptionOccurred()) {
            //Oops, we did something bad!!  You should be regularly checking for exceptions like this.
            break;
        }

        std::string word = env->GetStringUTFChars(element, nullptr);

        sentence += word + " ";

        //When you are done, remember to delete any local references you make.  You can only have 16 local
        //references by default (unless you ask for more), so not deleting them means you'll end up running out.
        env->DeleteLocalRef(element);
    }

    return env->NewStringUTF(sentence.c_str());
}