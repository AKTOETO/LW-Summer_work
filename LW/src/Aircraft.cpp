#include "pch.h"
#include "Aircraft.h"

void Aircraft::Draw()
{
	// корпус
	MoveToEx(m_hdc, m_x, m_y, NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(10));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(10));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(80), m_y + m_hitbox.GetShiftY(20));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(70), m_y + m_hitbox.GetShiftY(30));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(5),  m_y + m_hitbox.GetShiftY(30));
	LineTo(m_hdc, m_x, m_y);

	//крыло
	MoveToEx(m_hdc, m_x + m_hitbox.GetShiftX(25), m_y + m_hitbox.GetShiftY(20), NULL);
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(20), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(30), m_y + m_hitbox.GetShiftY(100));
	LineTo(m_hdc, m_x + m_hitbox.GetShiftX(45), m_y + m_hitbox.GetShiftY(20));
}

//конструктор
Aircraft::Aircraft(int _x, int _y, const HDC& _hdc, int _speed, HitBox _hb, COLORREF _color, bool is_mooveable)
	:ControllableObject(_x, _y, _hdc, _speed, _hb, _color)
{
}
//деструктор
Aircraft::~Aircraft()
{};

