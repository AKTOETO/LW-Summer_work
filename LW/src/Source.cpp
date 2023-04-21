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
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
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
//скрыть точку на экране
void Point::Hide()
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом

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
/*          КЛАСС Aircraft           */
/*-----------------------------------*/
//конструктор
Aircraft::Aircraft(int InitX, int InitY, int InitRadius, int InitEyeC) :Point(InitX, InitY)
{
	Radius = InitRadius;
	EyeColor = InitEyeC;
}
//деструктор
Aircraft::~Aircraft()
{
};


//показать ЛИЦО на экране
void Aircraft::Show()
{
	Visible = true;
	//зададим перо и цвет пера
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	//делаем перо активным 
	SelectObject(hdc, PenBlack);
	//нарисуем Контур ЛИЦА
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);


	PenBlack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, PenBlack);
	//нарисуем контур правого глаза
	Ellipse(hdc, X + 0.416 * Radius - 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius, X + 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius);
	//нарисуем контур левого глаза
	Ellipse(hdc, X - 0.416 * Radius - 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius, X - 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius);

	//Выбор цвета глаз
	HBRUSH Brush;
	switch (EyeColor)
	{
	case Black:
		Brush = CreateSolidBrush(RGB(0, 0, 0));
		break;
	case Brown:
		Brush = CreateSolidBrush(RGB(138, 97, 36));
		break;
	case Green:
		Brush = CreateSolidBrush(RGB(65, 161, 31));
		break;
	case Red:
		Brush = CreateSolidBrush(RGB(229, 18, 18));
		break;
	default:
		Brush = CreateSolidBrush(RGB(0, 0, 0));
	}
	//закрашивание глаз (зрачков)
	SelectObject(hdc, Brush);
	//правый
	Ellipse(hdc, X + 0.416 * Radius, Y - 0.277 * Radius - 0.167 * Radius / 2, X + 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius / 2);
	//левый
	Ellipse(hdc, X - 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius / 2, X - 0.416 * Radius, Y - 0.277 * Radius + 0.167 * Radius / 2);
	DeleteObject(Brush);
	//нарисуем нос
	HBRUSH BrushBlack = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, BrushBlack);
	Ellipse(hdc, X - 0.167 * Radius / 2, Y - 0.167 * Radius / 2, X + 0.167 * Radius / 2, Y + 0.167 * Radius / 2);
	DeleteObject(BrushBlack);
	//нарисуем рот
	PenBlack = CreatePen(PS_SOLID, 0.1 * Radius, RGB(0, 0, 0));
	SelectObject(hdc, PenBlack);
	MoveToEx(hdc, X - 0.33 * Radius, Y + 0.33 * Radius, 0);
	LineTo(hdc, X + 0.33 * Radius, Y + 0.33 * Radius);
	DeleteObject(PenBlack);
}
//скрыть ЛИЦО
void Aircraft::Hide()
{
	Visible = false; //лицо не видно
	//закрашиваем область белой окружностью
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);
	DeleteObject(Brush);

	//закрашиваем оставшийся контур
	HPEN PenWhite = CreatePen(PS_SOLID, 0.3 * Radius, RGB(255, 255, 255));
	SelectObject(hdc, PenWhite);
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);
	DeleteObject(PenWhite);
}

//ф-ии для раннего связывания
//void Aircraft::MoveTo(int NewX, int NewY)
//{
//	Hide();//скрыть ФИГУРУ по текущим коорднатам
//	X = NewX; //меняем ккординаты ФИГУРЫ
//	Y = NewY;
//	Show();//показать ФИГУРУ по новым координатам
//}

