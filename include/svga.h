#ifndef SVGA_H
#define SVGA_H

#include<bios.h> 
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>


#define SCR_WIDTH 800
#define SCR_HEIGHT 600

#define BMP_WIDTH_MAX 780
#define BMP_WIDTH_MIN 30
#define BMP_HEIGTH_MAX 470
#define BMP_HEIGTH_MIN 30

#define __COLORS
#define WHITE 0xffffff
#define GRAY 0xa9b6c2
#define SILVER 0xe4e8eb	
#define BLUE 0x728fa8
#define DARK 0x7d7d7d
#define TIANYILAN 0x66ccff

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

typedef unsigned char byte;

void setSVGA(void);
u32 getPixel(int x, int y);
void selectPage(register u8 page);
void putPixel(int x, int y, u32 color);
void bar(int x1, int y1, int x2, int y2, u32 color);
void line(int x1, int y1, int x2, int y2, u32 color);

#endif