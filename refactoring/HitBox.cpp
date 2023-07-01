#include "pch.h"
#include "HitBox.h"

// конструктор с параметрами
HitBox::HitBox(int _x, int _y, int _width, int _height)
	: Position(_x, _y), m_width(_width), m_height(_height)
{};

// конструктор
HitBox::HitBox(Position _pos, int _width, int _height)
	: Position(_pos), m_width(_width), m_height(_height)
{};

// получить смещение по оси X в пикселях исходя из смещения в процентах
int HitBox::GetShiftX(int _percents) const
{
	return (m_width * _percents / 100);
}

// получить смещение по оси Y в пикселях исходя из смещения в процентах
int HitBox::GetShiftY(int _percents) const
{
	return (m_height * _percents / 100);
}

// получить уже смещенную координату X исходя из процентов смещения
int HitBox::GetShiftedX(int _percents) const
{
	return m_x + GetShiftX(_percents);
}

// получить уже смещенную координату Y исходя из процентов смещения
int HitBox::GetShiftedY(int _percents) const
{
	return m_y + GetShiftY(_percents);
}

// получить ширину хитбокса
const int& HitBox::GetWidth() const
{
	return m_width;
}

// получить высоту хитбокса
const int& HitBox::GetHeight() const
{
	return m_height;
}

Position HitBox::GetShiftedPosition(int _percents_x, int _percents_y) const
{
	return Position(GetShiftedX(_percents_x), GetShiftedY(_percents_y));
}

// получение копии хитбокса
HitBox HitBox::GetHitBox() const
{
	return *this;
}
