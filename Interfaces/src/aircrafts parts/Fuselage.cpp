#include "../pch.h"
#include "Fuselage.h"

void Fuselage::DrawModel()
{
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(70));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetX(), GetY());
}

Fuselage::Fuselage(const HdcPos& _cnt)
	:BaseAircraftPart(
		{
			_cnt.m_hdc,					// задание контекста консоли
			RED,						// задание цвета крыла
			HitBox(_cnt.m_pos, 100, 30)	// задание хитбокса крыла			
		}
	)
{
}
