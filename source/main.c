#include<stdio.h>
#include<conio.h>
#include"svga.h"
#include"mouse.h"
#include"text.h"
#include"image.h"
void waitMouse(){
	Image image = {0};
	Mouse mouseOld, mouseNew;
	readBMP(&image,"temp\\timg.bmp",0,0,1);
	mouseStatus(&mouseOld);
	mouseStoreBk(mouseOld.x, mouseOld.y);
    while(1){
		mouseStatus(&mouseNew);
		if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
			continue;
		else{
			mousePutBk(mouseOld.x, mouseOld.y);
			mouseStoreBk(mouseNew.x, mouseNew.y);
			mouseDraw(mouseNew);
			if(mouseNew.button == 1){
				putBMP(&image,mouseNew.x,mouseNew.y);
				break;
			}
			mouseOld = mouseNew;
        }
    }
}
void testGoodbye(){
	showGoodbyeImage();
	TextGB64(100, 100, 50, WHITE, "祝你身体健康，再见",5);
	delay(1000);
}
int main()
{
    setSVGA();
    bar(0,0,SCR_WIDTH,SCR_HEIGHT,TIANYILAN);
    line(0,SCR_HEIGHT / 2,SCR_WIDTH,SCR_HEIGHT,WHITE);
	TextGB64(400, 100, 50, WHITE, "测试",0); //encoding : GB2312
	mouseReset();
	waitMouse();
	getch();
	testGoodbye();
    return 0;
}
