#include "pch.h"
#include "Missle.h"

void Missile::Draw()
{
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(90), GetY());
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
}

Missile::Missile(HDC _hdc, Position _pos, DIR _dir)
	:ABCUncontrollableObject(_hdc, { _pos , 10, 5 }, RED, 20, _dir)
{
}
