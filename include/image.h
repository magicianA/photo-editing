#ifndef IMAGE_H
#define IMAGE_H

#include<svga.h>
#include<string.h>
#include<math.h>

typedef struct{
    byte r,g,b;
}RGB;
typedef struct{
    byte b,g,r;
}BGR;
typedef struct{
    int width;
    int height;
    int x,y;
    char cachePath[25];
}Image;

typedef unsigned int UINT16;
typedef int DWORD;
typedef unsigned int WORD;
typedef long LONG;

typedef struct
{
	UINT16 bfType;
	DWORD bfSize;
	UINT16 bfReserved1;
	UINT16 bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER;

u32 RGB2u32(RGB x);
u32 rgb2u32(byte r,byte g,byte b);
RGB getRGB(byte r,byte g,byte b);
int readBMP(Image *image,const char *path,int x,int y,int flag);
int putBMP(Image const *const image,int x,int y);
void showGoodbyeImage();
void putImage(Image *image,int x,int y);
#endif