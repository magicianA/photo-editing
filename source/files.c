#include "files.h"


/*********************************************
FUNCTION: fileCount
DESCRIPTION: 图片计数
INPUT: void
RETURN: int
***********************************************/
int fileCount()
{
    int res = 0;
    struct ffblk dir;
    if (!findfirst("temp/*.bmp", &dir, 0)) //找到返回值为0
    {
        res = 1;
        while (!findnext(&dir)) //找到返回值为0
        {
            res++;
        }
    }
    return res;
}
/*********************************************
FUNCTION: allFiles
DESCRIPTION: 寻找所有图片
INPUT: fileNames maxN
RETURN: int
***********************************************/
int allFiles(char fileNames[][20],int maxN)
{
    int i = 0;
    struct ffblk dir;
    if (!findfirst("temp\\*.bmp", &dir, 0)) //找到返回值为0
    {
        i = 1;
        strcpy(fileNames[i - 1],dir.ff_name);
        while (!findnext(&dir) && i < maxN) //找到返回值为0
        {
            i++;
            strcpy(fileNames[i - 1],dir.ff_name);
        }
    }
    return i;
}
/*********************************************
FUNCTION: cleanTempFiles
DESCRIPTION: 去除所有临时文件
INPUT: void
RETURN: void
***********************************************/
void cleanTempFiles()
{
    struct ffblk dir;
    char t[20] = "temp\\";
    if (!findfirst("temp\\*.TMP", &dir, 0)) //找到返回值为0
    {
        strcat(t,dir.ff_name);
        remove(t);
        strcpy(t,"temp\\");
        while (!findnext(&dir)) //找到返回值为0
        {
            strcat(t,dir.ff_name);
            remove(t);
            strcpy(t,"temp\\");
        }
    }
}
/*********************************************
FUNCTION: previewFile
DESCRIPTION: 生成预览图
INPUT: image x y
RETURN: 布尔值，是否成功
***********************************************/
int previewFile(Image *image,int x,int y)
{
    #define getcacheRed(i,j) (((getPixelFromCache(fp,(i),(j),h0)) >> 16) / 255.0)
    #define getcacheGreen(i,j) (((getPixelFromCache(fp,(i),(j),h0) >> 8) & 0xff) / 255.0)
    #define getcacheBlue(i,j) (((getPixelFromCache(fp,(i),(j),h0)) & 0xff) / 255.0)
    int i, j;
    int h, w, h0, w0;
    double scaleX,scaleY;
    double srcX, srcY, value1, value0;
    int srcX0, srcY0, srcX1, srcY1;
    double resR, resG, resB;
    u32 color;
    FILE *fp;
    if ((fp = fopen(image->cachePath, "rb")) == 0)
        return 0;
    h0 = image->height, w0 = image->width;
    scaleX = 200.0 / w0;
    scaleY = 150.0 / h0;
    scaleX = scaleY = min(scaleX,scaleY);
    h = h0 * scaleY, w = w0 * scaleX;
    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            srcX = (i + 0.5) / scaleX - 0.5;
            srcY = (j + 0.5) / scaleY - 0.5;
            srcX0 = (int)srcX;
            srcY0 = (int)srcY;
            srcX1 = min(srcX0 + 1, w0);
            srcY1 = min(srcY0 + 1, h0);
            value0 = (srcX1 - srcX) * getcacheRed(srcX0, srcY0) + (srcX - srcX0) * getcacheRed(srcX1, srcY0);
            value1 = (srcX1 - srcX) * getcacheRed(srcX0, srcY1) + (srcX - srcX0) * getcacheRed(srcX1, srcY1);
            resR = (srcY1 - srcY) * value0 + (srcY - srcY0) * value1;

            value0 = (srcX1 - srcX) * getcacheGreen(srcX0, srcY0) + (srcX - srcX0) * getcacheGreen(srcX1, srcY0);
            value1 = (srcX1 - srcX) * getcacheGreen(srcX0, srcY1) + (srcX - srcX0) * getcacheGreen(srcX1, srcY1);
            resG = (srcY1 - srcY) * value0 + (srcY - srcY0) * value1;

            value0 = (srcX1 - srcX) * getcacheBlue(srcX0, srcY0) + (srcX - srcX0) * getcacheBlue(srcX1, srcY0);
            value1 = (srcX1 - srcX) * getcacheBlue(srcX0, srcY1) + (srcX - srcX0) * getcacheBlue(srcX1, srcY1);
            resB = (srcY1 - srcY) * value0 + (srcY - srcY0) * value1;
            resR = max(resR, 0), resB = max(resB, 0), resG = max(resG, 0);
            resR = min(resR, 1), resB = min(resB, 1), resG = min(resG, 1);
            color = rgb2u32(resR * 255, resG * 255, resB * 255);
            putPixel(x + i,y + j,color);
        }
    }
    fclose(fp);
    return 1;
    #undef getcacheRed
    #undef getcacheGreen
    #undef getcacheBlue
}

/*********************************************
FUNCTION: fileInfoShow
DESCRIPTION: 展示预览图
INPUT: dir x y
RETURN: void
***********************************************/
void fileInfoShow(struct ffblk dir,int x,int y)
{
    char name[18];
    char data[12],time[12];
    int year,month,day,hour,min,sec;
	char cSize[12];
    unsigned long int size;
    bar(x,y,x + 130,y + 100,BLUE);
    year = ((dir.ff_fdate & 0xFE00) >> 9) + 1980;	//注意优先级
	month = (dir.ff_fdate & 0x1E0) >> 5;
	day = dir.ff_fdate & 0x1F;
	hour = (dir.ff_ftime & 0xF800) >> 11;
	min = (dir.ff_ftime & 0x7E0) >> 5;
	sec = (dir.ff_ftime & 0x1F) * 2;
	size = dir.ff_fsize >> 10;

    sprintf(data, "%d.%d.%d", year, month, day);
	sprintf(time, "%d:%d:%d", hour, min, sec);
	sprintf(cSize, "%ldkB", size);
    strcpy(name, dir.ff_name);

	TextGB16(x, y + 20, 12, BLACK, name);
	TextGB16(x,y + 40, 12, BLACK, cSize);
	TextGB16(x, y + 60,12, BLACK, data);
	TextGB16(x, y + 80,12, BLACK, time); 
}
/*********************************************
FUNCTION: findFile
DESCRIPTION: 找到文件信息
INPUT: n dir
RETURN: 布尔值，是否成功
***********************************************/
int findFile(int n, struct ffblk *dir)
{
	int i = 0;
	if (!findfirst("temp/*.bmp", dir, 0))	//找到返回值为0
	{
		for (; i < n; i++)
		{
			if (!findnext(dir))	//找到返回值为0
			{
				;
			}
			else
			{
				//已经没有文件了
				dir->ff_name[0] = '\0';
				return 0;
			}
		}
		return 1;
	}
	return 0;
}