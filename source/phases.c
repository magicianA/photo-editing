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
                        msgPhase(20,20);
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
    Mouse mouseOld,mouseNew;
    readBMP(&image,"temp\\timg.bmp",400,200,1);
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
                spin(&image,TIANYILAN);
                blur(&image);
                //cutPhase(&image);
                break;
            }
            mouseOld = mouseNew;
        }
    }
}
int msgPhase(int x,int y){
    Image image;
    int i,j;
    image.x = x,image.y = y,image.height = 200,image.width = 300;
    strcpy(image.cachePath,"temp\\bgpic.tmp");
    if(!saveImageCache(&image)){
        return 0;
    }
    for(i = 0;i < 300;i++){
        for(j = 0;j < 200;j++){
            putPixel(x + i,y + j,PINK);
        }
    }
    TextGB16(x + 30,x + 40,14,WHITE,"ÇÐ¸îÊ§°Ü");
    getch();
    putImage(&image,x,y);
    return 1;
}

void mainPhase(){
    //todo
}