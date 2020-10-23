#include"mirror.h"


void mirror(Image *image){
    u32 c1,c2;
    int i,j,k,x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    for(i = 0,j = width - 1;i < j;i++,j--){
        for(k = 0;k < height;k++){
            c1 = getPixel(x + i,y + k);
            c2 = getPixel(x + j,y + k);
            putPixel(x + j,y + k,c1);
            putPixel(x + i,y + k,c2);
        }
    }
    saveImageCache(image);
}
int cut(Image *image,int x1,int x2,int y1,int y2,u32 color){
    int x,y,width,height,i,j;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x2&&x2<x+width&&y<y1&&y1<y2&&y2<y+height){
        for(i=x;i<x+width;i++){
            for(j=y;j<y+height;j++){
                if(i>=x1&&i<=x2&&j>=y1&&j<=y2){
                    continue;
                }
                else{
                    putPixel(i,j,color);
                }               
            }
        }
    }
    else{
        return 0;
    }
    image->x = x1,image->y = y1;
    image->height = y2 - y1 + 1;
    image->width = x2 - x1 + 1;
    saveImageCache(image);
    return 1;
}
void spin(Image *image,u32 cl){
    int i,j,x,y,width,height;
    u32 color;
    FILE *fp;
    x=image->x,y=image->y,width=image->width,height=image->height;
    for(i=x;i<x+width;i++){
        for(j=y;j<y+height;j++){
            putPixel(i,j,cl);
        }
    }
    image->x=x+width/2-height/2,image->y=y-width/2+height/2;
    image->width=height,image->height=width;
    fp=fopen(image->cachePath,"rb");
    for(j = 0;j < width;j++){
        for(i = height - 1;i >= 0;i--){
            fread(&color,4,1,fp);
            putPixel(image->x + i,image->y + j,color);
        }
    }
    fclose(fp);
    saveImageCache(image);
}
int drawLine(Image *image,int x1,int x2,int y1,int y2,u32 color){
    int x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x+width&&x<x2&&x2<x+width&&y<y1&&y1<y+height&&y<y2&&y2<y+height){
        line(x1,y1,x2,y2,color);
    }
    else{
        return 0;
    }
    saveImageCache(image);
    return 1;
}

int drawBarEmpty(Image *image,int x1,int x2,int y1,int y2,u32 color){
    int x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x+width&&x<x2&&x2<x+width&&y<y1&&y1<y+height&&y<y2&&y2<y+height){
        line(x1,y1,x1,y2,color);
        line(x1,y2,x2,y2,color);
        line(x2,y1,x2,y2,color);
        line(x1,y1,x2,y1,color);
    }
    else{
        return 0;
    }
    saveImageCache(image);
    return 1;
}

int drawBarFilled(Image *image,int x1,int x2,int y1,int y2,u32 color){
    int x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x+width&&x<x2&&x2<x+width&&y<y1&&y1<y+height&&y<y2&&y2<y+height){
        bar(x1,y1,x2,y2,color);
    }
    else{
        return 0;
    }
    saveImageCache(image);
    return 1;
}

int drawTriangle(Image *image,int x1,int x2,int x3,int y1,int y2,int y3,u32 color){
    int x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x+width&&x<x2&&x2<x+width&&x<x3&&x3<x+width&&y<y1&&y1<y+height&&y<y2&&y2<y+height&&y<y3&&y3<y+height){
        line(x1,y1,x2,y2,color);
        line(x1,y1,x3,y3,color);
        line(x2,y2,x3,y3,color);
    }
    else{
        return 0;
    }
    saveImageCache(image);
    return 1;
}


void drawFree(Image *image,u32 color){
    Mouse mouseOld,mouseNew;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x,mouseOld.y);
    while(1){
        mouseStatus(&mouseNew);
        if(mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else{
            if(!mouseDown(0,0,SCR_WIDTH,SCR_HEIGHT)){
                break;
            }else if(mouseNew.x >= image->x && mouseNew.x < image->x + image->width  - 1 && mouseNew.y >= image->y && mouseNew.y < image->y + image->height - 1){
                putPixel(mouseNew.x,mouseNew.y,color);
                putPixel(mouseNew.x + 1,mouseNew.y,color);
                putPixel(mouseNew.x,mouseNew.y + 1,color);
                putPixel(mouseNew.x + 1,mouseNew.y + 1,color);
            }
            mouseOld = mouseNew;
        }
    }
}
void colorBoard(int x,int y){
    int i,j;
    u32 color;
    HSL hsl;
    hsl.h=0;
    hsl.s=0.2;
    hsl.l=0.5;
    for(i=x+0;i<x+130;i++){
        hsl.h=0;
        hsl.s=hsl.s+0.8/130;
        for(j=y+0;j<y+210;j++){
            hsl.h=hsl.h+360.0/210;
            color=RGB2u32(HSL2RGB(hsl));
            putPixel(i,j,color);
        }
    }
}

HSL colorBoardSide(int x,int y,int x1,int y1){
    int i,j,x2,y2;
    u32 color;
    HSL hsl;
    RGB res;
    color=TIANYILAN;
    x2=x1-310;
    y2=y1-215;
    res=getRGB(color >> 16,(color >> 8) & 0xff,color & 0xff);
    hsl=RGB2HSL(res);
    hsl.h=0+y2*360.0/210;
    hsl.s=0.2+x2*0.8/130;
    hsl.l=0;
    for(i=x+0;i<x+140;i++){
        hsl.l=hsl.l+1.0/140;
        for(j=y+0;j<y+50;j++){
            color=RGB2u32(HSL2RGB(hsl));
            putPixel(i,j,color);
        }
    }
    return hsl;
}