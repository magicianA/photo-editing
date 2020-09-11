#include"phases.h"

int main()
{
	setSVGA();
	mouseReset();
	bar(0,0,SCR_WIDTH,SCR_HEIGHT,TIANYILAN);
	testPhase();
	getch();
    return 0;
}
