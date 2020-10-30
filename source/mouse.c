#include "mouse.h"

int Cursor[19][12] = {

	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0},
	{2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0},
	{2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0},
	{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0},
	{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	{2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
	{2, 1, 1, 1, 2, 1, 1, 2, 0, 0, 0, 0},
	{2, 1, 1, 2, 2, 1, 1, 2, 0, 0, 0, 0},
	{2, 1, 2, 0, 0, 2, 1, 1, 2, 0, 0, 0},
	{2, 2, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0}};

u32 m_bk[19][12];

/*鼠标初始化*/
unsigned int mouseInit(void)
{
	union REGS m;
	m.x.ax = 0;
	int86(0x33, &m, &m);
	return m.x.ax;
}

/*设置鼠标移动范围*/
void mouseRange(int x1, int y1, int x2, int y2)
{
	union REGS m;
	m.x.ax = 7;
	m.x.cx = x1;
	m.x.dx = x2;
	int86(0x33, &m, &m);

	m.x.ax = 8;
	m.x.cx = y1;
	m.x.dx = y2;
	int86(0x33, &m, &m);
}

/*读取鼠标状态，存入指定结构*/
int mouseStatus(Mouse *m)
{
	union REGS mouse;
	mouse.x.ax = 3;
	int86(0x33, &mouse, &mouse);
	m->x = mouse.x.cx;
	m->y = mouse.x.dx;
	m->button = mouse.x.bx;
	return m->button;
}

/*判断鼠标左键是否在指定位置按下*/
int mouseDown(int x1, int y1, int x2, int y2)
{
	Mouse m = {0, 0, 0};
	mouseStatus(&m);

	if ((m.x >= x1) && (m.x <= x2) && (m.y >= y1) && (m.y <= y2) && (m.button & 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*判断鼠标左键是否在指定位置松开*/
int mouseUp(int x1, int y1, int x2, int y2)
{
	Mouse m = {0, 0, 0};
	mouseStatus(&m);

	if ((m.x >= x1) && (m.x <= x2) && (m.y >= y1) && (m.y <= y2) && (m.button & 1) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*判断鼠标左键是否在指定位置外松开*/
int mouseOutUp(int x1, int y1, int x2, int y2)
{
	Mouse m = {0, 0, 0};
	mouseStatus(&m);

	if (((m.x < x1) || (m.x > x2) || (m.y < y1) || (m.y > y2)) && (m.button & 1) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*存储被鼠标遮挡部分的显存内容*/
void mouseStoreBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] != 0)
			{
				m_bk[i][j] = getPixel(x + j, y + i);
			}
		}
	}
}

/*恢复被鼠标挡住部分的显存*/
void mousePutBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] != 0)
			{
				putPixel(x + j, y + i, m_bk[i][j]);
			}
		}
	}
}

/*鼠标复位*/
void mouseReset(void)
{
	if (mouseInit() != 0xffff)
	{
		printf("Error mouseInit!\n");
		getch();
		exit(1);
	}
	mouseRange(0, 0, SCR_WIDTH - 1, SCR_HEIGHT - 1);
	mouseStoreBk(0, 0);
}

/*画鼠标函数*/
void mouseDraw(Mouse m)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] == 0)
			{
				continue;
			}
			else if (Cursor[i][j] == 1)
			{
				putPixel(m.x + j, m.y + i, 0xffffff);
			}
			else if (Cursor[i][j] == 2)
			{
				putPixel(m.x + j, m.y + i, 0);
			}
		}
	}
}