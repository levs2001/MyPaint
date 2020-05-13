#define _CRT_SECURE_NO_WARNINGS

#include "WinFunc.h"
#include "string.h"
#include <stdlib.h>
#include <stdbool.h> 
#include <Windows.h> 
#include <stdio.h>



MENU* MenuInit(void) {
	MENU* paintMenu;
	paintMenu = malloc(sizeof(MENU));

	paintMenu->menuDraw = true;
	paintMenu->currentBut = 0;
	paintMenu->button_count = 6;
	
	ButInit(&(paintMenu->NEW), 0, 0, 75, 30, "new", 1, RGB(255,255,255));
	ButInit(&(paintMenu->OPEN), 75, 0, 75, 30, "open", 2, RGB(255, 255, 255));
	ButInit(&(paintMenu->SAVE), 150, 0, 75, 30, "save", 3, RGB(255, 255, 255));
	ButInit(&(paintMenu->PENCIL1), 500, 0, 10, 10, "", 4, RGB(255, 255, 255));
	ButInit(&(paintMenu->PENCIL2), 510, 0, 20, 20, "", 5, RGB(255, 255, 255));
	ButInit(&(paintMenu->PENCIL3), 530, 0, 30, 30, "", 6, RGB(255, 255, 255));
	ButInit(&(paintMenu->COLRED), 400, 0, 20, 20, "", 7, RGB(255, 0, 0));
	ButInit(&(paintMenu->COLGREEN), 420, 0, 20, 20, "", 8, RGB(0, 255, 0));
	ButInit(&(paintMenu->COLBLUE), 440, 0, 20, 20, "", 9, RGB(0, 0, 255));
	ButInit(&(paintMenu->COLBIR), 460, 0, 20, 20, "", 10, RGB(0, 255, 255));
	ButInit(&(paintMenu->ERASER), 580, 0, 80, 30, "", 11, RGB(215, 215, 215));

	return paintMenu;
}

void ButInit(BUTTON* button, int locX, int locY, int sizeX, int sizeY, char* name, int num, COLORREF _mycolor) {
	
	button->location.x = locX;
	button->location.y = locY;
	button->size.x = sizeX;
	button->size.y = sizeY;
	strcpy(button->name, name);
	button->number = num;
	button->mycolor = _mycolor;

}


int CheckClick(MENU* paintMenu) {
	
	if (ButAim(&(paintMenu->NEW), paintMenu->click) == true)
		return paintMenu->NEW.number;
	
	if (ButAim(&(paintMenu->OPEN), paintMenu->click) == true)
		return paintMenu->OPEN.number;
	
	if (ButAim(&(paintMenu->SAVE), paintMenu->click) == true)
		return paintMenu->SAVE.number;

	if (ButAim(&(paintMenu->PENCIL1), paintMenu->click) == true)
		return paintMenu->PENCIL1.number;
	
	if (ButAim(&(paintMenu->PENCIL2), paintMenu->click) == true)
		return paintMenu->PENCIL2.number;
	
	if (ButAim(&(paintMenu->PENCIL3), paintMenu->click) == true)
		return paintMenu->PENCIL3.number;

	if (ButAim(&(paintMenu->COLRED), paintMenu->click) == true)
		paintMenu->currentCol = paintMenu->COLRED.mycolor;

	if (ButAim(&(paintMenu->COLGREEN), paintMenu->click) == true)
		paintMenu->currentCol = paintMenu->COLGREEN.mycolor;

	if (ButAim(&(paintMenu->COLBLUE), paintMenu->click) == true)
		paintMenu->currentCol = paintMenu->COLBLUE.mycolor;

	if (ButAim(&(paintMenu->COLBIR), paintMenu->click) == true)
		paintMenu->currentCol = paintMenu->COLBIR.mycolor;
	
	if (ButAim(&(paintMenu->ERASER), paintMenu->click) == true)
		paintMenu->currentCol = RGB(255,255,255);

	if (paintMenu->currentBut != paintMenu->PENCIL1.number && paintMenu->currentBut != paintMenu->PENCIL2.number
		&& paintMenu->currentBut != paintMenu->PENCIL3.number)
		return 0;
	else
		return paintMenu->currentBut;
}

bool ButAim(BUTTON* button, MYCOORD click) {
	if (click.x >= button->location.x && click.x <= button->location.x + button->size.x) {
		if (click.y >= button->location.y && click.y <= button->location.y + button->size.y)
			return true;
	}
	return false;
}