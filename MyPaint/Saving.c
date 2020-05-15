#define _CRT_SECURE_NO_WARNINGS
//Change to check
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


int SavePainting(HDC hdc, char* fileName, int sizeX, int sizeY) {
	FILE* file = fopen(fileName, "w");

	if (file == NULL)
		return -1;

	WriteToFile(hdc, file, sizeX, sizeY);

	fclose(file);
	return 0;
}

void WriteToFile(HDC hdc, FILE* file, int sizeX, int sizeY) {
	COLORREF pColor;

	for (int y = 31; y <= sizeY; y++) {
		for (int x = 1; x <= sizeX; x++) {
			pColor = GetPixel(hdc, x, y);
			fprintf(file, "%d", MyNumColor(pColor));
		}
		fprintf(file, "%c", '\n');  ////////здесь может быть ошибка
	}

}

int OpenPainting(HDC hdc, char* fileName, int sizeX, int sizeY) {
	FILE* file = fopen(fileName, "r+");

	if (file == NULL)
		return -1;

	PaintFile(hdc, file, sizeX, sizeY);

	fclose(file);
	return 0;
}


void PaintFile(HDC hdc, FILE* file, int sizeX, int sizeY) {
	COLORREF pColor;
	char pixNum = 1;
	int x = 1;
	for (int y = 31; y <= 900; y++) {
		do {
			fscanf(file, "%c", &pixNum);
			if (pixNum != '\n')
				SetPixel(hdc, x, y, GetColor(pixNum));
			x++;
		} while (pixNum != '\n');
		x = 0;
	}
}

COLORREF GetColor(char pixNum) {

	if (pixNum == '1')
		return RGB(255, 255, 255);
	if (pixNum == '2')
		return RGB(0, 0, 0);
	if (pixNum == '3')
		return RGB(255, 0, 0);
	if (pixNum == '4')
		return RGB(0, 255, 0);
	if (pixNum == '5')
		return RGB(0, 0, 255);
	if (pixNum == '6')
		return RGB(0, 255, 255);
	if (pixNum == '7')
		return RGB(215, 215, 215);

	return RGB(255, 255, 255);

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