#include "pch.h"
#include "RocketStation.h"

void RocketStation::Draw()
{
	MoveToEx(m_hdc, m_x + m_hitbox.GetShiftX(50), m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(100), m_y + m_hitbox.GetShiftY(95));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(0), m_y + m_hitbox.GetShiftY(95));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(50), m_y);
}

RocketStation::RocketStation(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color)
	:Barrier(_x, _y, _hdc, _hb, _color)
{
}
