#include"image.h"
#define _sq(x) ((x)*(x))

//source:tweetable-mathematical-art
char red_fn(long i,long  j){
    return (char)(_sq(cos(atan2(j-300,i-400)/2))*255);
}
char green_fn(long i,long j){
    return (char)(_sq(cos(atan2(j-300,i-400)/2-2*acos(-1)/3))*255);
}
char blue_fn(long i,long j){
    return (char)(_sq(cos(atan2(j-300,i-400)/2+2*acos(-1)/3))*255);
}
void showGoodbyeImage(){
    int i,j;
    for(i = 0;i < SCR_WIDTH;i++){
        for(j = 0;j < SCR_HEIGHT;j++){
            putPixel(i,j,rgb2u32(red_fn(i,j),green_fn(i,j),blue_fn(i,j)));
        }
    }

}


int readBMP(Image *image,const char *path,int x,int y,int flag){
	int i, j;
	BGR *buffer;
    BGR tt;
    char temp[25];
	u32 color24;
	u32 linebytes;
	FILE *fp = fopen(path, "rb");
    FILE *ft;
	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;

    strcpy(temp,path);
    strcpy(strstr(temp,".bmp"),".tmp");
	if(fp)
	{
		fseek(fp, 28L, 0);
		fread(&bmpinfo.biBitCount, 2, 1, fp);
		if (bmpinfo.biBitCount != 24U)
		{
			fclose(fp);
			return 0;
		}

		fseek(fp, 30L, 0);
		fread(&bmpinfo.biCompression, 4, 1, fp);
		if (bmpinfo.biCompression != 0UL)
		{
			fclose(fp);
			return -1;
		}

		fseek(fp, 18L, 0);
		fread(&bmpinfo.biWidth, 4, 1, fp);
		if (bmpinfo.biWidth > SCR_WIDTH)
		{
			fclose(fp);
			return -1;
		}

		fread(&bmpinfo.biHeight, 4, 1, fp);
		if (bmpinfo.biHeight > SCR_HEIGHT)
		{
			fclose(fp);
			return -1;
		}

		linebytes = (3 * bmpinfo.biWidth) % 4;
		if (!linebytes)
		{
			linebytes = 3 * bmpinfo.biWidth;
		}
		else
		{
			linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;
		}

		if ((buffer = (BGR*)malloc(linebytes)) == 0)
		{
			fclose(fp);
			return -1;
		}

		fseek(fp, 54L, 0);
        if(flag){
		    for (i = bmpinfo.biHeight - 1; i > -1; i--)
		    {
			    fread(buffer, linebytes, 1, fp);
		        for (j = 0; j < bmpinfo.biWidth; j++)
		        {
			        color24 = ((u32)buffer[j].r) << 16 | ((u32)buffer[j].g) << 8 | ((u32)buffer[j].b);
			        putPixel(j + x, i + y, color24);
		        }
		    }
        }
        free(buffer);
        if((ft = fopen(temp,"wb"))== 0) return 0;
        
        image->height = bmpinfo.biHeight;
        image->width = bmpinfo.biWidth;
        image->x = x;
        image->y = y;
		strcpy(image->cachePath,temp);
        for(i = 0;i < image->width;i++){
            for(j = 0;j < image->height;j++){
                color24 = getPixel(x + i,y + j);
                fwrite(&color24,4,1,ft);
            }
        }
		fclose(fp);
        fclose(ft);
	}
	else
	{
		return -1;
	}
	return 1;
}

int putBMP(Image const *image,int x,int y){
    FILE *fp;
    FILE *ft;
    int i,j;
    u32 color;
    if(!(image->cachePath)) return 0;
    if((fp = fopen(image->cachePath,"rb")) == 0)
        return 0;
    for(i = 0;i < image->width;i++){
        for(j = 0;j < image->height;j++){
            fread(&color,4,1,fp);
            putPixel(x + i,y + j,color);
        }
    }
    return 1;
}
u32 RGB2u32(RGB x){
    return ((u32) x.r << 16) | ((u32) x.g << 8) | ((u32) x.b);
}
u32 rgb2u32(byte r,byte g,byte b){
    return ((u32) r << 16) | ((u32) g << 8) | ((u32) b);
}
RGB getRGB(byte r,byte g,byte b){
    RGB t;
    t.r = r,t.b = b,t.g = g;
    return t;
}