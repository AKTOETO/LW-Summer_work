#pragma once
#include "aircrafts/Aircraft.h"
#include "barriers/Mountain.h"

HWND GetConcolWindow(); //указатель на консольное окно

int main(int argc, char* argv[])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();
	DWORD l;
	COORD point;
	point.X = 0; point.Y = 0;
	
	//если дескриптор существует
	if (hwnd != NULL)
	{
		HDC hdc = GetWindowDC(hwnd);
		//если контекст существует - можем работать
		if (hdc != 0)
		{
			HdcPos cnt(hdc, { 100,100 });
			Aircraft ar(cnt);
			ar.SetVisible();

			cnt.m_pos.SetPos({ 200,200 });
			Mountain mn(cnt);
			
			while (1)
			{
				ar.ProcessHide();
				ar.ProcessLogic(1);	
				ar.ProcessShow();

				mn.ProcessDraw();

				Sleep(10);
			}
		}
	}

	return 0;
}

HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//новая версия Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // получить заголовок окна
	SetConsoleTitle(title);						// установить новый заголовок окна
	Sleep(100);									// ждем смены заголовка окна (100 мс);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// определяем дескриптор окна
	SetConsoleTitle((LPWSTR)str);				//возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}