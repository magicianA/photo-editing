#include "image.h"
#define _sq(x) ((x) * (x))

/*********************************************
FUNCTION: red_fn 
DESCRIPTION: 七彩图片r坐标
INPUT: i j
RETURN: char
***********************************************/
char red_fn(long i, long j)
{
    return (char)(_sq(cos(atan2(j - 300, i - 400) / 2)) * 255);
}
/*********************************************
FUNCTION: green_fn 
DESCRIPTION: 七彩图片g坐标
INPUT: i j
RETURN: char
***********************************************/
char green_fn(long i, long j)
{
    return (char)(_sq(cos(atan2(j - 300, i - 400) / 2 - 2 * acos(-1) / 3)) * 255);
}
/*********************************************
FUNCTION: blue_fn 
DESCRIPTION: 七彩图片b坐标
INPUT: i j
RETURN: char
***********************************************/
char blue_fn(long i, long j)
{
    return (char)(_sq(cos(atan2(j - 300, i - 400) / 2 + 2 * acos(-1) / 3)) * 255);
}
/*********************************************
FUNCTION: showGoodbyeImage
DESCRIPTION: 展示七彩图片
INPUT: void
RETURN: void
***********************************************/
void showGoodbyeImage()
{
    int i, j;
    for (i = 0; i < SCR_WIDTH; i++)
    {
        for (j = 0; j < SCR_HEIGHT; j++)
        {
            putPixel(i, j, rgb2u32(red_fn(i, j), green_fn(i, j), blue_fn(i, j)));
        }
    }
}
/*********************************************
FUNCTION: image2ImageData
DESCRIPTION: 将Image结构体转换为ImageData结构体
INPUT: image
RETURN:  ImageData
***********************************************/
ImageData image2ImageData(Image *image){
    ImageData t;
    t.x = image->x;
    t.y = image->y;
    t.width = image->width;
    t.height = image->height;
    return t;
}
/*********************************************
FUNCTION: readBMP
DESCRIPTION: 读取BMP
INPUT: image path x y flag(布尔值，是否自适应)
RETURN:  int 1:成功读取 0:图片类型不符 -1 其他错误
***********************************************/
int readBMP(Image *image, const char *path, int x, int y, int flag)
{
    int i, j;
    BGR *buffer;
    char temp[25];
    u32 color24;
    u32 linebytes;
    FILE *fp = fopen(path, "rb");
    FILE *ft;
    BITMAPFILEHEADER bmphead;
    BITMAPINFOHEADER bmpinfo;

    strcpy(temp, path);
    strcpy(strstr(temp, ".bmp"), ".tmp");
    strcpy(strstr(temp, ".BMP"), ".tmp");
    if (fp)
    {
        fread(&bmphead, sizeof(bmphead), 1, fp);
        fread(&bmpinfo, sizeof(bmpinfo), 1, fp);
        if (bmphead.bfType != 0x4d42 || bmpinfo.biBitCount != 24u || bmpinfo.biCompression != 0ul || bmpinfo.biWidth > SCR_WIDTH ||
            bmpinfo.biHeight > SCR_HEIGHT)
        {
            fclose(fp);
            return 0;
        }
        if (flag)
        { //auto resolution fitting
            x = 432 - bmpinfo.biWidth / 2;
            y = 317 - bmpinfo.biHeight / 2;
        }
        linebytes = (3 * bmpinfo.biWidth) % 4;
        if (!linebytes)
            linebytes = 3 * bmpinfo.biWidth;
        else
            linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;

        if ((buffer = (BGR *)malloc(linebytes)) == 0)
        {
            fclose(fp);
            return -1;
        }

        fseek(fp, 54L, 0);
        for (i = bmpinfo.biHeight - 1; i > -1; i--)
        {
            fread(buffer, linebytes, 1, fp);
            for (j = 0; j < bmpinfo.biWidth; j++)
            {
                color24 = ((u32)buffer[j].r) << 16 | ((u32)buffer[j].g) << 8 | ((u32)buffer[j].b);
                putPixel(j + x, i + y, color24);
            }
        }
        free(buffer);
        if ((ft = fopen(temp, "wb")) == 0)
            return 0;

        image->height = bmpinfo.biHeight;
        image->width = bmpinfo.biWidth;
        image->x = x;
        image->y = y;
        strcpy(image->cachePath, temp);
        for (i = 0; i < image->width; i++)
        {
            for (j = 0; j < image->height; j++)
            {
                color24 = getPixel(x + i, y + j);
                fwrite(&color24, 4, 1, ft);
            }
        }
        fclose(fp);
        fclose(ft);
    }
    else
    {
        return -1;
    }
    return 1;
}
/*********************************************
FUNCTION: saveBMP
DESCRIPTION: 保存BMP
INPUT: x1 y1 x2 y2 path
RETURN: 一个布尔值 是否成功保存
***********************************************/
int saveBMP(int x1, int y1, int x2, int y2, char *path)
{
    int i, j;
    FILE *fp;
    BGR *buffer;
    u16 width = x2 - x1;
    u16 height = y2 - y1;
    u32 color24;
    u32 bmpbytes;
    u32 linebytes;
    BITMAPFILEHEADER bmphead;
    BITMAPINFOHEADER bmpinfo;

    linebytes = (3 * width) % 4;
    if (!linebytes)
    {
        linebytes = 3 * width;
    }
    else
    {
        linebytes = 3 * width + 4 - linebytes;
    }

    bmpbytes = linebytes * height + 54;
    bmphead.bfType = 0x4d42;
    bmphead.bfSize = bmpbytes;
    bmphead.bfReserved1 = 0;
    bmphead.bfReserved2 = 0;
    bmphead.bfOffBits = 0x36;
    bmpinfo.biSize = 0x28;
    bmpinfo.biWidth = width;
    bmpinfo.biHeight = height;
    bmpinfo.biPlanes = 1;
    bmpinfo.biBitCount = 0x18;
    bmpinfo.biCompression = 0;
    bmpinfo.biSizeImage = bmpbytes - 54;
    bmpinfo.biXPelsPerMeter = 0;
    bmpinfo.biYPelsPerMeter = 0;
    bmpinfo.biClrUsed = 0;
    bmpinfo.biClrImportant = 0;

    if ((buffer = (BGR *)malloc(3 * width)) == 0)
    {
        return 0;
    }
    if ((fp = fopen(path, "wb")) == NULL)
    {
        return 0;
    }

    fwrite(&bmphead, sizeof(BITMAPFILEHEADER), 1, fp);
    fwrite(&bmpinfo, sizeof(BITMAPINFOHEADER), 1, fp);

    fseek(fp, 54L, 0);
    for (i = height - 1; i > -1; i--)
    {
        for (j = width - 1; j > -1; j--)
        {
            color24 = getPixel(x1 + j, y1 + i);
            buffer[j].r = color24 >> 16 & 0xff;
            buffer[j].g = color24 >> 8 & 0xff;
            buffer[j].b = color24 & 0xff;
        }
        fwrite(buffer, linebytes, 1, fp);
    }

    free(buffer);
    fclose(fp);
    return 1;
}

