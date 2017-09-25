#include <jni.h>
#include <cstddef>
#include "libyuv.h"

using namespace libyuv;

extern "C" {

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_rgbToBgrInternal(JNIEnv *env, jobject,
                                                                         jbyteArray rgbArray,
                                                                         jint width,
                                                                         jint height,
                                                                         jbyteArray bgrArray) {

    jbyte *rgb = env->GetByteArrayElements(rgbArray, NULL);
    jbyte *bgr = env->GetByteArrayElements(bgrArray, NULL);

    ABGRToARGB((uint8 *) rgb, width << 2, (uint8 *) bgr, width << 2, width, height);

    env->ReleaseByteArrayElements(bgrArray, bgr, 0);
    env->ReleaseByteArrayElements(rgbArray, rgb, 0);
}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_rgb565ToI420Internal(JNIEnv *env, jobject,
                                                                             jbyteArray rgbArray,
                                                                             jint width,
                                                                             jint height,
                                                                             jbyteArray yuvArray) {
    jbyte *rgb = env->GetByteArrayElements(rgbArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    RGB565ToI420((uint8 *) rgb, width << 1, (uint8 *) yuv, width, (uint8 *) &yuv[width * height],
                 (width + 1) / 2,
                 (uint8 *) &yuv[width * height * 5 / 4], (width + 1) / 2, width, height);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(rgbArray, rgb, 0);

}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_rgb565ToArgbInternal(JNIEnv *env, jobject,
                                                                             jbyteArray rgbArray,
                                                                             jint width,
                                                                             jint height,
                                                                             jbyteArray argbArray) {
    jbyte *rgb = env->GetByteArrayElements(rgbArray, NULL);
    jbyte *argb = env->GetByteArrayElements(argbArray, NULL);

    RGB565ToARGB((uint8 *) rgb, width << 1, (uint8 *) argb, width << 2, width, height);

    env->ReleaseByteArrayElements(argbArray, argb, 0);
    env->ReleaseByteArrayElements(rgbArray, rgb, 0);

}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_bgrToNV21Internal(JNIEnv *env, jobject,
                                                                          jbyteArray bgrArray,
                                                                          jint width,
                                                                          jint height,
                                                                          jbyteArray yuvArray) {
    jbyte *bgr = env->GetByteArrayElements(bgrArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    ARGBToNV21((uint8 *) bgr, width << 2, (uint8 *) yuv, width, (uint8 *) &yuv[width * height],
               width, width, height);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(bgrArray, bgr, 0);

}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_bgrToNV12Internal(JNIEnv *env, jobject,
                                                                          jbyteArray bgrArray,
                                                                          jint width,
                                                                          jint height,
                                                                          jbyteArray yuvArray) {
    jbyte *bgr = env->GetByteArrayElements(bgrArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    ARGBToNV12((uint8 *) bgr, width << 2, (uint8 *) yuv, width, (uint8 *) &yuv[width * height],
               width, width, height);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(bgrArray, bgr, 0);
}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_bgrToI420Internal(JNIEnv *env, jobject,
                                                                          jbyteArray bgrArray,
                                                                          jint width,
                                                                          jint height,
                                                                          jbyteArray yuvArray) {
    jbyte *bgr = env->GetByteArrayElements(bgrArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    ARGBToI420((uint8 *) bgr, width << 2, (uint8 *) yuv, width, (uint8 *) &yuv[width * height],
               (width + 1) / 2,
               (uint8 *) &yuv[width * height * 5 / 4], (width + 1) / 2, width, height);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(bgrArray, bgr, 0);
}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_bgrToYV12Internal(JNIEnv *env, jobject,
                                                                          jbyteArray bgrArray,
                                                                          jint width,
                                                                          jint height,
                                                                          jbyteArray yuvArray) {
    jbyte *bgr = env->GetByteArrayElements(bgrArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    ARGBToI420((uint8 *) bgr, width << 2, (uint8 *) yuv, width,
               (uint8 *) &yuv[width * height * 5 / 4], (width + 1) / 2,
               (uint8 *) &yuv[width * height], (width + 1) / 2, width, height);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(bgrArray, bgr, 0);
}

JNIEXPORT void JNICALL
Java_cn_mrobot_system_console_camera_utils_jni_YuvUtils_I420ToNV21Internal(JNIEnv *env, jobject,
                                                                           jbyteArray i420Array,
                                                                           jint width,
                                                                           jint height,
                                                                           jbyteArray nv21Array) {
    jbyte *i420 = env->GetByteArrayElements(i420Array, NULL);
    jbyte *nv21 = env->GetByteArrayElements(nv21Array, NULL);

    I420ToNV21((uint8 *) i420, width, (uint8 *) &i420[width * height], (width + 1) / 2,
               (uint8 *) &i420[width * height * 5 / 4], (width + 1) / 2, (uint8 *) nv21, width,
               (uint8 *) &nv21[width * height], width, width, height);

    env->ReleaseByteArrayElements(i420Array, i420, 0);
    env->ReleaseByteArrayElements(nv21Array, nv21, 0);

}

} // extern "C"
