/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wiyun_engine_BaseWYObject */

#ifndef _Included_com_wiyun_engine_BaseWYObject
#define _Included_com_wiyun_engine_BaseWYObject
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_BaseWYObject
 * Method:    nativeAutoRelease
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_nativeAutoRelease
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_BaseWYObject
 * Method:    setName
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_setName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_wiyun_engine_BaseWYObject
 * Method:    getName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_wiyun_engine_BaseWYObject_getName
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_BaseWYObject
 * Method:    connectNativeTargetSelector
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_connectNativeTargetSelector
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif