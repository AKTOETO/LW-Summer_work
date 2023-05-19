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