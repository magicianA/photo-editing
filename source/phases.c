#include "phases.h"

/*********************************************
FUNCTION: cutPhase
DESCRIPTION: �и�׶�
INPUT: image stack
RETURN: void
***********************************************/
void cutPhase(Image *image, Stack *stack)
{
    int flag = 0;
    Mouse mouseOld, mouseNew, mouse1, mouse2;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "��ѡ���1");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseNew.button == 1)
            {
                if (flag)
                {
                    mouse2 = mouseNew;
                    mousePutBk(mouseNew.x, mouseNew.y);
                    if (!cut(image, mouse1.x, mouse2.x, mouse1.y, mouse2.y, WHITE))
                    {
                        stackPop(stack, image);
                        msgPhase(20, 20, "�и�ʧ��");
                    }
                    bar(200, 571, 500, 600, GRAY);
                    break;
                }
                else
                {
                    mouse1 = mouseNew;
                    flag = 1;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���2");
                }
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: linePhase
DESCRIPTION: ���߽׶�
INPUT: image color stack
RETURN: void
***********************************************/
void linePhase(Image *image, u32 color, Stack *stack)
{
    int flag = 0;
    Mouse mouseOld, mouseNew, mouse1, mouse2;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "��ѡ���1");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseNew.button == 1)
            {
                if (flag)
                {
                    mouse2 = mouseNew;
                    mousePutBk(mouseNew.x, mouseNew.y);
                    if (!drawLine(image, mouse1.x, mouse2.x, mouse1.y, mouse2.y, color))
                    {
                        stackPop(stack, image);
                        msgPhase(20, 20, "����ʧ��");
                    }
                    bar(200, 571, 500, 600, GRAY);
                    break;
                }
                else
                {
                    mouse1 = mouseNew;
                    flag = 1;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���2");
                }
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: emptyBarPhase
DESCRIPTION: �����ľ��ν׶�
INPUT: image color stack
RETURN: void
***********************************************/
void emptyBarPhase(Image *image, u32 color, Stack *stack)
{
    int flag = 0;
    Mouse mouseOld, mouseNew, mouse1, mouse2;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "��ѡ���1");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseNew.button == 1)
            {
                if (flag)
                {
                    mouse2 = mouseNew;
                    mousePutBk(mouseNew.x, mouseNew.y);
                    if (!drawBarEmpty(image, mouse1.x, mouse2.x, mouse1.y, mouse2.y, color))
                    {
                        stackPop(stack, image);
                        msgPhase(20, 20, "����ʧ��");
                    }
                    bar(200, 571, 500, 600, GRAY);
                    break;
                }
                else
                {
                    mouse1 = mouseNew;
                    flag = 1;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���2");
                }
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: filledBarPhase
DESCRIPTION: ��ʵ�ľ��ν׶�
INPUT: image color stack
RETURN: void
***********************************************/
void filledBarPhase(Image *image, u32 color, Stack *stack)
{
    int flag = 0;
    Mouse mouseOld, mouseNew, mouse1, mouse2;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "��ѡ���1");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseNew.button == 1)
            {
                if (flag)
                {
                    mouse2 = mouseNew;
                    mousePutBk(mouseNew.x, mouseNew.y);

                    if (!drawBarFilled(image, mouse1.x, mouse2.x, mouse1.y, mouse2.y, color))
                    {
                        stackPop(stack, image);
                        msgPhase(20, 20, "����ʧ��");
                    }
                    bar(200, 571, 500, 600, GRAY);
                    break;
                }
                else
                {
                    mouse1 = mouseNew;
                    flag = 1;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���2");
                }
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: trianglePhase
DESCRIPTION: �������ν׶�
INPUT: image color stack
RETURN: void
***********************************************/
void trianglePhase(Image *image, u32 color, Stack *stack)
{
    int flag = 0;
    Mouse mouseOld, mouseNew, mouse1, mouse2, mouse3;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "��ѡ���1");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseNew.button == 1)
            {
                if (flag == 2)
                {
                    mouse3 = mouseNew;
                    mousePutBk(mouseNew.x, mouseNew.y);
                    if (!drawTriangle(image, mouse1.x, mouse2.x, mouse3.x, mouse1.y, mouse2.y, mouse3.y, color))
                    {
                        stackPop(stack, image);
                        msgPhase(20, 20, "����ʧ��");
                    }
                    bar(200, 571, 500, 600, GRAY);
                    break;
                }
                else if (flag == 1)
                {
                    mouse2 = mouseNew;
                    flag++;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���3");
                }
                else
                {
                    mouse1 = mouseNew;
                    flag++;
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "��ѡ���2");
                }
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: testPhase
DESCRIPTION: ���Խ׶�
INPUT: void
RETURN: void
***********************************************/
void testPhase()
{
    Image image = {0};
    Mouse mouseOld, mouseNew;
    bar(0, 0, SCR_WIDTH, SCR_HEIGHT, TIANYILAN);
    mouseReset();
    BMPcache(&image,"temp\\timg.bmp");
    //readBMP(&image, "temp\\timg.bmp", 0, 0, 0);
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    bar(300, 300, 300 + 32, 300 + 32, PINK);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(300, 300, 332, 332))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                previewFile(&image,0,0);
                //putImage(&image,0,0);
                getch();
                TextGB32(0,0,10,BLACK,"���");
                getch();
                break;
            }
            mouseOld = mouseNew;
        }
    }
}
/*********************************************
FUNCTION: msgPhase
DESCRIPTION: ��ʾ��׶�
INPUT: x y s
RETURN: void
***********************************************/
void msgPhase(int x, int y, char *s)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    int i, j;
    bg.x = x, bg.y = y, bg.height = 200 + 20, bg.width = 300 + 20;
    strcpy(bg.cachePath, "temp\\msgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 100, y + 165, x + 200 - 1, y + 195 - 1, RED);
    TextGB64(x + 100, y, 50, WHITE, "��ʾ", 0);
    TextGB32(x + 110, y + 165, 40, WHITE, "ȷ��");
    TextGB32(x + 10, y + 100, 40, BLACK, s);
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 100, y + 165, x + 200, y + 195))
            {
                break;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: fliterPhase
DESCRIPTION: �˾��׶�
INPUT: image stack
RETURN: void
***********************************************/
void fliterPhase(Image *image, Stack *stack)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    char fliterNames[20][20];
    void (*filterFunc[20])(Image *) = {&old, &reverse, &gray, &sharpen, &blur, &curve, &movingBlur, &unsharpen, &melt, &cartoon, &extreme, &singleRed, &singleGreen, &singleBlue, &laplace,&girl};
    int curfilter = -1, curPage = 0;
    int filtercount = 16;
    int i, j, x, y;
    char s[10];
    bg.x = 300, bg.y = 150, bg.height = 250 + 20, bg.width = 300 + 20;
    x = 300, y = 150;
    strcpy(fliterNames[0], "����");
    strcpy(fliterNames[1], "��ɫ");
    strcpy(fliterNames[2], "�Ҷ�");
    strcpy(fliterNames[3], "��");
    strcpy(fliterNames[4], "ģ��");
    strcpy(fliterNames[5], "����");
    strcpy(fliterNames[6], "�˶�ģ��");
    strcpy(fliterNames[7], "ȥģ��");
    strcpy(fliterNames[8], "����");
    strcpy(fliterNames[9], "������");
    strcpy(fliterNames[10], "�ڰ�");
    strcpy(fliterNames[11], "�ɺ�");
    strcpy(fliterNames[12], "����");
    strcpy(fliterNames[13], "ε��");
    strcpy(fliterNames[14], "��Ե���");
    strcpy(fliterNames[15],"��Ů");
    strcpy(fliterNames[16],"��");
    strcpy(fliterNames[17],"��");
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 250 - 1, BLUE);
    bar(x + 100, y + 215, x + 220 - 1, y + 245 - 1, TIANYILAN);
    putUI("ui\\up.bmp", x + 230, y + 60, -1);
    putUI("ui\\down.bmp", x + 230, y + 110, -1);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 100, y, 50, WHITE, "�˾�", 0);
    TextGB32(x + 110, y + 215, 40, WHITE, "ȷ��");
    bar(x + 10, y + 70, x + 220, y + 100, PINK);
    TextGB32(x + 10, y + 70, 30, WHITE, fliterNames[0]);

    bar(x + 10, y + 110, x + 220, y + 140, PINK);
    TextGB32(x + 10, y + 110, 30, WHITE, fliterNames[1]);

    bar(x + 10, y + 150, x + 220, y + 180, PINK);
    TextGB32(x + 10, y + 150, 30, WHITE, fliterNames[2]);

    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 230, y + 60, x + 270, y + 100))
            {
                if (curPage > 0)
                {
                    curPage--;
                    bar(x + 10, y + 70, x + 220, y + 100, PINK);
                    TextGB32(x + 10, y + 70, 30, WHITE, fliterNames[0 + curPage * 3]);
                    bar(x + 10, y + 110, x + 220, y + 140, PINK);
                    TextGB32(x + 10, y + 110, 30, WHITE, fliterNames[1 + curPage * 3]);
                    bar(x + 10, y + 150, x + 220, y + 180, PINK);
                    TextGB32(x + 10, y + 150, 30, WHITE, fliterNames[2 + curPage * 3]);
                    delay(100);
                }
            }
            if (mouseDown(x + 230, y + 110, x + 270, y + 150))
            {
                if (curPage < filtercount / 3)
                {
                    curPage++;
                    bar(x + 10, y + 70, x + 220, y + 100, PINK);
                    TextGB32(x + 10, y + 70, 30, WHITE, fliterNames[0 + curPage * 3]);
                    bar(x + 10, y + 110, x + 220, y + 140, PINK);
                    TextGB32(x + 10, y + 110, 30, WHITE, fliterNames[1 + curPage * 3]);
                    bar(x + 10, y + 150, x + 220, y + 180, PINK);
                    TextGB32(x + 10, y + 150, 30, WHITE, fliterNames[2 + curPage * 3]);
                    delay(100);
                }
            }
            if (mouseDown(x + 10, y + 70, x + 220, y + 100))
            {
                curfilter = 0 + curPage * 3;
                if (curfilter >= filtercount)
                {
                    curfilter = -1;
                }
            }
            if (mouseDown(x + 10, y + 110, x + 220, y + 140))
            {
                curfilter = 1 + curPage * 3;
                if (curfilter >= filtercount)
                {
                    curfilter = -1;
                }
            }
            if (mouseDown(x + 10, y + 150, x + 220, y + 180))
            {
                curfilter = 2 + curPage * 3;
                if (curfilter >= filtercount)
                {
                    curfilter = -1;
                }
            }
            if (mouseDown(x + 100, y + 215, x + 220, y + 245))
            {
                if (curfilter != -1)
                {
                    putImage(&bg, x, y);
                    bar(200, 571, 500, 600, GRAY);
                    TextGB16(200, 571, 15, WHITE, "�����У����Ժ�");
                    stackPush(stack, image);
                    filterFunc[curfilter](image);
                    bar(200, 571, 500, 600, GRAY);
                    return;
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(0, 0, "��ѡ���˾�");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: adjustPhase
DESCRIPTION: ���ڽ׶�
INPUT: image stack
RETURN: void
***********************************************/
void adjustPhase(Image *image, Stack *stack)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    int i, j, x, y;
    int deltas = 0, deltal = 0;
    char s[10];
    bg.x = 300;
    bg.y = 150;
    bg.height = 230 + 20;
    bg.width = 300 + 20;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 230 - 1, BLUE);
    bar(x + 100, y + 195, x + 200 - 1, y + 225 - 1, TIANYILAN);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 100, y, 50, WHITE, "����", 0);
    TextGB32(x + 10, y + 55, 30, BLACK, "���Ͷ�");
    TextGB32(x + 10, y + 120, 30, BLACK, "����");
    TextGB32(x + 110, y + 195, 40, WHITE, "ȷ��");
    line(x + 50, y + 100, x + 250, y + 100, WHITE);
    line(x + 50, y + 165, x + 250, y + 165, WHITE);
    //bar(x+145,y+95,x+155,y+105,RED);
    //bar(x+145,y+160,x+155,y+170,RED);
    TextGB16(x + 260, y + 100, 10, WHITE, "0");
    TextGB16(x + 260, y + 165, 10, WHITE, "0");
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 50, y + 90, x + 250, y + 110))
            {
                line(x + 50, y + 100, x + 250, y + 100, WHITE);
                deltas = mouseNew.x - (x + 150);
                sprintf(s, "%d", deltas);
                bar(x + 260, y + 100, x + 290, y + 115, BLUE);
                TextGB16(x + 260, y + 100, 10, WHITE, s);
            }
            if (mouseDown(x + 50, y + 155, x + 250, y + 175))
            {
                line(x + 50, y + 165, x + 250, y + 165, WHITE);
                deltal = mouseNew.x - (x + 150);
                sprintf(s, "%d", deltal);
                bar(x + 260, y + 165, x + 290, y + 180, BLUE);
                TextGB16(x + 260, y + 165, 10, WHITE, s);
            }
            if (mouseDown(x + 100, y + 195, x + 200, y + 225))
            {
                putImage(&bg, x, y);
                stackPush(stack, image);
                bar(200, 571, 500, 600, GRAY);
                TextGB16(200, 571, 15, WHITE, "�������Ͷ��У����Ժ�");
                addSaturation(image, deltas / 200.0);
                bar(200, 571, 500, 600, GRAY);
                TextGB16(200, 571, 15, WHITE, "���������У����Ժ�");
                addBrightness(image, deltal / 200.0);
                bar(200, 571, 500, 600, GRAY);
                return;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: mainPhase
DESCRIPTION: ���׶�
INPUT: void
RETURN: void
***********************************************/
void mainPhase()
{
    Image image = {0};
    Mouse mouseOld, mouseNew;
    u32 curColor = BLACK;
    int curblock = 0,oldblock = 0;
    Stack stack;
    int curPage = 0;
    stackInit(&stack);
    bar(0, 0, SCR_WIDTH, SCR_HEIGHT, WHITE);
    bar(0, 0, 64, 570, TIANYILAN);
    bar(0, 0, 800, 64, TIANYILAN);
    bar(0, 571, 800, 600, GRAY);
    putUI("ui\\icon.bmp", 0, 0, -1);
    putUI("ui\\spin.bmp", 0, 64, -1);
    putUI("ui\\cut.bmp", 0, 128, -1);
    putUI("ui\\rgb.bmp", 0, 192, -1);
    putUI("ui\\folder.bmp", 3 + 64, 0, -1);
    putUI("ui\\save.bmp", 3 + 128, 0, -1);
    putUI("ui\\close.bmp", 800 - 64, 0, -1);
    putUI("ui\\adjust.bmp", 0, 256, -1);
    putUI("ui\\reflect.bmp", 0, 320, -1);
    putUI("ui\\resize.bmp", 0, 384 + 5, -1);
    putUI("ui\\brush.bmp", 0, 448 + 10, -1);
    putUI("ui\\new.bmp", 3 + 192, 0, -1);
    putUI("ui\\file.bmp", 3 + 256, 0, -1);
    putUI("ui\\undo.bmp", 3 + 320, 0, -1);
    putUI("ui\\spf.bmp", 3 + 384, 0, -1);
    mouseReset();

    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);

            oldblock = curblock;
            if (mouseIn(mouseNew, 800 - 64, 0, 800, 64))
            {
                curblock = 1;
            }
            else if (mouseIn(mouseNew, 0, 0, 64, 64))
            {
                curblock = 2;
            }
            else if (mouseIn(mouseNew, 3 + 64, 0, 3 + 128, 64))
            {
                curblock = 3;
            }
            else if (mouseIn(mouseNew, 0, 64, 64, 128))
            {
                if (curPage == 0)
                {
                    curblock = 4;
                }
                else if (curPage == 1)
                {
                    curblock = 5;
                }
            }
            else if (mouseIn(mouseNew, 0, 128, 64, 192))
            {
                if (curPage == 0)
                {
                    curblock = 6;
                }
                else if (curPage == 1)
                {
                    curblock = 7;
                }
            }
            else if (mouseIn(mouseNew, 3 + 128, 0, 3 + 192, 64))
            {
                curblock = 8;
            }
            else if (mouseIn(mouseNew, 0, 192, 64, 256))
            {
                if (curPage == 0)
                {
                    curblock = 9;
                }
                else if (curPage == 1)
                {
                    curblock = 10;
                }
            }
            else if (mouseIn(mouseNew, 0, 320, 64, 384))
            {
                if (curPage == 0)
                {
                    curblock = 11;
                }
                else if (curPage == 1)
                {
                    curblock = 12;
                }
            }
            else if (mouseIn(mouseNew, 0, 256, 64, 320))
            {
                if (curPage == 0)
                {
                    curblock = 13;
                }
                else if (curPage == 1)
                {
                    curblock = 14;
                }
            }
            else if (mouseIn(mouseNew, 0, 384 + 5, 64, 448 + 5))
            {
                if (curPage == 0)
                {
                    curblock = 15;
                }
                else if (curPage == 1)
                {
                    curblock = 16;
                }
            }
            else if (mouseIn(mouseNew, 3 + 192, 0, 256, 64))
            {
                curblock = 17;
            }
            else if (mouseIn(mouseNew, 3 + 256, 0, 3 + 320, 64))
            {
                curblock = 18;
            }
            else if (mouseIn(mouseNew, 0, 448 + 10, 64, 512 + 10))
            {
                if (curPage == 0)
                {
                    curblock = 19;
                }
                else if (curPage == 1)
                {
                    curblock = 20;
                }
            }
            else if (mouseIn(mouseNew, 3 + 320, 0, 3 + 384, 64))
            {
                curblock = 21;
            }
            else if (mouseIn(mouseNew, 3 + 384, 0, 3 + 448, 64))
            {
                curblock = 22;
            }
            else{
                curblock = 0;
            }
            if(curblock != oldblock){
                bar(200, 571, 500, 600, GRAY);
                switch (curblock)
                {
                    case 1:
                        TextGB16(200, 571, 15, WHITE, "�رճ���");
                    break;
                    case 2:
                        TextGB16(200, 571, 15, WHITE, "���ڳ���");
                    break;                    
                    case 3:
                        TextGB16(200, 571, 15, WHITE, "��ͼƬ");
                    break;                    
                    case 4:
                        TextGB16(200, 571, 15, WHITE, "��ת");
                    break;                    
                    case 5:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                    
                    case 6:
                        TextGB16(200, 571, 15, WHITE, "�и�");
                    break;                    
                    case 7:
                        TextGB16(200, 571, 15, WHITE, "��������");
                    break;                    
                    case 8:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                    
                    case 9:
                        TextGB16(200, 571, 15, WHITE, "�˾�");
                    break;                    
                    case 10:
                        TextGB16(200, 571, 15, WHITE, "�����ľ���");
                    break;                    
                    case 11:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                    
                    case 12:
                        TextGB16(200, 571, 15, WHITE, "���ɻ���");
                    break;                    
                    case 13:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                    
                    case 14:
                        TextGB16(200, 571, 15, WHITE, "��ʵ�ľ���");
                    break;
                    case 15:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                
                    case 16:
                        TextGB16(200, 571, 15, WHITE, "ѡ����ɫ");
                    break;                
                    case 17:
                        TextGB16(200, 571, 15, WHITE, "�½�ͼƬ");
                    break;                
                    case 18:
                        TextGB16(200, 571, 15, WHITE, "�ر�ͼƬ");
                    break;                
                    case 19:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                
                    case 20:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;                
                    case 21:
                        TextGB16(200, 571, 15, WHITE, "����");
                    break;         
                    case 22:
                        TextGB16(200, 571, 15, WHITE, "ͼƬ����");
                    break;                      
                    default:
                        break;
                }
            }
            if (mouseDown(800 - 64, 0, 800, 64))
            {
                break;
            }
            if (mouseDown(0, 0, 64, 64))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                copyleftPhase();
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(3 + 64, 0, 3 + 128, 64))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                openPhase(&image);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(0, 64, 64, 128))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        if (image.height < BMP_WIDTH_MAX && image.width < BMP_HEIGTH_MAX)
                        {
                            stackPush(&stack, &image);
                            spin(&image, WHITE);
                        }
                        else
                        {
                            mousePutBk(mouseNew.x, mouseNew.y);
                            msgPhase(200, 200, "��תʧ��");
                            mouseStoreBk(mouseNew.x, mouseNew.y);
                        }
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        linePhase(&image, curColor, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(0, 128, 64, 192))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        cutPhase(&image, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        trianglePhase(&image, curColor, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(3 + 128, 0, 3 + 192, 64))
            {
                if (image.height != 0)
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    savePhase(&image);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    //saveBMP(image.x,image.y,image.x + image.width,image.y + image.height,"temp\\result.bmp");
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(200, 200, "δ��ͼƬ");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            if (mouseDown(0, 192, 64, 256))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        fliterPhase(&image, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        emptyBarPhase(&image, curColor, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(0, 320, 64, 384))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        stackPush(&stack, &image);
                        mirror(&image);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        delay(20);
                        drawFreePhase(&image, curColor, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(0, 256, 64, 320))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        adjustPhase(&image, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        filledBarPhase(&image, curColor, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(0, 384 + 5, 64, 448 + 5))
            {
                if (curPage == 0)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        zoomPhase(&image, &stack);
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else if (curPage == 1)
                {
                    if (image.height != 0)
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        curColor = colorPhase();
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                    else
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "δ��ͼƬ");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
            }
            if (mouseDown(3 + 192, 0, 256, 64))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                newPhase(&image);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(3 + 256, 0, 3 + 320, 64))
            {
                if (image.height != 0)
                {
                    stackInit(&stack);
                    closeImage(&image);
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(200, 200, "δ��ͼƬ");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
                delay(200);
            }
            if (mouseDown(0, 448 + 10, 64, 512 + 10))
            {
                if (curPage == 0)
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    curPage++;
                    bar(0, 64, 64, 570, TIANYILAN);
                    putUI("ui\\line.bmp", 0, 64, -1);
                    putUI("ui\\triangle.bmp", 0, 128, -1);
                    putUI("ui\\rect.bmp", 0, 192, -1);
                    putUI("ui\\bar.bmp", 0, 256, -1);
                    putUI("ui\\pbrush.bmp", 0, 320, -1);
                    putUI("ui\\color.bmp", 0, 384 + 5, -1);
                    putUI("ui\\return.bmp", 0, 448 + 10, -1);
                    delay(100);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
                else if (curPage == 1)
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    curPage--;
                    bar(0, 64, 64, 570, TIANYILAN);
                    putUI("ui\\spin.bmp", 0, 64, -1);
                    putUI("ui\\cut.bmp", 0, 128, -1);
                    putUI("ui\\rgb.bmp", 0, 192, -1);
                    putUI("ui\\adjust.bmp", 0, 256, -1);
                    putUI("ui\\reflect.bmp", 0, 320, -1);
                    putUI("ui\\resize.bmp", 0, 384 + 5, -1);
                    putUI("ui\\brush.bmp", 0, 448 + 10, -1);
                    delay(100);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            if (mouseDown(3 + 320, 0, 3 + 384, 64))
            {
                if (image.height != 0)
                {
                    if (!stackPop(&stack, &image))
                    {
                        mousePutBk(mouseNew.x, mouseNew.y);
                        msgPhase(200, 200, "����ʧ��");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                    }
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(200, 200, "δ��ͼƬ");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            if (mouseDown(3 + 384, 0, 3 + 448, 64))
            {
                if (image.height == 0)
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    fileListPhase(&image);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(200, 200, "�Ѵ�ͼƬ");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            mouseOld = mouseNew;
        }
    }
    cleanTempFiles();
    //remove("temp\\bgpic.tmp");
    //remove("temp\\msgbgpic.tmp");
    if (image.height != 0)
    {
        remove(image.cachePath);
    }
}
/*********************************************
FUNCTION: openPhase
DESCRIPTION: �򿪽׶�
INPUT: image
RETURN: void
***********************************************/
void openPhase(Image *image)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    int i, j, x, y;
    char s[25] = "temp\\";
    char fileName[15] = "sunset.bmp";
    if (image->height != 0)
    {
        msgPhase(200, 200, "���Ѵ�ͼƬ");
        return;
    }
    bg.x = 300, bg.y = 150, bg.height = 230 + 40, bg.width = 300 + 40;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 230 - 1, BLUE);
    bar(x + 100, y + 195, x + 200 - 1, y + 225 - 1, TIANYILAN);
    bar(x + 40, y + 90, x + 250 - 1, y + 140 - 1, WHITE);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "��ͼƬ", 0);
    TextGB32(x + 110, y + 195, 40, WHITE, "ȷ��");
    TextASC24(340, 240, 14, 0, fileName);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 40, y + 90, x + 250, y + 140))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                inputPhase(fileName, 1, 0, 0);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(x + 100, y + 195, x + 200, y + 225))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                putImage(&bg, x, y);
                strcat(s, fileName);
                if (readBMP(image, s, 300, 200, 1) == 1)
                    return;
                else
                {
                    image->x = image->y = image->height = image->width = 0;
                    strcpy(image->cachePath, "");
                    strcpy(s, "temp\\");
                    msgPhase(200, 200, "��ʧ��");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    break;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: goodbyePhase
DESCRIPTION: �ټ��׶�
INPUT: void
RETURN: void
***********************************************/
void goodbyePhase()
{
    putUI("ui\\gb.bmp", 0, 0, -1);
    //showGoodbyeImage();
    TextGB64(0, 0, 50, WHITE, "���ף�����彡�����ټ�", 5);
    TextASC128(300, 400, 70, WHITE, "GOODBYE", 5);
    delay(1000);
}
/*********************************************
FUNCTION: inputPhase
DESCRIPTION: ����׶�
INPUT: filename flag(1=����ȫ�ַ����� 0=ֻ������������) dx dy
RETURN: int
***********************************************/
int inputPhase(char *filename, int flag, int dx, int dy)
{
    unsigned int key;
    unsigned int len = strlen(filename);
    while ((key = bioskey(0)) != Enter)
    {
        if (key == Backspace)
        {
            if (len > 0)
            {
                len--;
                filename[len] = '\0';
                bar(340 + dx, 240 + dy, 550 - 1 + dx, 280 - 1 + dy, WHITE);
                TextASC24(340 + dx, 240 + dy, 14, 0, filename);
            }
        }
        else if (key == Enter)
        {
            return 1;
        }
        else if ((key & 0xff) != 0 && len < 13)
        {
            if (flag == 1)
            {
                filename[len] = key & 0xff;
                filename[len + 1] = '\0';
                len++;
                TextASC24(340 + dx, 240 + dy, 14, 0, filename);
            }
            else
            {
                if ((key & 0xff) >= '0' && (key & 0xff) <= '9' && len < 10)
                {
                    filename[len] = key & 0xff;
                    filename[len + 1] = '\0';
                    len++;
                    TextASC24(340 + dx, 240 + dy, 14, 0, filename);
                }
            }
        }
    }
    return 0;
}
/*********************************************
FUNCTION: savePhase
DESCRIPTION: ����׶�
INPUT: image
RETURN: void
***********************************************/
void savePhase(Image *image)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    int i, j, x, y;
    char s[20] = "temp\\";
    char fileName[12] = "result.bmp";
    bg.x = 300;
    bg.y = 150;
    bg.height = 230 + 40;
    bg.width = 300 + 40;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 230 - 1, BLUE);
    bar(x + 100, y + 195, x + 200 - 1, y + 225 - 1, TIANYILAN);
    bar(x + 40, y + 90, x + 250 - 1, y + 140 - 1, WHITE);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "����ͼƬ", 0);
    TextGB32(x + 110, y + 195, 40, WHITE, "ȷ��");
    TextASC24(340, 240, 14, 0, fileName);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 40, y + 90, x + 250, y + 140))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                inputPhase(fileName, 1, 0, 0);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(x + 100, y + 195, x + 200, y + 225))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                putImage(&bg, x, y);
                strcat(s, fileName);
                if (saveBMP(image->x, image->y, image->x + image->width, image->y + image->height, s) == 1)
                {
                    //mousePutBk(mouseNew.x,mouseNew.y);
                    msgPhase(200, 200, "����ɹ�");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    delay(100);
                    return;
                }
                else
                {
                    strcpy(s, "temp\\");
                    msgPhase(200, 200, "����ʧ��");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    return;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: zoomPhase
DESCRIPTION: �����׶�
INPUT: image stack
RETURN: void
***********************************************/
void zoomPhase(Image *image, Stack *stack)
{
    Mouse mouseOld = {0}, mouseNew;
    Image bg;
    int i, j, x, y;
    double scaleX = 1, scaleY = 1;
    char s[10];
    bg.x = 300;
    bg.y = 150;
    bg.height = 230 + 20;
    bg.width = 300 + 20;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 230 - 1, BLUE);
    bar(x + 100, y + 195, x + 200 - 1, y + 225 - 1, TIANYILAN);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 100, y, 50, WHITE, "����", 0);
    TextGB32(x + 10, y + 55, 30, BLACK, "�����������");
    TextGB32(x + 10, y + 120, 30, BLACK, "�����������");
    TextGB32(x + 110, y + 195, 40, WHITE, "ȷ��");
    line(x + 50, y + 100, x + 250, y + 100, WHITE);
    line(x + 50, y + 165, x + 250, y + 165, WHITE);
    //bar(x+145,y+95,x+155,y+105,RED);
    //bar(x+145,y+160,x+155,y+170,RED);
    TextGB16(x + 260, y + 100, 10, WHITE, "1.0");
    TextGB16(x + 260, y + 165, 10, WHITE, "1.0");
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 50, y + 90, x + 250, y + 110))
            {
                line(x + 50, y + 100, x + 250, y + 100, WHITE);
                scaleX = (mouseNew.x - (x + 50)) / 200.0 * 1.5 + 0.5;
                scaleY = scaleX;
                sprintf(s, "%3.2f", scaleX);
                bar(x + 260, y + 100, x + 298, y + 115, BLUE);
                TextGB16(x + 260, y + 100, 10, WHITE, s);
                bar(x + 260, y + 165, x + 298, y + 180, BLUE);
                TextGB16(x + 260, y + 165, 10, WHITE, s);
            }
            if (mouseDown(x + 50, y + 155, x + 250, y + 175))
            {
                line(x + 50, y + 165, x + 250, y + 165, WHITE);
                scaleY = (mouseNew.x - (x + 50)) / 200.0 * 1.5 + 0.5;
                sprintf(s, "%3.2f", scaleY);
                bar(x + 260, y + 165, x + 298, y + 180, BLUE);
                TextGB16(x + 260, y + 165, 10, WHITE, s);
            }
            if (mouseDown(x + 100, y + 195, x + 200, y + 225))
            {
                putImage(&bg, x, y);
                bar(200, 571, 500, 600, GRAY);
                TextGB16(200, 571, 15, WHITE, "�����У����Ժ�");
                stackPush(stack, image);
                if (zoom(image, scaleX, scaleY) == 0)
                {
                    stackPop(stack, image);
                    msgPhase(200, 200, "����ʧ��");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
                bar(200, 571, 500, 600, GRAY);
                return;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: newPhase
DESCRIPTION: �½��׶�
INPUT: image
RETURN: void
***********************************************/
void newPhase(Image *image)
{
    Mouse mouseOld = {0}, mouseNew = {0};
    Image bg;
    int i, j, x, y;
    char sx[20] = "100", sy[20] = "100";
    int pWidth, pHeight;
    if (image->height != 0)
    {
        msgPhase(200, 200, "���Ѵ�ͼƬ");
        return;
    }
    bg.x = 300, bg.y = 150, bg.height = 280 + 40, bg.width = 300 + 40;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 280 - 1, BLUE);
    bar(x + 100, y + 245, x + 200 - 1, y + 275 - 1, TIANYILAN);
    bar(x + 40, y + 90, x + 250 - 1, y + 130 - 1, WHITE);
    bar(x + 40, y + 160, x + 250 - 1, y + 200 - 1, WHITE);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "�½�ͼƬ", 0);
    TextGB32(x + 110, y + 245, 40, WHITE, "ȷ��");
    TextGB16(x + 40, y + 70, 15, WHITE, "ͼƬ����");
    TextGB16(x + 40, y + 140, 15, WHITE, "ͼƬ���");
    TextASC24(340, 240, 14, 0, sx);
    TextASC24(340, 310, 14, 0, sy);
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 40, y + 90, x + 250, y + 130))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                inputPhase(sx, 2, 0, 0);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(x + 40, y + 160, x + 250, y + 200))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                inputPhase(sy, 2, 0, 70);
                mouseStoreBk(mouseNew.x, mouseNew.y);
            }
            if (mouseDown(x + 100, y + 245, x + 200, y + 275))
            {
                pWidth = pHeight = 0;
                pWidth = atoi(sx);
                pHeight = atoi(sy);
                if (pWidth >= BMP_WIDTH_MIN && pWidth <= BMP_WIDTH_MAX && pHeight >= BMP_HEIGTH_MIN && pHeight <= BMP_HEIGTH_MAX)
                {
                    image->x = 432 - pWidth / 2, image->y = 317 - pHeight / 2;
                    image->width = pWidth, image->height = pHeight;
                    mousePutBk(mouseNew.x, mouseNew.y);
                    putImage(&bg, x, y);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    strcpy(image->cachePath, "temp\\newpic.tmp");
                    for (i = 0; i < pWidth; i++)
                    {
                        for (j = 0; j < pHeight; j++)
                        {
                            putPixel(image->x + i, image->y + j, GRAY);
                        }
                    }
                    saveImageCache(image);
                    return;
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(200, 200, "ͼƬ��С������");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}
/*********************************************
FUNCTION: drawFreePhase
DESCRIPTION: ���ɻ��ʽ׶�
INPUT: image color stack
RETURN: void
***********************************************/
void drawFreePhase(Image *image, u32 color, Stack *stack)
{
    Mouse mouseOld, mouseNew;
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    stackPush(stack, image);
    bar(200, 571, 500, 600, GRAY);
    TextGB16(200, 571, 15, WHITE, "���ͼƬ�Կ�ʼ,��������ء�ͼ���˳�");
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(image->x, image->y, image->x + image->width - 1, image->y + image->height - 1))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                bar(200, 571, 500, 600, GRAY);
                drawFree(image, color);
                break;
            }
            if (mouseDown(0, 448 + 10, 64, 512 + 10))
            {
                mousePutBk(mouseNew.x, mouseNew.y);
                bar(200, 571, 500, 600, GRAY);
                break;
            }
        }
        mouseOld = mouseNew;
    }
    delay(100);
}
/*********************************************
FUNCTION: welcomePhase
DESCRIPTION: ��ӭ�׶�
INPUT: void
RETURN: void
***********************************************/
void welcomePhase()
{
    delay(1400);
    putUI("ui\\wel2.bmp", 0, 0, -1);
    TextGB64(100, 100, 45, BLACK, "�ֻ����˺���Ƭ��", 6);
    TextGB64(100, 150, 45, BLACK, "ȴ�Ҳ������õ���ͼ�����", 6);
    TextGB64(100, 250, 45, BLACK, "ϰ����", 6);
    TextASC64(240, 250, 40, BLACK, "DOS", 6);
    TextGB64(100, 300, 45, BLACK, "ϵͳ����ϰ�߸��µĲ���ϵͳ��", 6);
    TextGB64(100, 500, 40, BLACK, "���ڣ����õ��ģ�", 6);
    delay(1000);
    putUI("ui\\wel1.bmp", 0, 0, -1);
    delay(1000);
    TextGB64(300, 400, 45, BLACK, "�����������", 4);
    getch();
}
/*********************************************
FUNCTION: colorPhase
DESCRIPTION: ѡ����ɫ�׶�
INPUT: void
RETURN: u32
***********************************************/
u32 colorPhase()
{
    Mouse mouseOld = {0}, mouseNew = {0};
    Image bg;
    int i, j, x, y, x1, y1, x2;
    u32 colory = GRAY;
    HSL hsl = {200.0, 0.5, 0.5};
    int flag;
    RGB res;
    bg.x = 300, bg.y = 150, bg.height = 280 + 40, bg.width = 300 + 40;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\cbgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 280 - 1, BLUE);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "ѡ����ɫ", 0);
    colorBoard(x + 10, y + 65);
    colorBoardSide(x + 150, y + 65, x + 75, y + 170);
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 10, y + 65, x + 140, y + 275))
            {
                mouseStatus(&mouseNew);
                x1 = mouseNew.x, y1 = mouseNew.y;
                hsl = colorBoardSide(x + 150, y + 65, x1, y1);
            }
            if (mouseDown(x + 150, y + 65, x + 290, y + 115))
            {
                x2 = mouseNew.x - 450;
                hsl.l = 0 + x2 * 1.0 / 140;
                colory = RGB2u32(HSL2RGB(hsl));
                bar(x + 150, y + 175, x + 200, y + 220, colory);
                bar(x + 210, y + 175, x + 290, y + 220, TIANYILAN);
                TextGB32(x + 210, y + 175, 40, WHITE, "ȷ��");
                TextGB32(x + 150, y + 120, 35, BLACK, "��ǰ��ɫ");
                flag = 1;
            }
            if (mouseDown(x + 210, y + 175, x + 290, y + 220))
            {
                if (flag)
                {
                    putImage(&bg, x, y);
                    return colory;
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
    return BLACK;
}
/*********************************************
FUNCTION: copyleftPhase
DESCRIPTION: ���ڽ׶�
INPUT: void
RETURN: void
***********************************************/
void copyleftPhase()
{
    Mouse mouseOld = {0}, mouseNew = {0};
    Image bg;
    int i, j, x, y;
    bg.x = 300, bg.y = 150, bg.height = 280 + 40, bg.width = 300 + 40;
    x = 300, y = 150;
    strcpy(bg.cachePath, "temp\\bgpic.tmp");
    saveImageCache(&bg);
    bar(x + 0, y + 50, x + 300 - 1, y + 200 - 1, BLUE);
    bar(x + 0, y + 0, x + 300 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 250, y + 0, x + 300 - 1, y + 55 - 1, RED);
    bar(x + 0, y + 200, x + 300 - 1, y + 280 - 1, BLUE);
    bar(x + 100, y + 245, x + 200 - 1, y + 275 - 1, TIANYILAN);
    line(x + 250, y + 0, x + 300, y + 55, WHITE);
    line(x + 300, y + 0, x + 250, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "�������", 0);
    TextGB32(x + 110, y + 245, 40, WHITE, "ȷ��");
    TextGB32(x + 10, y + 60, 28, RED, "��Ƭ�༭�����ϵͳ");
    TextASC24(x + 240, y + 90, 10, RED, "v0.9");
    TextGB32(x + 10, y + 90, 28, BLACK, "��л��ʹ�ñ����");
    TextGB32(x + 10, y + 120, 28, BLACK, "ף��ʹ�����");
    TextGB32(x + 10, y + 150, 28, BLACK, "�������ѭ");
    TextASC24(x + 10, y + 180, 14, TIANYILAN, "MIT");
    TextGB32(x + 50, y + 180, 28, BLACK, "��ԴЭ��");
    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 250, y + 0, x + 300, y + 55))
            {
                break;
            }
            if (mouseDown(x + 100, y + 245, x + 200, y + 275))
            {
                break;
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}

