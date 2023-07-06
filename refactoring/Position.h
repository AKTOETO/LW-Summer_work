#pragma once
#include "pch.h"

// класс позиции
class Position
{
protected:

	int m_x;	// координата х
	int m_y;	// координата у

public:

	// конструктор
	Position(int _x, int _y);

	virtual ~Position() = default;

	// вычислить расстояние сдвига
	// и сдвинуть координаты
	void CalcShiftPos(const Position& _pos);

	// сдвинуть координаты X Y на _pos
	void ShiftPos(const Position& _pos);

	// установить координату X
	void SetX(int _x);

	// установить координату Y
	void SetY(int _y);

	// установить координаты X Y
	void SetPos(int _x, int _y);
	void SetPos(const Position& _pos);

	// получить координату X
	const int& GetX() const;

	// получить координату Y
	const int& GetY() const;

	// получить позицию
	Position GetPos();
};
