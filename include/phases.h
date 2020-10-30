#ifndef PHASES_H
#define PHASES_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include "svga.h"
#include "mouse.h"
#include "trans.h"
#include "text.h"
#include "image.h"
#include "jpeg.h"
#include "coll.h"

#define ESC 0x011b
#define Tab 0x0f09
#define Enter 0x1c0d
#define Delete 0x530D
#define Backspace 0x0e08

void cutPhase(Image *image,Stack *stack);
void testPhase();
void mainPhase();
void goodbyePhase();
void adjustPhase(Image *image,Stack *stack);
void fliterPhase(Image *image,Stack *stack);
void msgPhase(int x, int y, char *s);
int inputPhase(char *filename, int flag, int dx, int dy);
void savePhase(Image *image);
void openPhase(Image *image);
void zoomPhase(Image *image,Stack *stack);
void newPhase(Image *image);
u32 colorPhase();
void drawFreePhase(Image *image, u32 color,Stack *stack);
void welcomePhase();
void copyleftPhase();
void linePhase(Image *image, u32 color,Stack *stack);
void emptyBarPhase(Image *image, u32 color,Stack *stack);
void filledBarPhase(Image *image, u32 color,Stack *stack);
void trianglePhase(Image *image, u32 color,Stack *stack);

#endif