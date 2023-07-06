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
	HitBox(int _x, int _y, int _width, int _height);

	// конструктор
	HitBox(Position _pos, int _width, int _height);

	virtual ~HitBox() = default;

	// получить смещение по оси X в пикселях исходя из смещения в процентах
	int GetShiftX(int _percents) const;

	// получить смещение по оси Y в пикселях исходя из смещения в процентах
	int GetShiftY(int _percents) const;

	// получить уже смещенную координату X исходя из процентов смещения
	int GetShiftedX(int _percents) const;

	// получить уже смещенную координату Y исходя из процентов смещения
	int GetShiftedY(int _percents) const;

	// получить ширину хитбокса
	const int& GetWidth() const;

	// получить высоту хитбокса
	const int& GetHeight() const;

	// получить сдвинутую позицтю относительно
	// левого верхнего края хитбокса
	Position GetShiftedPosition(int _percents_x, int _percents_y) const;

	// получение хитбокса
	const HitBox& GetHitBox() const;
};
