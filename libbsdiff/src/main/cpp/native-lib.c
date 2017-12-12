#include "native-lib.h"


JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_diff(JNIEnv *env, jclass type, jstring oldpath_,
                                        jstring newpath_, jstring patch_) {
    char **argv;
    argv = (char **) malloc(4 * sizeof(char *));
    argv[0] = "bsdiff";
    argv[1] = (char *) (*env)->GetStringUTFChars(env, oldpath_, 0);
    argv[2] = (char *) (*env)->GetStringUTFChars(env, newpath_, 0);
    argv[3] = (char *) (*env)->GetStringUTFChars(env, patch_, 0);
    int ret = bsdiff_main(4, argv);
    __android_log_print(ANDROID_LOG_INFO,"bz2_command", "ret = %d", ret);
    (*env)->ReleaseStringUTFChars(env, oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch_, argv[3]);
    return ret;
}


JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_patch(JNIEnv *env, jclass type, jstring oldpath_,
                                         jstring newpath_, jstring patch_) {
    char *argv[4];
    argv[0] = "bspatch";
    argv[1] = (char *) (*env)->GetStringUTFChars(env, oldpath_, 0);
    argv[2] = (char *) (*env)->GetStringUTFChars(env, newpath_, 0);
    argv[3] = (char *) (*env)->GetStringUTFChars(env, patch_, 0);
    int ret = bspatch_main(4, argv);
    __android_log_print(ANDROID_LOG_INFO,"bz2_command", "ret = %d", ret);
    (*env)->ReleaseStringUTFChars(env, oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch_, argv[3]);
    return ret;

}

int strsplit(const char *str, char *parts[], const char *delimiter) {
    char *pch;
    int i = 0;
    char *copy = NULL, *tmp = NULL;

    copy = strdup(str);
    if (!copy)
        goto bad;

    pch = strtok(copy, delimiter);

    tmp = strdup(pch);
    if (!tmp)
        goto bad;

    parts[i++] = tmp;

    while (pch) {
        pch = strtok(NULL, delimiter);
        if (NULL == pch) break;

        tmp = strdup(pch);
        if (!tmp)
            goto bad;

        parts[i++] = tmp;
    }

    free(copy);
    return i;

    bad:
    free(copy);
    for (int j = 0; j < i; j++)
        free(parts[j]);
    return -1;
}

JNIEXPORT jint JNICALL
Java_com_kw_lib_bsdiff_BsdiffUtils_executeBZ2Command(JNIEnv *env, jclass type, jstring command_) {
    const char *command = (*env)->GetStringUTFChars(env, command_, 0);
    char *parts[8];
    size_t size = strsplit(command, parts, " ");
    LOGD(TAG,"command = %s size = %zu", command,size);
    char *argv[size];
    for (int i = 0; i < size; ++i) {
        argv[i] = parts[i];
    }
    int ret = bz2_main(size, argv);
    __android_log_print(ANDROID_LOG_INFO,"bz2_command", "ret = %d", ret);
    // TODO
    (*env)->ReleaseStringUTFChars(env, command_, command);
    return ret;
}
