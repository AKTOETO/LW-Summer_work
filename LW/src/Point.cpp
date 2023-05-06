#include "pch.h"
#include "Point.h"

//конструктор
Point::Point(int InitX, int InitY)
	: Location(InitX, InitY)
{
	m_visible = false;
}
//деструктор
Point::~Point()
{
	//emty body
};

//узнать про светимость точки
bool Point::IsVisisble()
{
	return m_visible;
};
//показать точку на экране
void Point::Show()
{
	m_visible = true;
	SetPixel(hdc, m_x, m_y, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, m_x + 1, m_y, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, m_x, m_y + 1, RGB(255, 0, 0));//рисуем точку установленным цветом
	SetPixel(hdc, m_x + 1, m_y + 1, RGB(255, 0, 0));//рисуем точку установленным цветом
}


/*-------------------*/
/*       Point       */
/*-------------------*/

//скрыть точку на экране
void Point::Hide()
{
	m_visible = false;
	SetPixel(hdc, m_x, m_y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, m_x + 1, m_y, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, m_x, m_y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом
	SetPixel(hdc, m_x + 1, m_y + 1, RGB(0, 0, 0));//рисуем точку устаовленным цветом

}

//// перемещение по клавишам
//void Point::Drag()
//{
//	// пока не нажата Q
//	while (!KEY_DOWN(81))
//	{
//		// A - лево
//		if (KEY_DOWN(65)) MoveTo(m_x - 10, m_y);
//		// W - вверх
//		else if (KEY_DOWN(87)) MoveTo(m_x, m_y - 10);
//		// D - вправо
//		else if (KEY_DOWN(68)) MoveTo(m_x + 10, m_y);
//		// S - Вниз
//		else if (KEY_DOWN(83)) MoveTo(m_x, m_y + 10);
//		Sleep(10);
//	}
//}
//
////переместить ФИГУРУ по новым координатам
//void Point::MoveTo(int NewX, int NewY)
//{
//	Hide();//скрыть ФИГУРУ по текущим коорднатам
//	m_x = NewX; //меняем ккординаты ФИГУРЫ
//	m_y = NewY;
//	Show();//показать ФИГУРУ по новым координатам
//}
