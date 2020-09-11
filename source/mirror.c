#include"mirror.h"


void pictureMirror(Image *image){
    u32 c1,c2;
    int i,j,x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    for(i=x;i<=x+width/2;i++){
        for(j=y;j<=y+height;j++){
            c1=getPixel(i,j);
            c2=getPixel(2*x+width-i,j);
            putPixel(2*x+width-i,j,c1);
            putPixel(i,j,c2);      
        }
    }
}
int cut(Image *image,int x1,int x2,int y1,int y2,u32 color){
    /*int x,y,width,height,i,j;
    x=image->x,y=image->y,width=image->width,height=image->height;
    if(x<x1&&x1<x2&&x2<x+width&&y<y1&&y1<y2&&y2<y+height){
        for(i=x;i<=x+width;i++){
            for(j=y;j<=y+height;j++){
                if(i>=x1&&i<=x2&&j>=y2&&j<=y1){
                    continue;
                }
                else{
                    putPixel(i,j,color);
                }               
            }
        }
    }
    else{
        return 1;
    }
    return 0;*/
    int i,j;
    for(i = x1;i <= x2;i++){
        for(j = y1;j <= y2;j++){
            putPixel(i,j,WHITE);
        }
    }
}
