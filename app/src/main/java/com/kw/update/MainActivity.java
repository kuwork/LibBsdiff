package com.kw.update;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import com.kw.lib.bsdiff.BsdiffUtils;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    //旧版本
    String old = getsdpath() + "com.ajb.anjubao.intelligent_1.3.2_38.apk";
    //新版本
    String newp = getsdpath() + "com.ajb.anjubao.intelligent_1.3.3_39.apk";
    //差分包
    String patch = getsdpath() + "com.ajb.anjubao.intelligent_38_39.patch";
    //旧版apk和差分包合并生成的新版apk
    String tmp = getsdpath() + "new.apk";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void click(View view) {
        switch (view.getId()) {
            case R.id.bt_diff:
                Log.d("Thread", "bt_diff Thread ID is " + Thread.currentThread().getId());
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        long s = System.currentTimeMillis();
                        Log.d("Thread", "Thread ID is " + Thread.currentThread().getId());
                        BsdiffUtils.diff(old, newp, patch);
                        long s1 = System.currentTimeMillis();
                        Log.d("bsdiff", "生成差分包成功，用时:" + (s1 - s) + "ms");
                    }
                }).start();

                break;
            case R.id.bt_patch:
                Log.d("Thread", "bt_patch Thread ID is " + Thread.currentThread().getId());
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        long s = System.currentTimeMillis();
                        Log.d("Thread", "Thread ID is " + Thread.currentThread().getId());
                        long s2 = System.currentTimeMillis();
                        BsdiffUtils.patch(old, tmp, patch);
                        long s3 = System.currentTimeMillis();
                        Log.d("bsdiff", "差分包合并成功，用时:" + (s3 - s2) + "ms");
                    }
                }).start();

                break;
            case R.id.bt_bz2:
                BsdiffUtils.bz2_command("bzip2  "+getsdpath()+"未命名.uml");
                break;
        }
    }

    private String getsdpath() {
        return Environment.getExternalStorageDirectory().getPath() + File.separator;
    }

}
