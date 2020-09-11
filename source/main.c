#include<stdio.h>
#include<conio.h>
#include"svga.h"
#include"mouse.h"
#include"mirror.h"
#include"text.h"
#include"image.h"
void testPhase(){
	Image image = {0};
	Mouse mouseOld, mouseNew;
	readBMP(&image,"temp\\grass.bmp",400,200,1);
	mouseStatus(&mouseOld);
	mouseStoreBk(mouseOld.x, mouseOld.y);
	bar(300,300,300 + 32,300 + 32,TIANYILAN);
    while(1){
		mouseStatus(&mouseNew);
		if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
			continue;
		else{
			mousePutBk(mouseOld.x, mouseOld.y);
			mouseStoreBk(mouseNew.x, mouseNew.y);
			mouseDraw(mouseNew);
			if(mouseOld.button == 1){
				putBMP(&image,mouseNew.x,mouseNew.y);
				pictureMirror(&image);
				break;
			}
			mouseOld = mouseNew;
        }
    }
}
int main()
{
	setSVGA();
	mouseReset();
	bar(0,0,SCR_WIDTH,SCR_HEIGHT,TIANYILAN);
	showGoodbyeImage();
	//TextGB32(0,0,100,WHITE,"ÄãÕæ°ô");
	//testPhase();
	getch();
    return 0;
}