/*********************************************
FUNCTION: fileListPhase
DESCRIPTION: ͼƬ����׶�
INPUT: image
RETURN: void
***********************************************/
void fileListPhase(Image *image)
{
    Mouse mouseOld, mouseNew;
    Image bg;
    char fileNames[20][20];
    int curfile = -1, curPage = 0;
    int filecount;
    int i, j, x, y;
    char s[20];
    bg.x = 200, bg.y = 100, bg.height = 350 + 20, bg.width = 450 + 20;
    x = 200, y = 100;
    
    filecount = fileCount();
    for (i = 0; i < 20; i++)
        strcpy(fileNames[i], "empty");
    allFiles(fileNames, 20);
    strcpy(bg.cachePath, "temp\\fbgpic.tmp");
    strcpy(s, "temp\\");
    saveImageCache(&bg);
    
    bar(x + 0, y + 50, x + 450 - 1, y + 350 - 1, BLUE);
    bar(x + 0, y + 0, x + 450 - 1, y + 55 - 1, TIANYILAN);
    bar(x + 400, y + 0, x + 450 - 1, y + 55 - 1, RED);
    bar(x + 230, y + 315, x + 340 - 1, y + 345 - 1, TIANYILAN);
    bar(x + 230,y + 270,x + 340 - 1,y + 300 - 1,TIANYILAN); //add
    bar(x + 10,y + 190,x + 210,y + 340,WHITE);
    putUI("ui\\up.bmp", x + 230, y + 60, -1);
    putUI("ui\\down.bmp", x + 230, y + 110, -1);
    line(x + 400, y + 0, x + 450, y + 55, WHITE);
    line(x + 450, y + 0, x + 400, y + 55, WHITE);
    TextGB64(x + 30, y, 50, WHITE, "��Ƭ����", 0);
    
    TextGB32(x + 240, y + 315, 40, WHITE, "��");
    TextGB32(x + 240,y + 270,40,WHITE,"Ԥ��");
    bar(x + 10, y + 70, x + 220, y + 100, PINK);
    TextASC24(x + 10, y + 70, 14, WHITE, fileNames[0]);

    bar(x + 10, y + 110, x + 220, y + 140, PINK);
    TextASC24(x + 10, y + 110, 14, WHITE, fileNames[1]);

    bar(x + 10, y + 150, x + 220, y + 180, PINK);
    TextASC24(x + 10, y + 150, 14, WHITE, fileNames[2]);

    mouseStatus(&mouseOld);
    mouseStoreBk(mouseOld.x, mouseOld.y);
    while (1)
    {
        mouseStatus(&mouseNew);
        if (mouseNew.x == mouseOld.x && mouseNew.y == mouseOld.y && mouseOld.button == mouseNew.button)
            continue;
        else
        {
            mousePutBk(mouseOld.x, mouseOld.y);
            mouseStoreBk(mouseNew.x, mouseNew.y);
            mouseDraw(mouseNew);
            if (mouseDown(x + 400, y + 0, x + 450, y + 55))
            {
                break;
            }
            if (mouseDown(x + 230, y + 60, x + 270, y + 100))
            {
                if (curPage > 0)
                {
                    curPage--;
                    bar(x + 10, y + 70, x + 220, y + 100, PINK);
                    TextASC24(x + 10, y + 70, 14, WHITE, fileNames[0 + curPage * 3]);
                    bar(x + 10, y + 110, x + 220, y + 140, PINK);
                    TextASC24(x + 10, y + 110, 14, WHITE, fileNames[1 + curPage * 3]);
                    bar(x + 10, y + 150, x + 220, y + 180, PINK);
                    TextASC24(x + 10, y + 150, 14, WHITE, fileNames[2 + curPage * 3]);
                    delay(100);
                }
            }
            if (mouseDown(x + 230, y + 110, x + 270, y + 150))
            {
                if (curPage < filecount / 3)
                {
                    curPage++;
                    bar(x + 10, y + 70, x + 220, y + 100, PINK);
                    TextASC24(x + 10, y + 70, 14, WHITE, fileNames[0 + curPage * 3]);
                    bar(x + 10, y + 110, x + 220, y + 140, PINK);
                    TextASC24(x + 10, y + 110, 14, WHITE, fileNames[1 + curPage * 3]);
                    bar(x + 10, y + 150, x + 220, y + 180, PINK);
                    TextASC24(x + 10, y + 150, 14, WHITE, fileNames[2 + curPage * 3]);
                    delay(100);
                }
            }
            if (mouseDown(x + 10, y + 70, x + 220, y + 100))
            {
                curfile = 0 + curPage * 3;
                if (curfile >= filecount)
                {
                    curfile = -1;
                }
            }
            if (mouseDown(x + 10, y + 110, x + 220, y + 140))
            {
                curfile = 1 + curPage * 3;
                if (curfile >= filecount)
                {
                    curfile = -1;
                }
            }
            if (mouseDown(x + 10, y + 150, x + 220, y + 180))
            {
                curfile = 2 + curPage * 3;
                if (curfile >= filecount)
                {
                    curfile = -1;
                }
            }
            if (mouseDown(x + 230, y + 315, x + 340, y + 345))
            {
                if (curfile != -1)
                {
                    putImage(&bg, x, y);
                    strcat(s, fileNames[curfile]);
                    strcpy(image->cachePath, s);
                    if (readBMP(image, s, 300, 200, 1) == 1)
                        return;
                    else
                    {
                        image->x = image->y = image->height = image->width = 0;
                        strcpy(image->cachePath, "");
                        strcpy(s, "temp\\");
                        msgPhase(200, 200, "��ʧ��");
                        mouseStoreBk(mouseNew.x, mouseNew.y);
                        break;
                    }
                }
                else
                {
                    mousePutBk(mouseNew.x, mouseNew.y);
                    msgPhase(0, 0, "��ѡ���ļ�");
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                }
            }
            if(mouseDown(x + 230,y + 270,x + 340,y + 300)){
                if(curfile != -1){
                    strcat(s, fileNames[curfile]);
                    lowerCase(s);
                    bar(x + 10,y + 190,x + 210,y + 340,WHITE);
                    mousePutBk(mouseNew.x, mouseNew.y);
                    previewPhase(x + 10,y + 190,s);
                    mouseStoreBk(mouseNew.x, mouseNew.y);
                    
                    strcpy(s,"temp\\");
                }
            }
            mouseOld = mouseNew;
        }
    }
    putImage(&bg, x, y);
}

void previewPhase(int x,int y,char *path)
{
    Image image;
    BMPcache(&image,path);
    previewFile(&image,x,y);
}