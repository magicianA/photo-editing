#include<stdio.h>
#include<conio.h>
#include"svga.h"
#include"mouse.h"
#include"text.h"

void waitMouse(){
	Mouse mouseOld, mouseNew;
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
    line(0,SCR_HEIGHT / 2,SCR_WIDTH,SCR_HEIGHT,WHITE);
	TextGB64(200+30, 100, 50, WHITE, "≤‚ ‘",0); //encoding : GB2312
	getch();
	waitMouse();
    return 0;
}
