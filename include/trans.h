#ifndef TRANSFORM_H
#define TRANSFORM_H

#include"svga.h"
#include"image.h"
#include"mouse.h"

void mirror(Image *image);
int cut(Image *image,int x1,int x2,int y1,int y2,u32 color);
void spin(Image *image,u32 cl);
int zoom(Image *image,double scaleX,double scaleY);
int drawLine(Image *image,int x1,int x2,int y1,int y2,u32 color);
int drawBarEmpty(Image *image,int x1,int x2,int y1,int y2,u32 color);
int drawBarFilled(Image *image,int x1,int x2,int y1,int y2,u32 color);
int drawTriangle(Image *image,int x1,int x2,int x3,int y1,int y2,int y3,u32 color);
void drawFree(Image *image,u32 color);
void colorBoard(int x,int y);
HSL colorBoardSide(int x,int y,int x1,int y1);

#endif