#include "pch.h"
#include "SlowAircraft.h"

void SlowAircraft::Draw()
{
	// корпус
	MoveToEx(m_hdc, m_x, m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(15));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(15));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(20));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(30));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(5), m_y + m_hitbox.GetShiftY(30));
	LineTo(m_hdc, m_x, m_y);

	//крыло
	MoveToEx(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(20), NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y + m_hitbox.GetShiftY(50));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(30), m_y + m_hitbox.GetShiftY(50));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(45), m_y + m_hitbox.GetShiftY(20));
}

SlowAircraft::SlowAircraft(int InitX, int InitY, const HDC& _hdc, int _speed, HitBox _hb)
	:Aircraft(InitX, InitY, _hdc, _speed, _hb)
{
}

SlowAircraft::~SlowAircraft()
{
}
