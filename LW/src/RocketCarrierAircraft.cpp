#include "pch.h"
#include "RocketCarrierAircraft.h"
void RocketCarrierAircraft::Draw()
{
	// корпус
	MoveToEx(m_hdc, m_x, m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(10));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(10));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(90), m_y + m_hitbox.GetShiftY(25));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(40));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(5), m_y + m_hitbox.GetShiftY(40));
	LineTo(m_hdc, m_x, m_y);

	// крыло
	MoveToEx(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(20), NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(45), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(50), m_y + m_hitbox.GetShiftY(20));

	// ракета
	MoveToEx(m_hdc, m_x, m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(40), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(10));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(40), m_y + m_hitbox.GetShiftY(20));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(40), m_y);

}

RocketCarrierAircraft::RocketCarrierAircraft(
	int InitX, int InitY, const HDC& _hdc, int _speed, HitBox _hb, COLORREF _color, bool is_mooveable
)
	: CargoAircraft(InitX, InitY, _hdc, _speed, _hb, _color, is_mooveable)
{
}
