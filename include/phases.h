#ifndef PHASES_H
#define PHASES_H

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<io.h>
#include"svga.h"
#include"mouse.h"
#include"mirror.h"
#include"text.h"
#include"image.h"


#define ESC 0x011b
#define Tab 0x0f09
#define Enter 0x1c0d
#define Delete 0x530D
#define Backspace 0x0e08


void cutPhase(Image *image);
void testPhase();
void mainPhase();
void goodbyePhase();
void adjustPhase(Image *image);
void fliterPhase(Image *image);
void msgPhase(int x,int y,char *s);
int inputPhase(char* filename,int flag,int dx,int dy);
void savePhase(Image *image);
void openPhase(Image *image);
void zoomPhase(Image *image);
void newPhase(Image *image);
void colorPhase(u32 *pColor);

#endif