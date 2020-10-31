#ifndef FILES_H
#define FILES_H

#include<io.h>
#include<dir.h>
#include<string.h>
#include"image.h"


int fileCount();
int allFiles(char fileNames[][20],int maxN);
void cleanTempFiles();
void previewFile(Image *image,int x,int y);

#endif

