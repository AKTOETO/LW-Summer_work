#include <Windows.h>
#include "Header.h"

//глобальная переменная
extern HDC hdc;//контекст устройства
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*-----------------------------------------------------------------*/
/*     Р Е А Л И З А Ц И Я    М Е Т О Д О В    К Л А С С О В       */
/*-----------------------------------------------------------------*/

/*-----------------------------------*/
/*          КЛАСС Location           */
/*-----------------------------------*/

//конструктор
Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
}//Location()

//деструктор
Location::~Location()
{
	//пустое поле
}

//получить значение поля X READ
int Location::GetX()
{
	return X;
};

//получить значение поля Y
int Location::GetY()
{
	return Y;
};
/*-----------------------------------*/
/*            КЛАСС Point            */
/*-----------------------------------*/

//конструктор
Point::Point(int InitX, int InitY)
	: Location(InitX, InitY)
{
	Visible = false;
}
//деструктор
Point::~Point()
{
	//emty body
};

//узнать про светимость точки
bool Point::IsVisisble()
{
	return Visible;
};
//показать точку на экране
void Point::Show()
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));//рисуем точку установленным цветом

}

/*-------------------*/
/*       Point       */
/*-------------------*/

//скрыть точку на экране
void Point::Hide()
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом

}

// перемещение по клавишам
void Point::Drag()
{
	// пока не нажата Q
	while (!KEY_DOWN(81))
	{
		// A - лево
		if (KEY_DOWN(65)) MoveTo(X - 10, Y);
		// W - вверх
		else if (KEY_DOWN(87)) MoveTo(X, Y - 10);
		// D - вправо
		else if (KEY_DOWN(68)) MoveTo(X + 10, Y);
		// S - Вниз
		else if (KEY_DOWN(83)) MoveTo(X, Y + 10);
		Sleep(100);
	}
}

//переместить ФИГУРУ по новым координатам
void Point::MoveTo(int NewX, int NewY)
{
	Hide();//скрыть ФИГУРУ по текущим коорднатам
	X = NewX; //меняем ккординаты ФИГУРЫ
	Y = NewY;
	Show();//показать ФИГУРУ по новым координатам
}


/*-----------------------------------*/
/*             Aircraft              */
/*-----------------------------------*/
void Aircraft::Draw()
{
	// корпус
	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, X + 20, Y);
	LineTo(hdc, X + 25, Y + 10);
	LineTo(hdc, X + 70, Y + 10);
	LineTo(hdc, X + 80, Y + 20);
	LineTo(hdc, X + 70, Y + 30);
	LineTo(hdc, X + 5, Y + 30);
	LineTo(hdc, X, Y);

	//крыло
	MoveToEx(hdc, X + 25, Y + 20, NULL);
	LineTo(hdc, X + 20, Y + 50);
	LineTo(hdc, X + 30, Y + 50);
	LineTo(hdc, X + 45, Y + 20);
}

//конструктор
Aircraft::Aircraft(int InitX, int InitY)
	:Point(InitX, InitY)
{
}
//деструктор
Aircraft::~Aircraft()
{
};


//показать на экране
void Aircraft::Show()
{
	Visible = true;
	//зададим перо и цвет пера
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	//делаем перо активным 
	SelectObject(hdc, PenBlack);
	Draw();

	DeleteObject(PenBlack);
}

//скрыть
void Aircraft::Hide()
{
	Visible = false; // не видно
	//закрашиваем область белой окружностью
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	//делаем перо активным 
	SelectObject(hdc, PenBlack);
	Draw();

	DeleteObject(PenBlack);
}

