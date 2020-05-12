#include <Windows.h>
#include "WinFunc.h"
#include "Drawing.h"

///////////////////////////////////// ���������� ����������
char szClassName[] = "Window1";
HWND hWnd;
///////////////////////////////////// ��������� �������
LRESULT CALLBACK WndProc(HWND, UINT, UINT, LONG);

ATOM registerMyClass(HINSTANCE hInstance);

int createMyWindow(HINSTANCE hInstance, int nCmdShow);
//////////////////////////////////////

MENU* pMenu = NULL;



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpszCmdParam, _In_ int nCmdShow)
{
	MSG msg;

	pMenu = MenuInit();
	createMyWindow(hInstance, nCmdShow);


	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	
	return msg.wParam;


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{

	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}
	case WM_CREATE:
	{
		
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		
		default:
			break;
		}
		break;
	}
	case WM_LBUTTONDOWN:
	{

		pMenu->click.x = LOWORD(lParam);//���������� � �������� ������ ���� - ��������� WndProc
		pMenu->click.y = HIWORD(lParam);
		pMenu->currentBut = CheckClick(pMenu);
		InvalidateRect(hWnd, NULL, 0);

		break;
	}
	case WM_MOUSEMOVE:
	{

		if (wParam & MK_LBUTTON)
		{
			pMenu->click.x = LOWORD(lParam);//���������� � �������� ������ ���� - ��������� WndProc
			pMenu->click.y = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, 0);
		}

	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		if(pMenu->menuDraw == true)
			DrawMyMenu(hdc, pMenu);
		CanvasDraw(hdc, pMenu);
		EndPaint(hWnd, &ps);
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int createMyWindow(HINSTANCE hInstance, int nCmdShow)
{
	registerMyClass(hInstance);

	hWnd = CreateWindow(szClassName, L"My paint", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1200, 900, NULL, NULL, hInstance, NULL);

	if (!hWnd) { return 0; }
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


}

ATOM registerMyClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	return RegisterClass(&wc);
}