#ifndef MIRROR_H
#define MIRROR_H

#include"svga.h"
#include"image.h"
void pictureMirror(Image *image);
int cut(Image *image,int x1,int x2,int y1,int y2,u32 color);
void spin(Image *image,u32 cl);

#endif