#include "coll.h"

void stackInit(Stack *stack)
{
    stack->tot = 0;
    stack->base = -1;
    //stack->curtop = 0;
    strcpy(stack->path, "temp\\");
}

void stackPush(Stack *stack, Image *image)
{
    FILE *fp1, *fp2;
    u32 buffer;
    ImageData imageData;
    char dest[20], t[20], s[20];
    strcpy(s, image->cachePath);
    strcpy(dest, stack->path);
    imageData = image2ImageData(image);
    (stack->tot)++;
    //stack->curtop = stack->tot;
    if (stack->tot > IMAGE_STACK_MAX_SIZE)
    {
        (stack->tot)--;
        stack->base = (stack->base + 1) % IMAGE_STACK_MAX_SIZE;
    }
    stack->stackData[(stack->base + stack->tot) % (IMAGE_STACK_MAX_SIZE)] = imageData;
    sprintf(t, "%d", (stack->tot + stack->base) % IMAGE_STACK_MAX_SIZE);
    strcat(t, ".tmp");
    strcat(dest, t);
    fp1 = fopen(s, "rb");
    fp2 = fopen(dest, "wb");
    while (!feof(fp1))
    {
        fread(&buffer, 4, 1, fp1);
        fwrite(&buffer, 4, 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

int stackPop(Stack *stack, Image *image)
{
    FILE *fp1, *fp2;
    u32 buffer;
    int i, j;
    int x, y;
    int height, width;
    ImageData imageData;
    char path[20], dest[20], t[20];
    if (stack->tot == 0)
    {
        return 0;
    }
    strcpy(dest, stack->path);
    strcpy(path, image->cachePath);
    sprintf(t, "%d", (stack->tot + stack->base) % IMAGE_STACK_MAX_SIZE);
    strcat(t, ".tmp");
    strcat(dest, t);
    x = image->x;
    y = image->y;
    width = image->width;
    height = image->height;
    imageData = stack->stackData[(stack->base + stack->tot) % (IMAGE_STACK_MAX_SIZE)];
    (stack->tot)--;
    if (x != imageData.x || y != imageData.y || width != imageData.width || height != imageData.height)
    {
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                putPixel(x + i, y + j, WHITE);
            }
        }
    }
    x = imageData.x;
    y = imageData.y;
    width = imageData.width;
    height = imageData.height;
    image->x = x;
    image->y = y;
    image->width = width;
    image->height = height;
    strcpy(image->cachePath, dest);
    putImage(image, -1, -1);
    strcpy(image->cachePath, path);
    fp1 = fopen(dest, "rb");
    fp2 = fopen(path, "wb");
    while (!feof(fp1))
    {
        fread(&buffer, 4, 1, fp1);
        fwrite(&buffer, 4, 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 1;
}


char* lowerCase(char *s){
    char *t = s;
    while(*s != '\0'){
        if(*s >= 'A' && *s <= 'Z'){
            *s += 'a' - 'A';
        }
        s++;
    }
    return t;
}