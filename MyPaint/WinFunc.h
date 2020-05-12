#pragma once
#include <stdbool.h> 
#include <Windows.h>
typedef struct {
	int x;
	int y;
}MYCOORD;

typedef struct {
	MYCOORD size;
	char name[15];
	MYCOORD location;
	int number;
	COLORREF mycolor;
}BUTTON;

typedef struct {
	int button_count;
	bool menuDraw;
	BUTTON NEW;
	BUTTON OPEN;
	BUTTON SAVE;
	BUTTON PENCIL1;
	BUTTON PENCIL2;
	BUTTON PENCIL3;
	BUTTON COLRED;
	BUTTON COLBLUE;
	BUTTON COLGREEN;
	BUTTON COLBIR;
	BUTTON ERASER;
	MYCOORD click;
	int currentBut;
	COLORREF currentCol;
}MENU;


MENU* MenuInit(void);
void ButInit(BUTTON* button, int locX, int locY, int sizeX, int sizeY, char* name, int num, COLORREF _mycolor);
int CheckClick(MENU* paintMenu);
bool ButAim(BUTTON* button, MYCOORD click);
