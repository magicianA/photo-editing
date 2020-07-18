#ifndef MOUSE_h
#define MOUSE_h

#include "svga.h"
#include<conio.h>

typedef struct
{
	int x;
	int y;
	int button;
} Mouse;

extern unsigned int mouseInit(void);

extern void mouseRange(int x1, int y1, int x2, int y2);

extern int mouseStatus(Mouse* mouse);

extern int mouseDown(int x1, int y1, int x2, int y2);

extern void mouseStoreBk(int x, int y);

extern void mousePutBk(int x, int y);

extern void mouseReset(void);

extern void mouseDraw(Mouse mouse);

extern int mouseUp(int x1, int y1, int x2, int y2);

extern int mouseOutUp(int x1, int y1, int x2, int y2);

#endif