/*********************************************
FUNCTION: saveImageCache
DESCRIPTION: 保存图片缓存
INPUT: image
RETURN: 一个布尔值 是否成功保存
***********************************************/
int saveImageCache(Image const *image)
{
    FILE *fp;
    int i, j;
    u32 color;
    if ((fp = fopen(image->cachePath, "wb")) == 0)
        return 0;
    for (i = 0; i < image->width; i++)
    {
        for (j = 0; j < image->height; j++)
        {
            color = getPixel(image->x + i, image->y + j);
            fwrite(&color, 4, 1, fp);
        }
    }
    fclose(fp);
    return 1;
}
/*********************************************
FUNCTION: putImage
DESCRIPTION: 从图片缓存中读取图片并打印到屏幕上
INPUT: image x y
RETURN: 一个布尔值 是否成功读取
***********************************************/
int putImage(Image const *image, int x, int y)
{
    FILE *fp;
    int i, j;
    u32 color;
    if ((fp = fopen(image->cachePath, "rb")) == 0)
        return 0;
    if(x == -1 && y == -1){
        x = image->x;
        y = image->y;
    }
    for (i = 0; i < image->width; i++)
    {
        for (j = 0; j < image->height; j++)
        {
            fread(&color, 4, 1, fp);
            putPixel(x + i, y + j, color);
        }
    }
    fclose(fp);
    return 1;
}
/*********************************************
FUNCTION: addBrightness
DESCRIPTION: 增加图片亮度
INPUT: image delta
RETURN: void
***********************************************/
void addBrightness(Image *image, double delta)
{
    int x, y, i, j;
    double r, g, b;
    u32 t;
    HSL hsl;
    x = image->x, y = image->y;
    for (i = 0; i < image->width; i++)
    {
        for (j = 0; j < image->height; j++)
        {
            t = getPixel(x + i, y + j);
            hsl = RGB2HSL(getRGB(t >> 16, (t >> 8) & 0xff, t & 0xff));
            hsl.l += delta;
            hsl.l = min(0.999, hsl.l);
            hsl.l = max(0, hsl.l);
            putPixel(x + i, y + j, RGB2u32(HSL2RGB(hsl)));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: addSaturation
DESCRIPTION: 增加图片饱和度
INPUT: image delta
RETURN: void
***********************************************/
void addSaturation(Image *image, double delta)
{
    int x, y, i, j;
    double r, g, b;
    u32 t;
    HSL hsl;
    x = image->x, y = image->y;
    for (i = 0; i < image->width; i++)
    {
        for (j = 0; j < image->height; j++)
        {
            t = getPixel(x + i, y + j);
            hsl = RGB2HSL(getRGB(t >> 16, (t >> 8) & 0xff, t & 0xff));
            hsl.s += delta;
            hsl.s = min(0.999, hsl.s);
            hsl.s = max(0, hsl.s);
            putPixel(x + i, y + j, RGB2u32(HSL2RGB(hsl)));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: RGB2u32
DESCRIPTION: 将RGB类型结构体转换为u32类型
INPUT: RGB
RETURN: u32
***********************************************/
u32 RGB2u32(const RGB x)
{
    return ((u32)x.r << 16) | ((u32)x.g << 8) | ((u32)x.b);
}
/*********************************************
FUNCTION: rgb2u32
DESCRIPTION: 将单独的rgb分量转换为u32类型
INPUT: r g b
RETURN: u32
***********************************************/
u32 rgb2u32(byte r, byte g, byte b)
{
    return ((u32)r << 16) | ((u32)g << 8) | ((u32)b);
}
/*********************************************
FUNCTION: getRGB
DESCRIPTION: 将单独的rgb分量转换为RGB结构体类型
INPUT: r g b
RETURN: RGB
***********************************************/
RGB getRGB(byte r, byte g, byte b)
{
    RGB t;
    t.r = r, t.b = b, t.g = g;
    return t;
}
/*********************************************
FUNCTION: RGB2HSL
DESCRIPTION: 将RGB坐标下的颜色转换为HSL坐标下的颜色
INPUT: RGB
RETURN: HSL
***********************************************/
HSL RGB2HSL(const RGB x)
{
    HSL t;
    double r = x.r / 256.0, g = x.g / 256.0, b = x.b / 256.0;
    double mx, mn;
    mx = max(max(r, g), b);
    mn = min(min(r, g), b);

    t.l = 0.5 * (mx + mn);

    if (fabs(mx - mn) <= 1e-6)
        t.h = 0;
    else if (fabs(mx - r) < 1e-6 && g >= b)
        t.h = 60.0 * (g - b) / (mx - mn);
    else if (fabs(mx - r) < 1e-6 && g < b)
        t.h = 60.0 * (g - b) / (mx - mn) + 360.0;
    else if (fabs(mx - g) < 1e-6)
        t.h = 60.0 * (b - r) / (mx - mn) + 120.0;
    else if (fabs(mx - b) < 1e-6)
        t.h = 60.0 * (r - g) / (mx - mn) + 240.0;

    if (fabs(t.l) <= 1e-6 || fabs(mx - mn) <= 1e-6)
        t.s = 0;
    else if (t.l > 0 && t.l <= 0.5)
        t.s = (mx - mn) / (2 * t.l);
    else if (t.l > 0.5)
        t.s = (mx - mn) / (2 - 2 * t.l);

    return t;
}
/*********************************************
FUNCTION: HSL2RGB
DESCRIPTION: 将HSL坐标下的颜色转换为BGB坐标下的颜色
INPUT: HSL
RETURN: RGB
***********************************************/
RGB HSL2RGB(HSL hsl)
{
    RGB res;
    double r1, g1, b1;
    double c, x, h0, m;
    double h = hsl.h, s = hsl.s, l = hsl.l;
    c = (1 - fabs(2 * l - 1)) * s;
    h0 = h / 60;
    x = c * (1 - fabs((h0 - ((int)(h0 / 2)) * 2) - 1));
    switch ((int)(h0))
    {
    case 0:
        r1 = c;
        g1 = x;
        b1 = 0;
        break;
    case 1:
        r1 = x;
        g1 = c;
        b1 = 0;
        break;
    case 2:
        r1 = 0;
        g1 = c;
        b1 = x;
        break;
    case 3:
        r1 = 0;
        g1 = x;
        b1 = c;
        break;
    case 4:
        r1 = x;
        g1 = 0;
        b1 = c;
        break;
    case 5:
        r1 = c;
        g1 = 0;
        b1 = x;
        break;
    }
    m = l - c / 2;

    res.r = (r1 + m) * 256;
    res.g = (g1 + m) * 256;
    res.b = (b1 + m) * 256;
    if (fabs((r1 + m) - 1) < 1e-6)
        res.r = 255;
    if (fabs((g1 + m) - 1) < 1e-6)
        res.g = 255;
    if (fabs((b1 + m) - 1) < 1e-6)
        res.b = 255;
    return res;
}
/*********************************************
FUNCTION: getPixelFromCache
DESCRIPTION: 从缓存中读取颜色
INPUT: fp x y height
RETURN: u32
***********************************************/
u32 getPixelFromCache(FILE *fp, long x, long y, int height)
{
    u32 color;
    fseek(fp, (x * height + y) * 4, SEEK_SET);
    fread(&color, 4, 1, fp);
    return color;
}
/*********************************************
FUNCTION: BMPcache
DESCRIPTION: 将bmp读取在缓存中
INPUT: image path
RETURN: 布尔值，是否成功
***********************************************/
int BMPcache(Image *image,char *path)
{
    int i, j;
    BGR *buffer;
    char temp[25];
    u32 color24;
    u32 linebytes;
    FILE *fp = fopen(path, "rb");
    FILE *ft;
    BITMAPFILEHEADER bmphead;
    BITMAPINFOHEADER bmpinfo;

    strcpy(temp, path);
    strcpy(strstr(temp, ".bmp"), ".tmp");
    strcpy(strstr(temp, ".BMP"), ".tmp");
    if (fp)
    {
        fread(&bmphead, sizeof(bmphead), 1, fp);
        fread(&bmpinfo, sizeof(bmpinfo), 1, fp);
        if (bmphead.bfType != 0x4d42 || bmpinfo.biBitCount != 24u || bmpinfo.biCompression != 0ul || bmpinfo.biWidth > SCR_WIDTH ||
            bmpinfo.biHeight > SCR_HEIGHT)
        {
            fclose(fp);
            return 0;
        }
        linebytes = (3 * bmpinfo.biWidth) % 4;
        if (!linebytes)
            linebytes = 3 * bmpinfo.biWidth;
        else
            linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;
        fseek(fp, 54L, 0);
        if ((ft = fopen(temp, "wb+")) == 0)
            return 0;
        fseek(ft,0,SEEK_SET);
        for(i = 0;i < bmpinfo.biWidth;i++){
            for(j = 0;j < bmpinfo.biHeight;j++){
                fwrite(BLACK, 4, 1, ft);
            }
        }
        for (i = bmpinfo.biHeight - 1; i >= 0; i--)
        {
            fread(buffer, linebytes, 1, fp);
            for (j = 0; j < bmpinfo.biWidth; j++)
            {
                color24 = ((u32)buffer[j].r) << 16 | ((u32)buffer[j].g) << 8 | ((u32)buffer[j].b);
                fseek(ft,(j * bmpinfo.biHeight + i)* 4,SEEK_SET);
                fwrite(&color24,4,1,ft);
            }
        }
        free(buffer);
        image->width = bmpinfo.biWidth;
        image->height = bmpinfo.biHeight;
        strcpy(image->cachePath,temp);
        //fclose(fp);
        //fclose(ft);
    }
    else
    {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    fclose(ft);
    return 1;
}
/*********************************************
FUNCTION: convolute3
DESCRIPTION: 图片卷积(3*3卷积核)
INPUT: image core
RETURN: 一个布尔值，卷积是否成功
***********************************************/
int convolute3(Image *image, double core[][3])
{
    FILE *fp;
    int i, j;
    int p1, p2;
    int x, y, width, height;
    u32 pix[3][3];
    RGB res;
    double r = 0, g = 0, b = 0;
    x = image->x, y = image->y, width = image->width, height = image->height;
    if (!(image->cachePath))
        return 0;
    if ((fp = fopen(image->cachePath, "rb")) == 0)
        return 0;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            r = g = b = 0;
            for (p1 = -1; p1 <= 1; p1++)
                for (p2 = -1; p2 <= 1; p2++)
                    pix[1 + p1][1 + p2] = getPixelFromCache(fp, (i + width + p1) % width, (j + height + p2) % height, height);
            for (p1 = 0; p1 <= 2; p1++)
                for (p2 = 0; p2 <= 2; p2++)
                {
                    r += (pix[p1][p2] >> 16) / 256.0 * core[p1][p2];
                    g += ((pix[p1][p2] >> 8) & 0xff) / 256.0 * core[p1][p2];
                    b += (pix[p1][p2] & 0xff) / 256.0 * core[p1][p2];
                }
            r = min(r, 1);
            g = min(g, 1);
            b = min(b, 1);
            r = max(r, 0);
            g = max(g, 0);
            b = max(b, 0);
            res.r = r * 256;
            res.g = g * 256;
            res.b = b * 256;
            if (fabs(r - 1) < 1e-6)
                res.r = 255;
            if (fabs(g - 1) < 1e-6)
                res.g = 255;
            if (fabs(b - 1) < 1e-6)
                res.b = 255;
            putPixel(x + i, y + j, RGB2u32(res));
        }
    }
    fclose(fp);
    return 1;
}
/*********************************************
FUNCTION: convolute5
DESCRIPTION: 图片卷积(5*5卷积核)
INPUT: image core
RETURN: 一个布尔值，卷积是否成功
***********************************************/
int convolute5(Image *image, double core[][5])
{
    FILE *fp;
    int i, j;
    int p1, p2;
    int x, y, width, height;
    u32 pix[5][5];
    RGB res;
    double r = 0, g = 0, b = 0;
    x = image->x, y = image->y, width = image->width, height = image->height;
    if ((fp = fopen(image->cachePath, "rb")) == 0)
        return 0;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            r = g = b = 0;
            for (p1 = -2; p1 <= 2; p1++)
                for (p2 = -2; p2 <= 2; p2++)
                    pix[2 + p1][2 + p2] = getPixelFromCache(fp, (i + width + p1) % width, (j + height + p2) % height, height);
            for (p1 = 0; p1 < 5; p1++)
                for (p2 = 0; p2 < 5; p2++)
                {
                    r += (pix[p1][p2] >> 16) / 256.0 * core[p1][p2];
                    g += ((pix[p1][p2] >> 8) & 0xff) / 256.0 * core[p1][p2];
                    b += (pix[p1][p2] & 0xff) / 256.0 * core[p1][p2];
                }
            r = min(r, 1);
            g = min(g, 1);
            b = min(b, 1);
            r = max(r, 0);
            g = max(g, 0);
            b = max(b, 0);
            res.r = r * 256;
            res.g = g * 256;
            res.b = b * 256;
            if (fabs(r - 1) < 1e-6)
                res.r = 255;
            if (fabs(g - 1) < 1e-6)
                res.g = 255;
            if (fabs(b - 1) < 1e-6)
                res.b = 255;
            putPixel(x + i, y + j, RGB2u32(res));
        }
    }
    fclose(fp);
    return 1;
}
/*********************************************
FUNCTION: sharpen
DESCRIPTION: 图片锐化
INPUT: image
RETURN: void
***********************************************/
void sharpen(Image *image)
{
    double core[3][3] = {0};
    core[0][1] = core[1][0] = core[1][2] = core[2][1] = -1;
    core[1][1] = 5;
    convolute3(image, core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: blur
DESCRIPTION: 图片模糊
INPUT: image
RETURN: void
***********************************************/
void blur(Image *image)
{
    double core[3][3] = {1 / 16.0, 2 / 16.0, 1 / 16.0, 2 / 16.0, 4/ 16.0, 2 / 16.0, 1 / 16.0, 2 / 16.0, 1 / 16.0};
    convolute3(image, core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: movingBlur
DESCRIPTION: 图片运动模糊
INPUT: image
RETURN: void
***********************************************/
void movingBlur(Image *image)
{
    double core[5][5] = {{0.2, 0, 0, 0, 0}, {0, 0.2, 0, 0, 0}, {0, 0, 0.2, 0, 0}, {0, 0, 0, 0.2, 0}, {0, 0, 0, 0, 0.2}};
    convolute5(image, core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: unsharpen
DESCRIPTION: 图片去模糊
INPUT: image
RETURN: void
***********************************************/
void unsharpen(Image *image)
{
    double core[5][5] = {{-1 / 256.0, -4 / 256.0, -6 / 256.0, -4 / 256.0, -1 / 256.0}, {-4 / 256.0, -16 / 256.0, -24 / 256.0, -16 / 256.0, -4 / 256.0}, {-6 / 256.0, -24 / 256.0, 476 / 256.0, -24 / 256.0, -6 / 256.0}, {-4 / 256.0, -16 / 256.0, -24 / 256.0, -16 / 256.0, -4 / 256.0}, {-1 / 256.0, -4 / 256.0, -6 / 256.0, -4 / 256.0, -1 / 256.0}};
    convolute5(image, core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: laplace
DESCRIPTION: 边缘检测(laplace 算子)
INPUT: image
RETURN: void
***********************************************/
void laplace(Image *image)
{
    double core[3][3] = {-1,-1,-1,-1,8,-1,-1,-1,-1};
    convolute3(image,core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: curve
DESCRIPTION: 图片浮雕
INPUT: image
RETURN: void
***********************************************/
void curve(Image *image)
{
    double core[3][3] = {{-6, -3, 0}, {-3, 1, 3}, {0, 3, 6}};
    convolute3(image, core);
    saveImageCache(image);
}
/*********************************************
FUNCTION: putUI
DESCRIPTION: 将UI图片显示到屏幕上
INPUT: path x y bgcolor(=-1表示背景透明)
RETURN: void
***********************************************/
int putUI(const char *path, int x, int y, u32 bgcolor)
{
    int i, j;
    BGR *buffer;
    u32 color24;
    u32 linebytes;
    FILE *fp = fopen(path, "rb");
    BITMAPFILEHEADER bmphead;
    BITMAPINFOHEADER bmpinfo;

    if (fp)
    {
        fread(&bmphead, sizeof(bmphead), 1, fp);
        fread(&bmpinfo, sizeof(bmpinfo), 1, fp);
        if (bmphead.bfType != 0x4d42 || bmpinfo.biBitCount != 24u || bmpinfo.biCompression != 0ul || bmpinfo.biWidth > SCR_WIDTH ||
            bmpinfo.biHeight > SCR_HEIGHT)
        {
            fclose(fp);
            return 0;
        }

        linebytes = (3 * bmpinfo.biWidth) % 4;
        if (!linebytes)
            linebytes = 3 * bmpinfo.biWidth;
        else
            linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;

        if ((buffer = (BGR *)malloc(linebytes)) == 0)
        {
            fclose(fp);
            return -1;
        }

        fseek(fp, 54L, 0);
        for (i = bmpinfo.biHeight - 1; i > -1; i--)
        {
            fread(buffer, linebytes, 1, fp);
            for (j = 0; j < bmpinfo.biWidth; j++)
            {
                color24 = ((u32)buffer[j].r) << 16 | ((u32)buffer[j].g) << 8 | ((u32)buffer[j].b);
                if (color24 != WHITE)
                    putPixel(j + x, i + y, color24);
                else if (bgcolor != -1)
                    putPixel(j + x, i + y, bgcolor);
            }
        }
        free(buffer);
        fclose(fp);
    }
    else
    {
        return -1;
    }
    return 1;
}
/*********************************************
FUNCTION: gray
DESCRIPTION: 灰度
INPUT: image
RETURN: void
***********************************************/
void gray(Image *image)
{
    int i, j, t;
    u32 color;
    int x, y, width, height;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            t = (30 * res.r + 59 * res.g + 11 * res.b) / 100;
            res.r = t;
            res.g = t;
            res.b = t;
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: filtMatrix
DESCRIPTION: 颜色(列向量)左乘一矩阵
INPUT: image a
RETURN: void
***********************************************/
void filtMatrix(Image *image, double a[][3])
{
    int i, j;
    int x, y, width, height;
    int r, g, b, r1, g1, b1;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            r = res.r;
            g = res.g;
            b = res.b;
            r1 = a[0][0] * r + a[0][1] * g + a[0][2] * b;
            g1 = a[1][0] * r + a[1][1] * g + a[1][2] * b;
            b1 = a[2][0] * r + a[2][1] * g + a[2][2] * b;
            res.r = min(r1, 255);
            res.g = min(g1, 255);
            res.b = min(b1, 255);
            res.r = max(res.r, 0);
            res.g = max(res.g, 0);
            res.b = max(res.b, 0);
            putPixel(i, j, RGB2u32(res));
        }
    }
}
/*********************************************
FUNCTION: old
DESCRIPTION: 复古滤镜
INPUT: image
RETURN: void
***********************************************/
void old(Image *image)
{
    double b[][3] = {{0.393, 0.769, 0.189}, {0.349, 0.686, 0.168}, {0.272, 0.534, 0.131}};
    filtMatrix(image, b);
    saveImageCache(image);
}
/*********************************************
FUNCTION: frozen
DESCRIPTION: 冰冻滤镜
INPUT: image
RETURN: void
***********************************************/
void frozen(Image *image){
    double b[][3]={{1.5,-1.5,-1.5},{-1.5,1.5,-1.5},{-1.5,-1.5,1.5}};
    filtMatrix(image,b);
    saveImageCache(image);
}
/*********************************************
FUNCTION: reverse
DESCRIPTION: 反色滤镜
INPUT: image
RETURN: void
***********************************************/
void reverse(Image *image)
{
    int i, j;
    int x, y;
    int width, height;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            res.r = 255 - res.r;
            res.g = 255 - res.g;
            res.b = 255 - res.b;
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: closeImage
DESCRIPTION: 关闭图片
INPUT: image
RETURN: void
***********************************************/
void closeImage(Image *image)
{
    int i, j;
    int x, y;
    int width, height;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            putPixel(x + i, y + j, WHITE);
        }
    }
    remove(image->cachePath);
    image->x = image->y = image->width = image->height = 0;
    strcpy(image->cachePath, "");
}
/*********************************************
FUNCTION: melt
DESCRIPTION: 熔融滤镜
INPUT: image
RETURN: void
***********************************************/
void melt(Image *image)
{
    int i, j;
    int x, y;
    int width, height;
    int r, g, b;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            r = res.r * 128 / (res.g + res.b + 1);
            g = res.g * 128 / (res.b + res.r + 1);
            b = res.b * 128 / (res.r + res.g + 1);
            res.r = r;
            res.g = g;
            res.b = b;
            res.r = min(r, 255);
            res.g = min(g, 255);
            res.b = min(b, 255);
            res.r = max(res.r, 0);
            res.g = max(res.g, 0);
            res.b = max(res.b, 0);
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: cartoon
DESCRIPTION: 连环画滤镜
INPUT: image
RETURN: void
***********************************************/
void cartoon(Image *image)
{
    int i, j;
    int x, y; 
    int width, height;
    double r, g, b;
    double r1, g1, b1;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            r = res.r;
            g = res.g;
            b = res.b;
            r1 = abs(g - b + g + r) * r / 256;
            g1 = abs(b - g + b + r) * r / 256;
            b1 = abs(b - g + b + r) * g / 256;
            res.r = min(r1, 255);
            res.g = min(g1, 255);
            res.b = min(b1, 255);
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: extreme
DESCRIPTION: 黑白滤镜
INPUT: image
RETURN: void
***********************************************/
void extreme(Image *image)
{
    int i, j;
    int x, y;
    int width, height;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            if (res.r + res.g + res.b >= 300)
            {
                res.r = 255;
                res.g = 255;
                res.b = 255;
            }
            else
            {
                res.r = 0;
                res.g = 0;
                res.b = 0;
            }
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: singleRed
DESCRIPTION: 猩红滤镜
INPUT: image
RETURN: void
***********************************************/
void singleRed(Image *image)
{
    int i, j;
    int x, y, width, height;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            res.g = 0;
            res.b = 0;
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: singleGreen
DESCRIPTION: 翠绿滤镜
INPUT: image
RETURN: void
***********************************************/
void singleGreen(Image *image)
{
    int i, j;
    int x, y;
    int width, height;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            res.r = 0;
            res.b = 0;
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: singleBlue
DESCRIPTION: 蔚蓝滤镜
INPUT: image
RETURN: void
***********************************************/
void singleBlue(Image *image)
{
    int i, j;
    int x, y, width, height;
    u32 color;
    RGB res;
    x = image->x, y = image->y, width = image->width, height = image->height;
    for (i = x; i < x + width; i++)
    {
        for (j = y; j < y + height; j++)
        {
            color = getPixel(i, j);
            res = getRGB(color >> 16, (color >> 8) & 0xff, color & 0xff);
            res.r = 0;
            res.g = 0;
            putPixel(i, j, RGB2u32(res));
        }
    }
    saveImageCache(image);
}
/*********************************************
FUNCTION: blend
DESCRIPTION: 将图片与某种颜色按一定比例混合
INPUT: image
RETURN: void
***********************************************/
void blend(int x1,int y1,int x2,int y2,u32 color2,double alpha)
{
    int i,j;
    int width,height;
    u32 color1;
    RGB res,rgb1,rgb2;
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;
    for(i = 0;i < width;i++){
        for(j = 0;j < height;j++){
            color1 = getPixel(x1 + i,y1 + j);
            rgb1 = getRGB(color1 >> 16, (color1 >> 8) & 0xff, color1 & 0xff);
            rgb2 = getRGB(color2 >> 16, (color2 >> 8) & 0xff, color2 & 0xff);
            res.r = alpha * rgb1.r + (1 - alpha) * rgb2.r;
            res.g = alpha * rgb1.g + (1 - alpha) * rgb2.g;
            res.b = alpha * rgb1.b + (1 - alpha) * rgb2.b;
            res.r = min(res.r, 255);
            res.g = min(res.g, 255);
            res.b = min(res.b, 255);
            putPixel(x1 + i,y1 + j,RGB2u32(res));
        }   
    }
}
/*********************************************
FUNCTION: girl
DESCRIPTION: 少女滤镜
INPUT: image
RETURN: void
***********************************************/
void girl(Image *image)
{
    int x1,y1;
    int x2,y2;
    x1 = image->x;
    y1 = image->y;
    x2 = image->x + image->width - 1;
    y2 = image->y + image->height - 1;
    blend(x1,y1,x2,y2,PINK,0.7);
    saveImageCache(image);
}
/*********************************************
FUNCTION: glass
DESCRIPTION: 毛玻璃滤镜
INPUT: image
RETURN: void
***********************************************/
void glass(Image *image)
{
    int i,j;
    int x,y,width,height;
    int r;
    u32 color;
    int ax[]={-1,0,1,-1,1,-1,0,1};
    int ay[]={-1,-1,-1,0,0,1,1,1};
    FILE *fp;
    fp = fopen(image ->cachePath,"wb");
    x = image->x, y = image->y, width = image->width, height = image->height;
    for(i = x;i < x + width;i++){
        for(j = y;j < y + height;j++){
            r = rand() % 8;
            if(i > x&&i < x + width - 1&&j > y&&j < y + height - 1){
                color = getPixel(i + ax[r],j + ay[r]);
                fwrite(&color, 4, 1, fp);
            }
            else{
                color = getPixel(i,j);
                fwrite(&color, 4, 1, fp);
            }
        }
    }
    fclose(fp);
    putImage(image, x, y);
    saveImageCache(image);
} 
/*********************************************
FUNCTION: fantasy
DESCRIPTION: 幻想滤镜
INPUT: image
RETURN: void
***********************************************/
void fantasy(Image *image)
{
    int x1,y1;
    int x2,y2;
    x1 = image->x;
    y1 = image->y;
    x2 = image->x + image->width - 1;
    y2 = image->y + image->height - 1;
    blend(x1,y1,x2,y2,PURPLE,0.4);
    saveImageCache(image);
}
