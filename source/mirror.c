#include"mirror.h"


void pictureMirror(Image *image){
    u32 c1,c2;
    int i,j,x,y,width,height;
    x=image->x,y=image->y,width=image->width,height=image->height;
    for(i=x;i<=x+(width+1)/2;i++){
        for(j=y;j<=y+height;j++){
            c1=getPixel(i,j);
            c2=getPixel(2*x+width+(width&1)-i,j);
            putPixel(2*x+width+(width&1)-i,j,c1);
            putPixel(i,j,c2);  
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
