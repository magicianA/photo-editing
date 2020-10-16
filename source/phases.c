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
void linePhase(Image *image,u32 color){
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
                    if(!drawLine(image,mouse1.x,mouse2.x,mouse1.y,mouse2.y,color)){
                        msgPhase(20,20,"划线失败");
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
void emptyBarPhase(Image *image,u32 color){
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
                    if(!drawBarEmpty(image,mouse1.x,mouse2.x,mouse1.y,mouse2.y,color)){
                        msgPhase(20,20,"划线失败");
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
void filledBarPhase(Image *image,u32 color){
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
                    if(!drawBarFilled(image,mouse1.x,mouse2.x,mouse1.y,mouse2.y,color)){
                        msgPhase(20,20,"划线失败");
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

void trianglePhase(Image *image,u32 color){
    int flag = 0;
    Mouse mouseOld,mouseNew,mouse1,mouse2,mouse3;
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
                if(flag == 2){
                    mouse3 = mouseNew;
                    mousePutBk(mouseNew.x,mouseNew.y);
                    if(!drawTriangle(image,mouse1.x,mouse2.x,mouse3.x,mouse1.y,mouse2.y,mouse3.y,color)){
                        msgPhase(20,20,"划线失败");
                    }
                    bar(200,571,500,600,GRAY);
                    break;
                }else if(flag == 1){
                    mouse2 = mouseNew;
                    flag++;
                    bar(200,571,500,600,GRAY);
                    TextGB16(200,571,15,WHITE,"请选择点3");
                }else{
                    mouse1 = mouseNew;
                    flag++;
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
                zoom(&image,0.8,1.2);
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
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 100,y + 165,x + 200 - 1,y + 195 - 1,RED);
    TextGB64(x + 100,y,50,WHITE,"提示",0);
    TextGB32(x + 110,y + 165,40,WHITE,"确定");
    TextGB32(x + 10,y + 100,40,BLACK,s);
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
    char fliterNames[15][20];
    void (*filterFunc[15])(Image *) = {&old,&reverse,&gray,&sharpen,&blur,&curve,&movingBlur,&unsharpen,&melt,&cartoon,&extreme,&singleRed,&singleGreen,&singleBlue,NULL};
    int curfilter = -1,curPage = 0;
    int filtercount = 14;
    int i,j,x,y;
    char s[10];
    bg.x = 300,bg.y = 150,bg.height = 250 + 20,bg.width = 300 + 20; 
    x = 300,y = 150;
    strcpy(fliterNames[0],"复古");
    strcpy(fliterNames[1],"反色");
    strcpy(fliterNames[2],"灰度");    
    strcpy(fliterNames[3],"锐化");
    strcpy(fliterNames[4],"模糊");
    strcpy(fliterNames[5],"浮雕");
    strcpy(fliterNames[6],"运动模糊");
    strcpy(fliterNames[7],"降噪");
    strcpy(fliterNames[8],"熔铸");
    strcpy(fliterNames[9],"连环画");
    strcpy(fliterNames[10],"黑白");
    strcpy(fliterNames[11],"猩红");
    strcpy(fliterNames[12],"翠绿");
    strcpy(fliterNames[13],"蔚蓝");
    strcpy(fliterNames[14],"空");
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 250 - 1,BLUE);
    bar(x + 100,y + 215,x + 220 - 1,y + 245 - 1,TIANYILAN);
    putUI("ui\\up.bmp",x + 230,y + 60,-1);
    putUI("ui\\down.bmp",x + 230,y + 110,-1);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 100,y,50,WHITE,"滤镜",0);
    TextGB32(x + 110,y + 215,40,WHITE,"确定");
    bar(x + 10,y + 70,x + 220,y + 100,PINK);
    TextGB32(x + 10,y + 70,30,WHITE,fliterNames[0]);

    bar(x + 10,y + 110,x + 220,y + 140,PINK);
    TextGB32(x + 10,y + 110,30,WHITE,fliterNames[1]);

    bar(x + 10,y + 150,x + 220,y + 180,PINK);
    TextGB32(x + 10,y + 150,30,WHITE,fliterNames[2]);
    
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
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x + 230,y + 60,x + 270,y + 100)){
                if(curPage > 0){
                    curPage--;
                    bar(x + 10,y + 70,x + 220,y + 100,PINK);
                    TextGB32(x + 10,y + 70,30,WHITE,fliterNames[0 + curPage * 3]);
                    bar(x + 10,y + 110,x + 220,y + 140,PINK);
                    TextGB32(x + 10,y + 110,30,WHITE,fliterNames[1 + curPage * 3]);
                    bar(x + 10,y + 150,x + 220,y + 180,PINK);
                    TextGB32(x + 10,y + 150,30,WHITE,fliterNames[2 + curPage * 3]);
                }
            }
            if(mouseDown(x + 230,y + 110,x + 270,y + 150)){
                if(curPage < 4){
                    curPage++;
                    bar(x + 10,y + 70,x + 220,y + 100,PINK);
                    TextGB32(x + 10,y + 70,30,WHITE,fliterNames[0 + curPage * 3]);
                    bar(x + 10,y + 110,x + 220,y + 140,PINK);
                    TextGB32(x + 10,y + 110,30,WHITE,fliterNames[1 + curPage * 3]);
                    bar(x + 10,y + 150,x + 220,y + 180,PINK);
                    TextGB32(x + 10,y + 150,30,WHITE,fliterNames[2 + curPage * 3]);
                }
            }
            if(mouseDown(x + 10,y + 70,x + 220,y + 100)){
                curfilter = 0 + curPage * 3;
                if(curfilter >= filtercount){
                    curfilter = -1;
                }
            }
            if(mouseDown(x + 10,y + 110,x + 220,y + 140)){
                curfilter = 1 + curPage * 3;
                if(curfilter >= filtercount){
                    curfilter = -1;
                }
            }
            if(mouseDown(x + 10,y + 150,x + 220,y + 180)){
                curfilter = 2 + curPage * 3;
                if(curfilter >= filtercount){
                    curfilter = -1;
                }
            }
            if(mouseDown(x + 100,y + 215,x + 220,y + 245)){
                if(curfilter != -1){
                    putImage(&bg,x,y);
                    TextGB16(200,571,15,WHITE,"处理中，请稍候");
                    filterFunc[curfilter](image);
                    bar(200,571,500,600,GRAY);
                    return;
                }else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(0,0,"请选择滤镜");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
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
    int curPage = 0;
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
    putUI("ui\\resize.bmp",0,384 + 5,-1);
    putUI("ui\\brush.bmp",0,448 + 10,-1);
    putUI("ui\\new.bmp",3+192,0,-1);
    putUI("ui\\file.bmp",3+256,0,-1);
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
                mousePutBk(mouseNew.x,mouseNew.y);
                openPhase(&image);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(0,64,64,128)){
                if(curPage == 0){
                    if(image.height != 0){
                        spin(&image,WHITE);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }else if(curPage == 1){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        linePhase(&image,WHITE);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(0,128,64,192)){
                if(curPage == 0){
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
                }else if(curPage == 1){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        trianglePhase(&image,WHITE);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(3+128,0,3+192,64)){
                if(image.height != 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    savePhase(&image);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                    //saveBMP(image.x,image.y,image.x + image.width,image.y + image.height,"temp\\result.bmp");
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,192,64,256)){
                if(curPage == 0){
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
                }else if(curPage == 1){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        emptyBarPhase(&image,WHITE);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(0,320,64,384)){
                if(curPage == 0){
                    if(image.height != 0){
                        mirror(&image);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    } 
                }else if(curPage == 1){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        delay(20);
                        drawFreePhase(&image,WHITE);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(0,256,64,320)){
                if(curPage == 0){
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
                }else if(curPage == 1){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        filledBarPhase(&image,WHITE);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(0,384+5,64,448+5)){
                if(curPage == 0){
                    if(image.height != 0){
                        mousePutBk(mouseNew.x,mouseNew.y);
                        zoomPhase(&image);
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                    else{
                        mousePutBk(mouseNew.x,mouseNew.y);
                        msgPhase(200,200,"未打开图片");
                        mouseStoreBk(mouseNew.x,mouseNew.y);
                    }
                }
            }
            if(mouseDown(3+192,0,256,64)){
                mousePutBk(mouseNew.x,mouseNew.y);
                newPhase(&image);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(3 + 256,0,3 + 320,64)){
                if(image.height != 0){
                    closeImage(&image);
                }
                else{
                    mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200,200,"未打开图片");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            if(mouseDown(0,448 + 10,64,512 + 10)){
                if(curPage == 0){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    curPage++;
                    bar(0,64,64,570,TIANYILAN);
                    putUI("ui\\line.bmp",0,64,-1);
                    putUI("ui\\triangle.bmp",0,128,-1);
                    putUI("ui\\rect.bmp",0,192,-1);
                    putUI("ui\\bar.bmp",0,256,-1);
                    putUI("ui\\pbrush.bmp",0,320,-1);
                    putUI("ui\\return.bmp",0,448 + 10,-1);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }else if(curPage == 1){
                    mousePutBk(mouseNew.x,mouseNew.y);
                    curPage--;
                    bar(0,64,64,570,TIANYILAN);
                    putUI("ui\\spin.bmp",0,64,-1);
                    putUI("ui\\cut.bmp",0,128,-1);
                    putUI("ui\\rgb.bmp",0,192,-1);
                    putUI("ui\\adjust.bmp",0,256,-1);
                    putUI("ui\\reflect.bmp",0,320,-1);
                    putUI("ui\\resize.bmp",0,384 + 5,-1);
                    putUI("ui\\brush.bmp",0,448 + 10,-1);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
            }
            mouseOld = mouseNew;
        }
    }
}
void openPhase(Image *image){
    Mouse mouseOld,mouseNew;
    Image bg;
    int i,j,x,y;
    char s[20] = "temp\\";
    char fileName[10] = "timg.bmp";
    if(image->height != 0){
        msgPhase(200,200,"您已打开图片");
        return;
    }
    bg.x = 300,bg.y = 150,bg.height = 230 + 40,bg.width = 300 + 40; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 230 - 1,BLUE);
    bar(x + 100,y + 195,x + 200 - 1,y + 225 - 1,TIANYILAN);
    bar(x + 40,y + 90,x + 250 - 1,y + 140 - 1,WHITE);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 30,y,50,WHITE,"打开图片",0);
    TextGB32(x + 110,y + 195,40,WHITE,"确定");
    TextASC24(340, 240, 14, 0, fileName);
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
            if(mouseDown(x + 40,y + 90,x + 250,y + 140)){
                mousePutBk(mouseNew.x,mouseNew.y);
                inputPhase(fileName,1,0,0);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(x + 100,y + 195,x + 200,y + 225)){
                mousePutBk(mouseNew.x,mouseNew.y);
                putImage(&bg,x,y);
                strcat(s,fileName);
                if(readBMP(image,s,300,200,1) == 1)
                    return;
                else{
                    image->x = image->y = image->height = image->width = 0;
                    strcpy(image->cachePath,"");
                    strcpy(s,"temp\\");
                    msgPhase(200,200,"打开失败");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                    break;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}
void goodbyePhase(){
    showGoodbyeImage();
    TextGB64(0,0,50,WHITE,"最后祝你身体健康，再见",5);
    TextASC128(300,400,70,WHITE,"GOODBYE",5);
    delay(1000);
}
int inputPhase(char* filename,int flag,int dx,int dy){
    unsigned int key;
    unsigned int len = strlen(filename);
    while((key = bioskey(0)) != Enter){
        if (key == Backspace){
            if (len > 0){
                len--;
                filename[len] = '\0';
                bar(340 + dx, 240 + dy, 550 - 1 + dx, 280 - 1 + dy, WHITE);
                TextASC24(340 + dx, 240 + dy, 14, 0, filename);
            }
        }
        else if(key == Enter){
            return 1;
        }
        else if((key & 0xff) != 0 && len < 13){
            if(flag == 1){
                filename[len] = key & 0xff;
                filename[len + 1] = '\0';
                len++;
                TextASC24(340 + dx, 240 + dy, 14, 0, filename);
            }else{
                if((key & 0xff) >= '0' && (key & 0xff) <= '9' && len < 10){
                    filename[len] = key & 0xff;
                    filename[len + 1] = '\0';
                    len++;
                    TextASC24(340 + dx, 240 + dy, 14, 0, filename);
                }
            }
        }
    }
    return 0;
}

void savePhase(Image *image){
    Mouse mouseOld,mouseNew;
    Image bg;
    int i,j,x,y;
    char s[20] = "temp\\";
    char fileName[12] = "result.bmp";
    bg.x = 300,bg.y = 150,bg.height = 230 + 40,bg.width = 300 + 40; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 230 - 1,BLUE);
    bar(x + 100,y + 195,x + 200 - 1,y + 225 - 1,TIANYILAN);
    bar(x + 40,y + 90,x + 250 - 1,y + 140 - 1,WHITE);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 30,y,50,WHITE,"保存图片",0);
    TextGB32(x + 110,y + 195,40,WHITE,"确定");
    TextASC24(340, 240, 14, 0, fileName);
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
            if(mouseDown(x + 40,y + 90,x + 250,y + 140)){
                mousePutBk(mouseNew.x,mouseNew.y);
                inputPhase(fileName,1,0,0);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(x + 100,y + 195,x + 200,y + 225)){
                mousePutBk(mouseNew.x,mouseNew.y);
                putImage(&bg,x,y);
                strcat(s,fileName);
                if(saveBMP(image->x,image->y,image->x + image->height,image->y + image->width,s) == 1)
                    return;
                else{
                    strcpy(s,"temp\\");
                    msgPhase(200,200,"保存失败");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                    return;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}

void zoomPhase(Image *image){
    Mouse mouseOld = {0},mouseNew;
    Image bg;
    int i,j,x,y;
    double scaleX = 1,scaleY = 1;
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
    TextGB64(x + 100,y,50,WHITE,"放缩",0);
    TextGB32(x + 10,y + 55,30,BLACK,"横轴放缩倍率");
    TextGB32(x + 10,y + 120,30,BLACK,"纵轴放缩倍率");
    TextGB32(x + 110,y + 195,40,WHITE,"确定");
    line(x+50,y+100,x+250,y+100,WHITE);
    line(x+50,y+165,x+250,y+165,WHITE);
    //bar(x+145,y+95,x+155,y+105,RED);
    //bar(x+145,y+160,x+155,y+170,RED);
    TextGB16(x+260,y+100,10,WHITE,"1.0");
    TextGB16(x+260,y+165,10,WHITE,"1.0");
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
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x+50,y+90,x+250,y+110)){
                line(x+50,y+100,x+250,y+100,WHITE);
                scaleX = (mouseNew.x - (x + 50)) / 200.0 * 1.5 + 0.5;
                scaleY = scaleX;
                sprintf(s,"%3.2f",scaleX);
                bar(x+260,y+100,x+298,y+115,BLUE);
                TextGB16(x+260,y+100,10,WHITE,s);
                bar(x+260,y+165,x+298,y+180,BLUE);
                TextGB16(x+260,y+165,10,WHITE,s);
            }
            if(mouseDown(x+50,y+155,x+250,y+175)){
                line(x+50,y+165,x+250,y+165,WHITE);
                scaleY = (mouseNew.x - (x + 50)) / 200.0 * 1.5 + 0.5;
                sprintf(s,"%3.2f",scaleY);
                bar(x+260,y+165,x+298,y+180,BLUE);
                TextGB16(x+260,y+165,10,WHITE,s);
            }
            if(mouseDown(x + 100,y + 195,x + 200,y + 225)){
                putImage(&bg,x,y);
                TextGB16(200,571,15,WHITE,"调整中，请稍候");
                if(zoom(image,scaleX,scaleY) == 0){
                    msgPhase(200,200,"放缩失败");
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                }
                bar(200,571,500,600,GRAY);
                return;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}

void newPhase(Image *image){
    Mouse mouseOld = {0},mouseNew = {0};
    Image bg;
    int i,j,x,y;
    char sx[20] = "100",sy[20] = "100";
    int pWidth,pHeight;
    if(image->height != 0){
        msgPhase(200,200,"您已打开图片");
        return;
    }
    bg.x = 300,bg.y = 150,bg.height = 280 + 40,bg.width = 300 + 40; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 280 - 1,BLUE);
    bar(x + 100,y + 245,x + 200 - 1,y + 275 - 1,TIANYILAN);
    bar(x + 40,y + 90,x + 250 - 1,y + 130 - 1,WHITE);
    bar(x + 40,y + 160,x + 250 - 1,y + 200 - 1,WHITE);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 30,y,50,WHITE,"新建图片",0);
    TextGB32(x + 110,y + 245,40,WHITE,"确定");
    TextGB16(x + 40,y + 70,15,WHITE,"图片长度");
    TextGB16(x + 40,y + 140,15,WHITE,"图片宽度");
    TextASC24(340, 240, 14, 0, sx);
    TextASC24(340, 310, 14, 0, sy);
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
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x + 40,y + 90,x + 250,y + 130)){
                mousePutBk(mouseNew.x,mouseNew.y);
                inputPhase(sx,2,0,0);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(x + 40,y + 160,x + 250,y + 200)){
                mousePutBk(mouseNew.x,mouseNew.y);
                inputPhase(sy,2,0,70);
                mouseStoreBk(mouseNew.x,mouseNew.y);
            }
            if(mouseDown(x + 100,y + 245,x + 200,y + 275)){
                pWidth = pHeight = 0;
                pWidth = atoi(sx);
                pHeight = atoi(sy);
                if(pWidth >= BMP_WIDTH_MIN && pWidth <= BMP_WIDTH_MAX && pHeight >= BMP_HEIGTH_MIN && pHeight <= BMP_HEIGTH_MAX){
                    image->x = 300,image->y = 150;
                    image->width = pWidth,image->height = pHeight;
                    mousePutBk(mouseNew.x,mouseNew.y);
                    putImage(&bg,x,y);
                    mouseStoreBk(mouseNew.x,mouseNew.y);
                    strcpy(image->cachePath,"newpic.tmp");
                    for(i = 0;i < pWidth;i++){
                        for(j = 0;j < pHeight;j++){
                            putPixel(image->x + i,image->y + j,GRAY);
                        }
                    }
                    saveImageCache(image);
                    return;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}

void colorPhase(u32 *pColor){
    Mouse mouseOld = {0},mouseNew = {0};
    Image bg;
    int i,j,x,y;
    bg.x = 300,bg.y = 150,bg.height = 280 + 40,bg.width = 300 + 40; 
    x = 300,y = 150;
    strcpy(bg.cachePath,"temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0,y + 50,x + 300 - 1,y + 200 - 1,BLUE);
    bar(x + 0,y + 0,x + 300 - 1,y + 55 - 1,TIANYILAN);
    bar(x + 250,y + 0,x + 300 - 1,y + 55 - 1,RED);
    bar(x + 0,y + 200,x + 300 - 1,y + 280 - 1,BLUE);
    bar(x + 100,y + 245,x + 200 - 1,y + 275 - 1,TIANYILAN);
    line(x+250,y+0,x+300,y+55,WHITE);
    line(x+300,y+0,x+250,y+55,WHITE);
    TextGB64(x + 30,y,50,WHITE,"选择颜色",0);
    TextGB32(x + 110,y + 245,40,WHITE,"确定");
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
            if(mouseDown(x+250,y+0,x+300,y+55)){
                break;
            }
            if(mouseDown(x + 100,y + 245,x + 200,y + 275)){
                break;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg,x,y);
}

void drawFreePhase(Image *image,u32 color){
    Mouse mouseOld,mouseNew;
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
            if(!mouseDown(0,0,SCR_WIDTH,SCR_HEIGHT)){
                break;
            }else if(mouseDown(image->x,image->y,image->x + image->width - 1,image->y + image->height - 1)){
                putPixel(mouseNew.x,mouseNew.y,color);
            }
            mouseOld = mouseNew;
        }
    }
}