#pragma once
#include "Position.h"

// структура поля вокруг игрового объекта
class HitBox
	: public Position
{
protected:

	int m_width;	// ширина
	int m_height;	// высота

public:

	// конструктор с параметрами
	HitBox(int _x, int _y,int _width, int _height)
		: Position(_x, _y), m_width(_width), m_height(_height) {};

	// конструктор
	HitBox(Position _pos, int _width, int _height)
		: Position(_pos), m_width(_width), m_height(_height) {};

	// получить смещение по оси X в пикселях исходя из смещения в процентах
	int GetShiftX(int _percents) const { return (m_width * _percents / 100); }

	// получить смещение по оси Y в пикселях исходя из смещения в процентах
	int GetShiftY(int _percents) const { return (m_height * _percents / 100); };

	// получить уже смещенную координату X исходя из процентов смещения
	int GetShiftedX(int _percents) const { return m_x + GetShiftX(_percents); }

	// получить уже смещенную координату Y исходя из процентов смещения
	int GetShiftedY(int _percents) const { return m_y + GetShiftY(_percents); }

	// получить ширину хитбокса
	const int& GetWidth() const { return m_width; }

	// получить высоту хитбокса
	const int& GetHeight() const { return m_height; }

	// получение копии хитбокса
	HitBox GetHitBox() const { return *this; }
};