#include "pch.h"
#include "Rock.h"

void Rock::Draw()
{
	//Ellipse(m_hdc, m_x, m_y, m_x + m_hitbox.m_width, m_y + m_hitbox.m_height);
	RoundRect(m_hdc, m_x, m_y, m_x + m_hitbox.m_width,
		m_y + m_hitbox.m_height, m_hitbox.GetShiftX(50), m_hitbox.GetShiftY(50));
}

Rock::Rock(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color)
	:Barrier(_x, _y, _hdc, _hb, _color)
{
}
