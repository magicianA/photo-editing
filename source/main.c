#include<stdio.h>
#include<conio.h>
#include"svga.h"
#include"mouse.h"
#include"text.h"
#include"image.h"
void waitMouse(){
	Image image = {0};
	Mouse mouseOld, mouseNew;
	readBMP(&image,"temp\\timg.bmp",400,200,1);
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
			if(mouseDown(300,300,300 + 32,300 + 32)){
				putBMP(&image,mouseNew.x,mouseNew.y);
				break;
			}
			mouseOld = mouseNew;
        }
    }
}
void testHello(){
	//showGoodbyeImage();
	//TextGB64(100, 100, 50, WHITE, "欢迎使用图片管理系统",0);
	delay(1000);
}
int main()
{
	setSVGA();
	mouseReset();
	bar(0,0,SCR_WIDTH,SCR_HEIGHT,PINK);
	//testHello();
	waitMouse();
	getch();
    return 0;
}
