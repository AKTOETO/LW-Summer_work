#include "../pch.h"
#include "Rock.h"

void Rock::DrawModel()
{
	// крыло нижнее
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(10), GetShiftedY(0));
}

Rock::Rock(const HdcPos& _cnt)
	:BaseBarrierPart(
		{
			_cnt.m_hdc,					// задание контекста консоли
			GREEN,						// задание цвета крыла
			HitBox(_cnt.m_pos, 40, 40)	// задание хитбокса крыла			
		}
	)
{
}