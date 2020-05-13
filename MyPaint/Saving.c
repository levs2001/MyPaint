#define _CRT_SECURE_NO_WARNINGS

#include "WinFunc.h"
#include "string.h"
#include <stdlib.h>
#include <stdbool.h> 
#include <Windows.h> 
#include <stdio.h>
#include "Saving.h"

#define MYWHITE 1
#define MYBLACK 2
#define MYRED 3
#define MYGREEN 4
#define MYBLUE 5
#define MYBIR 6
#define MYGRAY 7


void SavePainting(HDC hdc, int sizeX, int sizeY) {

}

void WriteToFile(HDC hdc, FILE* file, int sizeX, int sizeY) {
	COLORREF pColor;

	for (int y = 1; y <= sizeY; y++) {
		for (int x = 1; x <= sizeX; x++) {
			pColor = GetPixel(hdc, x, y);
			fprintf(file, "%d", MyNumColor(pColor));
		}
		fprintf(file, "%c", '\n');  ////////здесь может быть ошибка
	}

}


int MyNumColor(COLORREF pColor) {
	int R = GetRValue(pColor), G = GetGValue(pColor), B = GetBValue(pColor);

	if (R == 255 && G == 255 && B == 255)
		return MYWHITE;
	if (R == 0 && G == 0 && B == 0)
		return MYBLACK;
	if (R == 255 && G == 0 && B == 0)
		return MYRED;
	if (R == 0 && G == 255 && B == 0)
		return MYGREEN;
	if (R == 0 && G == 0 && B == 255)
		return MYBLUE;
	if (R == 0 && G == 255 && B == 255)
		return MYBIR;
	if (R == 215 && G == 215 && B == 215)
		return MYGRAY;

	return MYWHITE;
}

