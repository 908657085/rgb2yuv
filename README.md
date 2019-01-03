# rgb2yuv
convert rgb bytes  to yuv bytes use google library libyuv

图片格式

RGB 格式

1. argb 每个像素占用 4byte 每项占用 8位 1个字节

   bitmap 转 argb byte[] 大小为 width*height*4

2. rgb_565 每个像素占用 2byte 总共16位 这16位中，高5位为R分量，中间6位为G分量，低5位为B分量

   bitmap 转 rgb_565 byte[] 大小为 width*height*2

YUV420格式

每4个像素为一组,生成4个单独的Y分量以及共用的一组U、V分量 每个8位

bitmap 转YUV120 格式 byte[] 大小为 width*height + width*height/2

各种YUV420 的区别在于 UV分量 排布顺序不同

3. NV21  YYYYYYYY VUVU  ====>YUV420SP

4. NV12  YYYYYYYY UVUV  ====>YUV420sp

5. I420  YYYYYYYY UU VV ====>YUV420P

6. yv12  YYYYYYYY VV UU ====>YUV420p


