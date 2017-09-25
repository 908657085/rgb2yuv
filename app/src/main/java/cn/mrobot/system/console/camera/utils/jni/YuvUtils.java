package cn.mrobot.system.console.camera.utils.jni;

public class YuvUtils {

    static {
        System.loadLibrary("rgb2yuv");
    }

    private  byte[] mBgr;

    public  void rgbToNV21(byte[] rgb, int width, int height, byte[] yuv) {
        if (mBgr == null || mBgr.length < rgb.length) {
            mBgr = new byte[rgb.length];
        }

        rgbToBgrInternal(rgb, width, height, mBgr);
        bgrToNV21Internal(mBgr, width, height, yuv);
    }

    public  void rgbToNV12(byte[] rgb, int width, int height, byte[] yuv) {
        if (mBgr == null || mBgr.length < rgb.length) {
            mBgr = new byte[rgb.length];
        }

        rgbToBgrInternal(rgb, width, height, mBgr);
        bgrToNV12Internal(mBgr, width, height, yuv);
    }

    public  void rgbToI420(byte[] rgb, int width, int height, byte[] yuv) {
        if (mBgr == null || mBgr.length < rgb.length) {
            mBgr = new byte[rgb.length];
        }

        rgbToBgrInternal(rgb, width, height, mBgr);
        bgrToI420Internal(mBgr, width, height, yuv);
    }

    public  void rgbToYV12(byte[] rgb, int width, int height, byte[] yuv) {
        if (mBgr == null || mBgr.length < rgb.length) {
            mBgr = new byte[rgb.length];
        }

        rgbToBgrInternal(rgb, width, height, mBgr);
        bgrToYV12Internal(mBgr, width, height, yuv);
    }

    public  void rgb565ToI420(byte[] rgb, int width, int height, byte[] yuv) {
        rgb565ToI420Internal(rgb,width,height,yuv);
    }


    public  void rgb565ToArgb(byte[] rgb, int width, int height, byte[] argb) {
        rgb565ToArgbInternal(rgb,width,height,argb);
    }

    public void i420ToNV21(byte[] i420, int width, int height, byte[] nv21){
        I420ToNV21Internal(i420, width, height, nv21);
    }

    private native void rgbToBgrInternal(byte[] rgb, int width, int height, byte[] bgr);
    private native void rgb565ToI420Internal(byte[] rgb, int width, int height, byte[] yuv);
    private native void rgb565ToArgbInternal(byte[] rgb, int width, int height, byte[] argb);
    private native void bgrToNV21Internal(byte[] bgr, int width, int height, byte[] yuv);
    private native void bgrToNV12Internal(byte[] bgr, int width, int height, byte[] yuv);
    private native void bgrToI420Internal(byte[] bgr, int width, int height, byte[] yuv);
    private native void bgrToYV12Internal(byte[] bgr, int width, int height, byte[] yuv);
    private native void I420ToNV21Internal(byte[] i420, int width, int height, byte[] nv21);
}
