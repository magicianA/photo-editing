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
