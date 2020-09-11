#include"phases.h"

void cutPhase(Image *image){
	int flag = 0;
	Mouse mouseOld,mouseNew,mouse1,mouse2;
	mouseStatus(&mouseOld);
	mouseStoreBk(mouseOld.x,mouseOld.y);
	while(1){
		mouseStatus(&mouseNew);
		if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
			continue;
		else{
			mousePutBk(mouseOld.x, mouseOld.y);
			mouseStoreBk(mouseNew.x, mouseNew.y);
			mouseDraw(mouseNew);
			if(mouseNew.button == 1){
				if(flag){
					mouse2 = mouseNew;
					mousePutBk(mouseNew.x,mouseNew.y);
					if(!cut(image,mouse1.x,mouse2.x,mouse1.y,mouse2.y,TIANYILAN)){
						//提示失败
					}
					break;
				}else{
					mouse1 = mouseNew;
					flag = 1;
				}
			}
			mouseOld = mouseNew;			
		}
	}	
}
void testPhase(){
	Image image = {0};
	Mouse mouseOld, mouseNew;
	readBMP(&image,"temp\\grass.bmp",400,200,1);
	mouseStatus(&mouseOld);
	mouseStoreBk(mouseOld.x, mouseOld.y);
	bar(300,300,300 + 32,300 + 32,PINK);
    while(1){
		mouseStatus(&mouseNew);
		if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
			continue;
		else{
			mousePutBk(mouseOld.x, mouseOld.y);
			mouseStoreBk(mouseNew.x, mouseNew.y);
			mouseDraw(mouseNew);
			if(mouseDown(300,300,332,332)){
				mousePutBk(mouseNew.x,mouseNew.y);
				cutPhase(&image);
				break;
			}
			mouseOld = mouseNew;
        }
    }
}