#include "pch.h"
#include "Position.h"

// конструктор
Position::Position(int _x, int _y)
	:m_x(_x), m_y(_y)
{};

// вычислить расстояние сдвига
// и сдвинуть координаты
void Position::CalcShiftPos(const Position& _pos)
{
	ShiftPos({ _pos.GetX() - m_x, _pos.GetY() - m_y });
}

// сдвинуть координаты X Y на _pos
void Position::ShiftPos(const Position& _pos)
{
	m_x += _pos.GetX();
	m_y += _pos.GetY();
}

// установить координату X
void Position::SetX(int _x)
{
	m_x = _x;
}

// установить координату Y
void Position::SetY(int _y)
{
	m_y = _y;
}

// установить координаты X Y
void Position::SetPos(int _x, int _y)
{
	SetX(_x);
	SetY(_y);
}
void Position::SetPos(const Position& _pos)
{
	SetX(_pos.GetX());
	SetY(_pos.GetY());
}

// получить координату X
const int& Position::GetX() const
{
	return m_x;
}

// получить координату Y
const int& Position::GetY() const
{
	return m_y;
}

// получить позицию
Position Position::GetPos()
{
	return *this;
}
