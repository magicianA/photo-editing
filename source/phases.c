#include"phases.h"

void cutPhase(Image *image){
    int flag = 0;
    Mouse mouseOld,mouseNew,mouse1,mouse2;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x,mouseOld.y);
    TextGB16(200,571,15,WHITE,"请选择点1");
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
                        msgPhase(20,20,"切割失败");
                    }
                    bar(200,571,500,600,GRAY);
                    break;
                }else{
                    mouse1 = mouseNew;
                    flag = 1;
                    bar(200,571,500,600,GRAY);
                    TextGB16(200,571,15,WHITE,"请选择点2");
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
void msgPhase(int x,int y,char *s){
    Mouse mouseOld,mouseNew;
    Image bg;
    int i,j;
    bg.x = x,bg.y = y,bg.height = 200 + 20,bg.width = 300 + 20; 
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 100,y + 165,x + 200 - 1,y + 195 - 1,TIANYILAN);
    TextGB64(x + 100,y,50,WHITE,"提示",0);
    TextGB32(x + 110,y + 165,40,WHITE,"确定");
    TextGB32(x + 90,y + 100,40,BLACK,s);
    while(1){
        mouseStatus(&mouseNew);
        if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else{
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if(mouseDown(x + 100,y + 165,x + 200,y + 195)){
                break;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}
void fliterPhase(Image *image){
    Mouse mouseOld,mouseNew;
    Image bg;
    int i,j,x,y;
    char s[10];
    bg.x = 300,bg.y = 150,bg.height = 230 + 20,bg.width = 300 + 20; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 230 - 1,BLUE);
    bar(x + 100,y + 195,x + 200 - 1,y + 225 - 1,TIANYILAN);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 100,y,50,WHITE,"滤镜",0);
    TextGB32(x + 110,y + 195,40,WHITE,"确定");
    while(1){
        mouseStatus(&mouseNew);
        if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else{
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x + 100,y + 195,x + 200,y + 225)){
                putImage(&bg,x,y);
                return;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}
void adjustPhase(Image *image){
    Mouse mouseOld,mouseNew;
    Image bg;
    int i,j,x,y;
    int deltas = 0,deltal = 0;
    char s[10];
    bg.x = 300,bg.y = 150,bg.height = 230 + 20,bg.width = 300 + 20; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 230 - 1,BLUE);
    bar(x + 100,y + 195,x + 200 - 1,y + 225 - 1,TIANYILAN);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 100,y,50,WHITE,"调节",0);
    TextGB32(x + 10,y + 55,30,BLACK,"饱和度");
    TextGB32(x + 10,y + 120,30,BLACK,"亮度");
    TextGB32(x + 110,y + 195,40,WHITE,"确定");
    line(x+50,y+100,x+250,y+100,WHITE);
    line(x+50,y+165,x+250,y+165,WHITE);
    //bar(x+145,y+95,x+155,y+105,RED);
    //bar(x+145,y+160,x+155,y+170,RED);
    TextGB16(x+260,y+100,10,WHITE,"0");
    TextGB16(x+260,y+165,10,WHITE,"0");
    while(1){
        mouseStatus(&mouseNew);
        if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else{
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x+50,y+90,x+250,y+110)){
                line(x+50,y+100,x+250,y+100,WHITE);
                deltas = mouseNew.x - (x + 150);
                sprintf(s,"%d",deltas);
                bar(x+260,y+100,x+290,y+115,BLUE);
                TextGB16(x+260,y+100,10,WHITE,s);
            }
            if(mouseDown(x+50,y+155,x+250,y+175)){
                line(x+50,y+165,x+250,y+165,WHITE);
                deltal = mouseNew.x - (x + 150);
                sprintf(s,"%d",deltal);
                bar(x+260,y+165,x+290,y+180,BLUE);
                TextGB16(x+260,y+165,10,WHITE,s);
            }
            if(mouseDown(x + 100,y + 195,x + 200,y + 225)){
                putImage(&bg,x,y);
                TextGB16(200,571,15,WHITE,"调整饱和度中，请稍候");
                addSaturation(image,deltas / 200.0);
                bar(200,571,500,600,GRAY);
                TextGB16(200,571,15,WHITE,"调整亮度中，请稍候");
                addBrightness(image,deltal / 200.0);
                bar(200,571,500,600,GRAY);
                return;
            }
            mouseOld = mouseNew;
        }
    }
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
    putUI("ui\\new.bmp",3+192,0,-1);
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
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,128,64,192)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    cutPhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(3+128,0,3+192,64)){
                if(image.height != 0)
                    saveBMP(image.x,image.y,image.x + image.width,image.y + image.height,"temp\\result.bmp");
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,192,64,256)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    fliterPhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,320,64,384)){
                if(image.height != 0){
                    pictureMirror(&image);
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,256,64,320)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    adjustPhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(3+192,0,256,64)){
                //todo
            }
            mouseOld = mouseNew;
        }
    }
}
void inputPhase(){
    
}
void goodbyePhase(){
    showGoodbyeImage();
    TextGB64(0,0,50,WHITE,"最后祝你身体健康，再见",5);
    TextASC128(300,400,70,WHITE,"GOODBYE",5);
    delay(1000);
}