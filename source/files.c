#include "files.h"



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