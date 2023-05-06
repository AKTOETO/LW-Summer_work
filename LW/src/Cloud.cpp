#include "pch.h"
#include "Cloud.h"

void Cloud::Draw()
{
	MoveToEx(m_hdc, m_x, m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(90), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(85), m_y + m_hitbox.GetShiftY(80));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(70));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(10), m_y + m_hitbox.GetShiftY(50));
	LineTo(m_hdc, m_x, m_y);
}

Cloud::Cloud(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color)
	:Barrier(_x, _y, _hdc, _hb, _color)
{
}
