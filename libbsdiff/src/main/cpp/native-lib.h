#include <jni.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "bzip2/bzlib_private.h"
#include "logutils.h"


int bsdiff_main(int argc, char *argv[]);

int bspatch_main(int argc, char *argv[]);

int bz2_main(int argc, Char *argv[]);

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_diff(JNIEnv *env, jclass type, jstring oldpath_,
                                        jstring newpath_, jstring patch_);

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_patch(JNIEnv *env, jclass type, jstring oldpath_,
                                         jstring newpath_, jstring patch_);

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_executeBZ2Command(JNIEnv *env, jclass type, jstring command_);


