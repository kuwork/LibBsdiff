package com.kw.lib.bsdiff;

public class BsdiffUtils {
    static {
        System.loadLibrary("bsdiff");
    }

    //生成差分包
    public static native int diff(String oldpath, String newpath, String patch);

    //旧apk和差分包合并

    /**
     * native方法
     * 使用路径为oldApkPath的apk与路径为patchPath的补丁包，合成新的apk，并存储于newApkPath
     *
     * @param oldpath
     * @param newpath
     * @param patch
     * @return
     */
    public static native int patch(String oldpath, String newpath, String patch);
    public static native int bz2_command(String command);
}