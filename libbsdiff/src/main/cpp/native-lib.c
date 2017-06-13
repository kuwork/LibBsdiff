#include "native-lib.h"

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_diff(JNIEnv *env, jclass type, jstring oldpath_,
                                        jstring newpath_, jstring patch_) {
    char *argv[4];
    argv[0] = "bsdiff";
    argv[1] = (*env)->GetStringUTFChars(env, oldpath_, 0);
    argv[2] = (*env)->GetStringUTFChars(env, newpath_, 0);
    argv[3] = (*env)->GetStringUTFChars(env, patch_, 0);
    bsdiff_main(4, (char *)argv);
    (*env)->ReleaseStringUTFChars(env, oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch_, argv[3]);
    free(argv);
    return 0;
}

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_patch(JNIEnv *env, jclass type, jstring oldpath_,
                                         jstring newpath_, jstring patch_) {
    char *argv[4];
    argv[0] = "bspatch";
    argv[1] = (*env)->GetStringUTFChars(env, oldpath_, 0);
    argv[2] = (*env)->GetStringUTFChars(env, newpath_, 0);
    argv[3] = (*env)->GetStringUTFChars(env, patch_, 0);
    bspatch_main(4, (char *)argv);
    (*env)->ReleaseStringUTFChars(env, oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch_, argv[3]);
    free(argv);
    return 0;

}


