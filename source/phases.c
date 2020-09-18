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
                    if(!cut(image,mouse1.x,mouse2.x,mouse1.y,mouse2.y,WHITE)){
                        msgPhase(20,20,"«–∏Ó ß∞‹");
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
	bar(0,0,SCR_WIDTH,SCR_HEIGHT,TIANYILAN);
    mouseReset();
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
                cutPhase(&image);
                getch();
                break;
            }
            mouseOld = mouseNew;
        }
    }
}
int msgPhase(int x,int y,char *s){
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
    TextGB16(x + 30,x + 40,14,WHITE,s);
    getch();
    putImage(&image,x,y);
    return 1;
}
void adjustPhase(Image *image){
    Image bg;
    int i,j,x,y;
    bg.x = 300,bg.y = 150,bg.height = 300,bg.width = 400; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    for(i = 0;i < 300;i++){
        for(j = 50;j < 200;j++){
            putPixel(x + i,y + j,BLUE);
        }
    }
    for(i = 0;i < 300;i++){
        for(j = 0;j < 55;j++){
            putPixel(x + i,y + j,TIANYILAN);
        }
    }
    TextGB64(x + 100,y,50,WHITE,"µ˜Ω⁄",0);
    getch();
    putImage(&bg,x,y);
}
void mainPhase(){
    Image image = {0};
    Mouse mouseOld,mouseNew;
	bar(0,0,SCR_WIDTH,SCR_HEIGHT,WHITE);
    bar(0,0,64,570,TIANYILAN);
    bar(0,0,800,64,TIANYILAN);
    bar(0,571,800,600,GRAY);
    putUI("ui\\icon.bmp",0,0,-1);
    putUI("ui\\spin.bmp",0,64,-1);
    putUI("ui\\cut.bmp",0,128,-1);
    putUI("ui\\rgb.bmp",0,192,-1);
    putUI("ui\\folder.bmp",3+64,0,-1);
    putUI("ui\\save.bmp",3+128,0,-1);
    putUI("ui\\close.bmp",800-64,0,-1);
    putUI("ui\\adjust.bmp",0,256,-1);
    putUI("ui\\reflect.bmp",0,320,-1);
    mouseReset();

    while(1){
        mouseStatus(&mouseNew);
        if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else{
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if(mouseDown(800-64,0,800,64)){
                break;
            }
            if(mouseDown(3+64,0,3+128,64)){
                readBMP(&image,"temp\\timg.bmp",300,200,1);
            }
            if(mouseDown(0,64,64,128)){
                if(image.height != 0){
                    spin(&image,WHITE);
                }
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            if(mouseDown(0,128,64,192)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    cutPhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            if(mouseDown(3+128,0,3+192,64)){
                if(image.height != 0)
                    saveBMP(image.x,image.y,image.x + image.width,image.y + image.height,"temp\\result.bmp");
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            if(mouseDown(0,192,64,256)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    curve(&image);
                    //addBrightness(&image,0.1);
                    //addSaturation(&image,0.1);
                }
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            if(mouseDown(0,320,64,384)){
                if(image.height != 0){
                    pictureMirror(&image);
                }
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            if(mouseDown(0,256,64,320)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    adjustPhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                else
                    msgPhase(200,200,"Œ¥¥Úø™Õº∆¨");
            }
            mouseOld = mouseNew;
        }
    }
}