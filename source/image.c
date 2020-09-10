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
        fread(&bmphead,sizeof(bmphead),1,fp);
        fread(&bmpinfo,sizeof(bmpinfo),1,fp);
        if(bmphead.bfType != 0x4d42 || bmpinfo.biBitCount != 24u || bmpinfo.biCompression != 0ul || bmpinfo.biWidth > SCR_WIDTH ||
        bmpinfo.biHeight > SCR_HEIGHT){
            fclose(fp);
            return 0;
        }

		linebytes = (3 * bmpinfo.biWidth) % 4;
		if (!linebytes)
			linebytes = 3 * bmpinfo.biWidth;
		else
			linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;

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
	else{
		return -1;
	}
	return 1;
}

int putBMP(Image const *image,int x,int y){
    FILE *fp;
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

void addBrightness(Image *image,double delta){
    int x,y,i,j;
    double r,g,b;
    u32 t;
    HSL hsl;
    x = image->x,y = image->y;
    for(i = 0;i < image->width;i++){
        for(j = 0;j < image->height;j++){
            t = getPixel(x + i,y + j);
            hsl = RGB2HSL(getRGB(t >> 16,(t >> 8) & 0xff,t & 0xff));
            hsl.l += delta;
            hsl.l = min(0.999,hsl.l);
            hsl.l = max(0,hsl.l);
            putPixel(x + i,y + j,RGB2u32(HSL2RGB(hsl)));
        }
    }
}
void addSaturation(Image *image,double delta){
    int x,y,i,j;
    double r,g,b;
    u32 t;
    HSL hsl;
    x = image->x,y = image->y;
    for(i = 0;i < image->width;i++){
        for(j = 0;j < image->height;j++){
            t = getPixel(x + i,y + j);
            hsl = RGB2HSL(getRGB(t >> 16,(t >> 8) & 0xff,t & 0xff));
            hsl.s += delta;
            hsl.s = min(0.999,hsl.s);
            hsl.s = max(0,hsl.s);
            putPixel(x + i,y + j,RGB2u32(HSL2RGB(hsl)));
        }
    }
}
u32 RGB2u32(const RGB x){
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
HSL RGB2HSL(const RGB x){
    HSL t;
    double r = x.r / 256.0,g = x.g / 256.0,b = x.b / 256.0;
    double mx,mn;
    mx = max(max(r,g),b);
    mn = min(min(r,g),b);
    
    t.l = 0.5 * (mx + mn);

    if(fabs(mx - mn) <= 1e-6)
        t.h = 0;
    else if(fabs(mx - r) < 1e-6 && g >= b)
        t.h = 60.0 * (g - b) / (mx - mn);
    else if(fabs(mx - r) < 1e-6 && g < b)
        t.h = 60.0 * (g - b) / (mx - mn) + 360.0;
    else if(fabs(mx - g) < 1e-6)
        t.h = 60.0 * (b - r) / (mx - mn) + 120.0;
    else if(fabs(mx - b) < 1e-6)
        t.h = 60.0 * (r - g) / (mx - mn) + 240.0;

    if(fabs(t.l) <= 1e-6 || fabs(mx - mn) <= 1e-6)
        t.s = 0;
    else if(t.l > 0 && t.l <= 0.5)
        t.s = (mx - mn) / (2 * t.l);
    else if(t.l > 0.5)
        t.s = (mx - mn) / (2 - 2 * t.l);

    return t;    
}
RGB HSL2RGB(HSL hsl){
    RGB res;
    double r1,g1,b1;
    double c,x,h0,m;
    double h = hsl.h,s = hsl.s,l = hsl.l;
    c = (1 - fabs(2 * l - 1)) * s;
    h0 = h / 60;
    x = c * (1 - fabs((h0 - ((int)(h0 / 2)) * 2) - 1));
    switch((int)(h0)){
        case 0:
            r1 = c;
            g1 = x;
            b1 = 0;
            break;
        case 1:
            r1 = x;
            g1 = c;
            b1 = 0;
            break;
        case 2:
            r1 = 0;
            g1 = c;
            b1 = x;
            break;
        case 3:
            r1 = 0;
            g1 = x;
            b1 = c;
            break;
        case 4:
            r1 = x;
            g1 = 0;
            b1 = c;
            break;
        case 5:
            r1 = c;
            g1 = 0;
            b1 = x;
            break;
    }
    m = l - c / 2;

    res.r = (r1 + m) * 256;
    res.g = (g1 + m) * 256;
    res.b = (b1 + m) * 256;
    if(fabs((r1 + m) - 1) < 1e-6) res.r = 255;
    if(fabs((g1 + m) - 1) < 1e-6) res.g = 255;
    if(fabs((b1 + m) - 1) < 1e-6) res.b = 255;
    return res;
}