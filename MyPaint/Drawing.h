#pragma once
#include "WinFunc.h"
#include <Windows.h>


void DrawMyMenu(HDC hdc, MENU* paintMenu);
void DrawMyButton(HDC hdc, BUTTON* button);
void DrawDot(HDC hdc, MYCOORD coord, int size, COLORREF color);
void CanvasDraw(HDC hdc, MENU* paintMenu);
void CleanCanvas(HDC hdc, int sizeX, int sizeY);