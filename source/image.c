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

int saveBMP(int x1,int y1,int x2,int y2,char* path)
{
	int i, j;
	FILE* fp;
	BGR* buffer;
	u16 width = x2 - x1;
	u16 height = y2 - y1;
	u32 color24;
	u32 bmpbytes;
	u32 linebytes;
	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;

	linebytes = (3 * width) % 4;
	if (!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	bmpbytes = linebytes * height + 54;
	bmphead.bfType = 0x4d42;
	bmphead.bfSize = bmpbytes;
	bmphead.bfReserved1 = 0;
	bmphead.bfReserved2 = 0;
	bmphead.bfOffBits = 0x36;
	bmpinfo.biSize = 0x28;
	bmpinfo.biWidth = width;
	bmpinfo.biHeight = height;
	bmpinfo.biPlanes = 1;
	bmpinfo.biBitCount = 0x18;
	bmpinfo.biCompression = 0;
	bmpinfo.biSizeImage = bmpbytes - 54;
	bmpinfo.biXPelsPerMeter = 0;
	bmpinfo.biYPelsPerMeter = 0;
	bmpinfo.biClrUsed = 0;
	bmpinfo.biClrImportant = 0;

	if ((buffer = (BGR*)malloc(3 * width)) == 0)
	{
		//无法开辟内存
		return 0;
	}
	if ((fp = fopen(path, "wb")) == NULL)
	{
		//无法创建文件
		return 0;
	}

	fwrite(&bmphead, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&bmpinfo, sizeof(BITMAPINFOHEADER), 1, fp);

	fseek(fp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		for (j = width - 1; j > -1; j--)
		{
			color24 = getPixel(x1 + j, y1 + i);
			buffer[j].r = color24 >> 16 & 0xff;
			buffer[j].g = color24 >> 8 & 0xff;
			buffer[j].b = color24 & 0xff;
		}
		fwrite(buffer, linebytes, 1, fp);
	}

	free(buffer);
	fclose(fp);
	return 1;
}

int saveImageCache(Image const *image){
    FILE *fp;
    int i,j;
    u32 color;
    if(!(image->cachePath)) return 0;
    if((fp = fopen(image->cachePath,"wb")) == 0)
        return 0;
    for(i = 0;i < image->width;i++){
        for(j = 0;j < image->height;j++){
            color = getPixel(image->x + i,image->y + j);
            fwrite(&color,4,1,fp);
        }
    }
    fclose(fp);
    return 1;
}
int putImage(Image const *image,int x,int y){
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
    fclose(fp);
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
u32 getPixelFromCache(FILE *fp,long x,long y,int height){
    u32 color;
    fseek(fp,(x * height + y) * 4,SEEK_SET);
    fread(&color,4,1,fp);
    return color;
}
int convolute3(Image *image,double core[][3]){
    FILE *fp;
    int i,j;
    int p1,p2;
    int x,y,width,height;
    u32 pix[3][3];
    RGB res;
    double r = 0,g = 0,b = 0;
    x = image->x,y = image->y,width = image->width,height = image->height;
    if(!(image->cachePath)) return 0;
    if((fp = fopen(image->cachePath,"rb")) == 0)
        return 0;
    for(i = 0;i < width;i++){
        for(j = 0;j < height;j++){
            r = g = b = 0;
            for(p1 = -1;p1 <= 1;p1++) for(p2 = -1;p2 <= 1;p2++)
                pix[1 + p1][1 + p2] = getPixelFromCache(fp,(i + width + p1) % width,(j + height + p2) % height,height);
            for(p1 = 0;p1 <= 2;p1++) for(p2 = 0;p2 <= 2;p2++){
                r += (pix[p1][p2] >> 16) / 256.0 * core[p1][p2];
                g += ((pix[p1][p2] >> 8) & 0xff) / 256.0 * core[p1][p2];
                b += (pix[p1][p2] & 0xff) / 256.0 * core[p1][p2]; 
            }
            r = min(r,1);
            g = min(g,1);
            b = min(b,1);
            r = max(r,0);
            g = max(g,0);
            b = max(b,0);
            res.r = r * 256;
            res.g = g * 256;
            res.b = b * 256;
            if(fabs(r - 1) < 1e-6) res.r = 255;
            if(fabs(g - 1) < 1e-6) res.g = 255;
            if(fabs(b - 1) < 1e-6) res.b = 255;
            putPixel(x + i,y + j,RGB2u32(res));
        }
    }
    return 1;
    /*FILE *fp;
    int i,j;
    u32 color[3];
    u32 up;
    double sum;
    if(!(image->cachePath)) return 0;
    if((fp = fopen(image->cachePath,"rb")) == 0)
        return 0;
    up = getPixel(image->x + 1,image->y);
    for(i = 1;i < image->width - 1;i++){
        for(j = 1;j < image->height - 1;j++){
            fread(color,4,3,fp);
            sum = core[0][0] * color[0] + core[0][1] * color[1] + core[0][2] * color[2] \
                + core[1][0] * up + core[1][1] * getPixel(image->x + i,image->y + j) + core[1][2] * getPixel(image->x + i,image->y + j + 1) \
                + core[2][0] * getPixel(image->x + i + 1,image->y + j - 1) + core[2][1] * getPixel(image->x + i + 1,image->y + j) + core[2][2] * getPixel(image->x + i + 1,image->y + j + 1);
            putPixel(image->x + i,image->y + j,(u32)sum);
            up = getPixel(image->x + i,image->y + j);
            //if(j < )
                fseek(fp,-8,SEEK_CUR);
        }
    }
    return 1;*/
}
int convolute5(Image *image,double core[][5]){
    FILE *fp;
    int i,j;
    int p1,p2;
    int x,y,width,height;
    u32 pix[5][5];
    RGB res;
    double r = 0,g = 0,b = 0;
    x = image->x,y = image->y,width = image->width,height = image->height;
    if(!(image->cachePath)) return 0;
    if((fp = fopen(image->cachePath,"rb")) == 0)
        return 0;
    for(i = 0;i < width;i++){
        for(j = 0;j < height;j++){
            r = g = b = 0;
            for(p1 = -2;p1 <= 2;p1++) for(p2 = -2;p2 <= 2;p2++)
                pix[2 + p1][2 + p2] = getPixelFromCache(fp,(i + width + p1) % width,(j + height + p2) % height,height);
            for(p1 = 0;p1 < 5;p1++) for(p2 = 0;p2 < 5;p2++){
                r += (pix[p1][p2] >> 16) / 256.0 * core[p1][p2];
                g += ((pix[p1][p2] >> 8) & 0xff) / 256.0 * core[p1][p2];
                b += (pix[p1][p2] & 0xff) / 256.0 * core[p1][p2]; 
            }
            r = min(r,1);
            g = min(g,1);
            b = min(b,1);
            r = max(r,0);
            g = max(g,0);
            b = max(b,0);
            res.r = r * 256;
            res.g = g * 256;
            res.b = b * 256;
            if(fabs(r - 1) < 1e-6) res.r = 255;
            if(fabs(g - 1) < 1e-6) res.g = 255;
            if(fabs(b - 1) < 1e-6) res.b = 255;
            putPixel(x + i,y + j,RGB2u32(res));
        }
    }
    return 1; 
}
void sharpen(Image *image,double strength){
    double core[3][3] = {0};
    core[0][1] = core[1][0] = core[1][2] = core[2][1] = -strength;
    core[1][1] = 1 + 4 * strength; 
    convolute3(image,core); 
}
void blur(Image *image){
    double core[3][3] = {1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9};
    convolute3(image,core);
}
void movingBlur(Image *image){
    double core[5][5] = {{0.2,0,0,0,0},{0,0.2,0,0,0},{0,0,0.2,0,0},{0,0,0,0.2,0},{0,0,0,0,0.2}};
    convolute5(image,core);
}
void unsharpen(Image *image){
    double core[5][5] = {{-1/256.0,-4/256.0,-6/256.0,-4/256.0,-1/256.0},{-4/256.0,-16/256.0,-24/256.0,-16/256.0,-4/256.0},\
    {-6/256.0,-24/256.0,476/256.0,-24/256.0,-6/256.0},{-4/256.0,-16/256.0,-24/256.0,-16/256.0,-4/256.0},{-1/256.0,-4/256.0,-6/256.0,-4/256.0,-1/256.0}};
    convolute5(image,core);
}
void curve(Image *image){
    double core[3][3] = {{-6,-3,0},{-3,1,3},{0,3,6}};
    convolute3(image,core);
}