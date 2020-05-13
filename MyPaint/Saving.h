#pragma once

#include "WinFunc.h"
#include "string.h"
#include <stdlib.h>
#include <stdbool.h> 
#include <Windows.h> 
#include <stdio.h>


int MyNumColor(COLORREF pColor);
void WriteToFile(HDC hdc, FILE* file, int sizeX, int sizeY);