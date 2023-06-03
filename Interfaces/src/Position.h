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
	Position(int _x, int _y) :m_x(_x), m_y(_y) {};

	// вычислить расстояние сдвига
	// и сдвинуть координаты
	void CalcShiftPos(const Position& _pos) { ShiftPos({ _pos.GetX() - m_x, _pos.GetY() - m_y}); }

	// сдвинуть координаты X Y на _pos
	void ShiftPos(const Position& _pos) { m_x += _pos.GetX(); m_y += _pos.GetY(); }

	// установить координату X
	void SetX(int _x) { m_x = _x; }

	// установить координату Y
	void SetY(int _y) { m_y = _y; }

	// установить координаты X Y
	void SetPos(int _x, int _y) { SetX(_x); SetY(_y); }
	void SetPos(const Position& _pos) { SetX(_pos.GetX()); SetY(_pos.GetY()); }

	// получить координату X
	const int& GetX() const { return m_x; }

	// получить координату Y
	const int& GetY() const { return m_y; }

	// получить позицию
	Position GetPos() { return *this; }
};