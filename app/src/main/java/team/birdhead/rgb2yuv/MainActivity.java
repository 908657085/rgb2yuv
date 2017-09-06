package team.birdhead.rgb2yuv;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;

import cn.mrobot.system.console.camera.utils.jni.YuvUtils;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getName();
    private static final String SYSTEM_ROOT_DIR =
        Environment.getExternalStorageDirectory().getPath() + File.separator + "platform";
    public static final String DEFAULT_PIC_DIR =
        SYSTEM_ROOT_DIR + File.separator + "camera" + File.separator + "pic" + File.separator;
    public static final String DEFAULT_VID_DIR =
        SYSTEM_ROOT_DIR + File.separator + "camera" + File.separator + "vid" + File.separator;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        Log.d(TAG, "onCreate: ");
        new Thread() {
            @Override
            public void run() {
                YuvUtils converter = new YuvUtils();

                Bitmap bitmap = BitmapFactory.decodeResource(MainActivity.this.getResources(), R.drawable.test);

                int bytes = bitmap.getByteCount();

                ByteBuffer buf = ByteBuffer.allocate(bytes);
                bitmap.copyPixelsToBuffer(buf);

                byte[] rgb = buf.array();

                Log.d(TAG, "bitmap:  width " + bitmap.getWidth() + "height " + bitmap.getHeight());
                //                byte[] rgb = baos.toByteArray();
                Log.d(TAG, "rgb.length : " + rgb.length);
                Log.d(TAG, "rgb need length : " + (bitmap.getWidth() * bitmap.getHeight() * 4));

                //            final byte[] rgb = new byte[size.getWidth() * size.getHeight() * 4];
                byte[] yuv = new byte[bitmap.getWidth() * bitmap.getHeight() * 3 / 2];
                converter.rgbToNV21(rgb, bitmap.getWidth(), bitmap.getHeight(), yuv);
                saveYuvFrame(yuv,"test_NV21.yuv");

                converter.rgbToNV12(rgb, bitmap.getWidth(), bitmap.getHeight(), yuv);
                saveYuvFrame(yuv,"test_NV12.yuv");

                converter.rgbToI420(rgb, bitmap.getWidth(), bitmap.getHeight(), yuv);
                saveYuvFrame(yuv,"test_I420.yuv");

                converter.rgbToYV12(rgb, bitmap.getWidth(), bitmap.getHeight(), yuv);
                saveYuvFrame(yuv,"test_YV12.yuv");
                Log.d(TAG, "run: finish");
            }
        }.start();
    }

    private void saveYuvFrame(byte[] data,String name) {
        File file = new File(DEFAULT_PIC_DIR + name);
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        FileOutputStream output = null;
        ByteArrayOutputStream baos = null;
        try {
            output = new FileOutputStream(file);
            output.write(data);
            output.flush();
            Log.d(TAG, "capture  still yuv success");
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        } finally {
            if (output != null) {
                try {
                    output.close();
                } catch (IOException e) {
                    Log.e(TAG, e.getMessage());
                }
            }
            if (baos != null) {
                try {
                    baos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}
