#pragma once
//Change to check
#include "WinFunc.h"
#include "string.h"
#include <stdlib.h>
#include <stdbool.h> 
#include <Windows.h> 
#include <stdio.h>

int SavePainting(HDC hdc, char* fileName, int sizeX, int sizeY);
void WriteToFile(HDC hdc, FILE* file, int sizeX, int sizeY);
int OpenPainting(HDC hdc, char* fileName, int sizeX, int sizeY);
void PaintFile(HDC hdc, FILE* file, int sizeX, int sizeY);
COLORREF GetColor(char pixNum);
int MyNumColor(COLORREF pColor);

