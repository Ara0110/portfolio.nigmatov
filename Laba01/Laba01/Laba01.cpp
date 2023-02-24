#include <windows.h>
#include <iostream>
#include "CBALL.h"
#include <WinUser.h>
#include <math.h>
//Вместо клавиш A и Q для уменьшение и увеличения скорости соотвественно, использовал клавиши как Control и Caps Lock соответственно.


using namespace std;

int g_nCmdShow;
HWND g_mainWnd;
HINSTANCE g_hInstance;
CBALL b1(15, 10, 50, 50, 30);
CHLimiter h1(350, 250, 300);



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hWnd, &ps);
		b1.Draw(hDC);
		h1.Draw(hDC);
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_SIZE:
	{
		RECT rect;
		rect.top = 0;
		rect.left = 0;
		rect.bottom = HIWORD(lParam);
		rect.right = LOWORD(lParam);
		b1.SetBounds(rect);
		return 0;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_DOWN:
			h1.MoveY(-6);
			return 0;
		case VK_UP:
			h1.MoveY(6);
			return 0;
		case VK_LEFT:
			h1.MoveX(6);
			return 0;
		case VK_RIGHT:
			h1.MoveX(-6);
			return 0;
		case VK_CAPITAL:
			b1.speedup(50);
			return 0;
		case VK_CONTROL:
			b1.speeddown(50);
			return 0;

		}
	}
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void OnIdle()
{
	DWORD ticks = GetTickCount64();
	b1.Move(ticks);
	InvalidateRect(g_mainWnd, NULL, TRUE);
}

WPARAM StartMessageLoop()
{
	MSG msg;
	while (1)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			DispatchMessage(&msg);
		}
		else
		{
			Sleep(20);
			OnIdle();
		}
	}
	return msg.wParam;
}

BOOL InitWindow()
{
	g_mainWnd = CreateWindow(L"Laba01", L"Лабораторная работа 1",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		400, 400,
		0, 0,
		g_hInstance,
		0);

	if (!g_mainWnd) return FALSE;
	ShowWindow(g_mainWnd, g_nCmdShow);
	UpdateWindow(g_mainWnd);
	return TRUE;
}

BOOL InitAppClass()
{
	ATOM class_id;
	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = g_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = L"Laba01";
	class_id = RegisterClass(&wc);

	if (class_id != 0)
		return TRUE;
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{
	g_hInstance = hInstance;
	g_nCmdShow = nCmdShow;

	if (!InitAppClass())
		return 0;

	if (!InitWindow())
		return 0;

	RECT cr;
	GetClientRect(g_mainWnd, &cr);
	b1.SetBounds(cr);
	b1.SetCHLimiter(&h1);
	return StartMessageLoop();
}
