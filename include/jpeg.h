#ifndef JPEG_H
#define JPEG_H

#define PI 3.1415926
#include"svga.h"
#include"image.h"

void saveJPEG(int x,int y);
double alpha(double x);
void dct(double res[][8],double src[][8]);
void quantization(double a[][8],int flag,int dest[][8]);

#endif