#ifndef PHASES_H
#define PHASES_H

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include"svga.h"
#include"mouse.h"
#include"mirror.h"
#include"text.h"
#include"image.h"

void cutPhase(Image *image);
void testPhase();
void mainPhase();
void adjustPhase(Image *image);
int msgPhase(int x,int y,char *s);

#endif