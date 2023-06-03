#include "../pch.h"
#include "Window.h"

void Window::DrawModel()
{
	// крыло нижнее
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
}

Window::Window(const HdcPos& _cnt)
	:BaseAircraftPart(
		{
			_cnt.m_hdc,					// задание контекста консоли
			GREEN,						// задание цвета крыла
			HitBox(_cnt.m_pos, 20, 20)	// задание хитбокса крыла			
		}
	)
{
}
