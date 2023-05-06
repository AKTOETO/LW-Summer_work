#include "pch.h"
#include "DeadAircraft.h"

void DeadAircraft::Draw()
{
	// корпус
	MoveToEx(m_hdc, m_x, m_y, NULL);
	//LineTo(m_hdc, )
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(30), m_y + m_hitbox.GetShiftY(15));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(15));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(25));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(35));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(10), m_y + m_hitbox.GetShiftY(35));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(0), m_y);

	//крыло
	MoveToEx(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(45), NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(30), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(45), m_y + m_hitbox.GetShiftY(45));
}

DeadAircraft::DeadAircraft(
	int InitX, int InitY, const HDC& _hdc, int _speed, HitBox _hb, COLORREF _color, bool is_mooveable
)
	: Aircraft(InitX, InitY, _hdc, _speed, _hb, _color, is_mooveable)
{
}
