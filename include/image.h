#ifndef IMAGE_H
#define IMAGE_H

#include<svga.h>
#include<string.h>
#include<math.h>
#include"debug.h"

typedef struct{
    byte r,g,b;
}RGB;
typedef struct{
    byte b,g,r;
}BGR;
typedef struct{
	double h,s,l;
}HSL;
typedef struct{
    int width;
    int height;
    int x,y;
    char cachePath[25];
}Image;

typedef unsigned int UINT16;
typedef unsigned long DWORD;
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

u32 RGB2u32(const RGB x);
u32 rgb2u32(byte r,byte g,byte b);
RGB getRGB(byte r,byte g,byte b);
HSL RGB2HSL(const RGB x);
RGB HSL2RGB(HSL hsl);
int readBMP(Image *image,const char *path,int x,int y,int flag);
int saveBMP(int x1,int y1,int x2,int y2,char* path);
void addBrightness(Image *image,double delta);
void addSaturation(Image *image,double delta);
int putImage(Image const *image,int x,int y);
int saveImageCache(Image const *image);
void showGoodbyeImage();
int convolute3(Image *image,double core[][3]);
u32 getPixelFromCache(FILE *fp,long x,long y,int height); 
void sharpen(Image *image,double strength);
void blur(Image *image);
void movingBlur(Image *image);
void unsharpen(Image *image);
void curve(Image *image);
int putUI(const char *path,int x,int y,u32 bgcolor);
void showGoodbyeImage();

#endif