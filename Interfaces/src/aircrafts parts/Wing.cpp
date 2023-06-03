#include "../pch.h"
#include "Wing.h"

void Wing::DrawModel()
{
	// крыло нижнее
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
}

Wing::Wing(const HdcPos& _cnt)
	:BaseAircraftPart(
		{
			_cnt.m_hdc,					// задание контекста консоли
			RED,						// задание цвета крыла
			HitBox(_cnt.m_pos, 15, 60)	// задание хитбокса крыла			
		}
	)
{
}
