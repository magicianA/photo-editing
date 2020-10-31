#ifndef FILES_H
#define FILES_H

#include<io.h>
#include<dir.h>
#include<string.h>
#include"image.h"
#include"text.h"


int fileCount();
int allFiles(char fileNames[][20],int maxN);
void cleanTempFiles();
int previewFile(Image *image,int x,int y);
int findFile(int n, struct ffblk *dir);
void fileInfoShow(struct ffblk dir,int x,int y);

#endif

