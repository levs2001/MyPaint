#include "Drawing.h"
#include "WinFunc.h"
#include <Windows.h>
//Change to check
void DrawMyMenu(HDC hdc, MENU* paintMenu) {

	DrawMyButton(hdc, &(paintMenu->NEW));
	DrawMyButton(hdc, &(paintMenu->OPEN));
	DrawMyButton(hdc, &(paintMenu->SAVE));
	DrawMyButton(hdc, &(paintMenu->PENCIL1));
	DrawMyButton(hdc, &(paintMenu->PENCIL2));
	DrawMyButton(hdc, &(paintMenu->PENCIL3));
	DrawMyButton(hdc, &(paintMenu->COLRED));
	DrawMyButton(hdc, &(paintMenu->COLGREEN));
	DrawMyButton(hdc, &(paintMenu->COLBLUE));
	DrawMyButton(hdc, &(paintMenu->COLBIR));
	DrawMyButton(hdc, &(paintMenu->ERASER));
	paintMenu->menuDraw = false;
	CleanCanvas(hdc, 1200, 900);
	/////

}

void CanvasDraw(HDC hdc, MENU* paintMenu) {
	if (paintMenu->currentBut != 0) {
		if (paintMenu->currentBut == paintMenu->NEW.number) {
			CleanCanvas(hdc, 1200, 900);
			paintMenu->currentBut = 0;
		}
		if (paintMenu->currentBut == paintMenu->OPEN.number)
			TextOutA(hdc, 300, 300, paintMenu->OPEN.name, strlen(paintMenu->OPEN.name));
		if (paintMenu->currentBut == paintMenu->SAVE.number)
			TextOutA(hdc, 300, 300, paintMenu->SAVE.name, strlen(paintMenu->SAVE.name));
		if (paintMenu->currentBut == paintMenu->PENCIL1.number)
			DrawDot(hdc, paintMenu->click, paintMenu->PENCIL1.size.x, paintMenu->currentCol);
		if (paintMenu->currentBut == paintMenu->PENCIL2.number)
			DrawDot(hdc, paintMenu->click, paintMenu->PENCIL2.size.x, paintMenu->currentCol);
		if (paintMenu->currentBut == paintMenu->PENCIL3.number)
			DrawDot(hdc, paintMenu->click, paintMenu->PENCIL3.size.x, paintMenu->currentCol);
	}
}


void CleanCanvas(HDC hdc, int sizeX, int sizeY) {

	HBRUSH myBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, myBrush);
	Rectangle(hdc, 0, 30, sizeX, 30 + sizeY);
}


void DrawMyButton(HDC hdc, BUTTON* button) {
	HBRUSH myBrush = CreateSolidBrush(button->mycolor);
	SelectObject(hdc, myBrush);
	if (button->number == 11)
		RoundRect(hdc, button->location.x, button->location.y, button->location.x + button->size.x, button->location.y + button->size.y, button->size.x / 2, button->size.y / 2);
	else
		Rectangle(hdc, button->location.x, button->location.y, button->location.x + button->size.x, button->location.y + button->size.y);
	TextOutA(hdc, button->location.x + button->size.x / 3, button->location.y + button->size.y / 3, button->name, strlen(button->name));
}


void DrawDot(HDC hdc, MYCOORD coord, int size, COLORREF color) {

	if (coord.y - size / 2 > 30) {
		for (int x = coord.x - size / 2; x < coord.x + size / 2; x++) {
			for (int y = coord.y - size / 2; y < coord.y + size / 2; y++) {
				SetPixel(hdc, x, y, color);
			}
		}
	}
}