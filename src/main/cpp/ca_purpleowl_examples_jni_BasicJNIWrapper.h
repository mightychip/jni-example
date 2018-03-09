/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ca_purpleowl_examples_jni_BasicJNIWrapper */

#ifndef _Included_ca_purpleowl_examples_jni_BasicJNIWrapper
#define _Included_ca_purpleowl_examples_jni_BasicJNIWrapper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ca_purpleowl_examples_jni_BasicJNIWrapper
 * Method:    genericHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_genericHello
  (JNIEnv *, jobject);

/*
 * Class:     ca_purpleowl_examples_jni_BasicJNIWrapper
 * Method:    personalHello
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_personalHello
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ca_purpleowl_examples_jni_BasicJNIWrapper
 * Method:    addNumbers
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_addNumbers
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     ca_purpleowl_examples_jni_BasicJNIWrapper
 * Method:    subtractNumbers
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_subtractNumbers
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     ca_purpleowl_examples_jni_BasicJNIWrapper
 * Method:    oneMore
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_ca_purpleowl_examples_jni_BasicJNIWrapper_oneMore
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
