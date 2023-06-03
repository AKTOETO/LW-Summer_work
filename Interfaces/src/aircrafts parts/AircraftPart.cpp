#include "../pch.h"
#include "AircraftPart.h"

//void AircraftPart::Hide()
//{
//	m_is_visisble = false;
//	// зарисовываю фигуру белым цветом
//	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
//	SelectObject(m_hdc, Pen);
//	DrawModel();
//	DeleteObject(Pen);
//}
//
//void AircraftPart::Show()
//{
//	m_is_visisble = true;
//	// зарисовываю фигуру красным цветом
//	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
//	SelectObject(m_hdc, Pen);
//	DrawModel();
//	DeleteObject(Pen);
//}
//
AircraftPart::AircraftPart(const HitBoxContext& _cnt)
	:HitBox(_cnt.m_hitbox)//,
	//m_hdc(_cnt.m_hdc),
	//m_color(_cnt.m_color),
	//m_is_visisble(0)
{
}

AircraftPart::~AircraftPart()
{
}

void AircraftPart::ProcessMove(Position _pos)
{
	// можем двигаться, только если живы
	//if (m_is_visisble)
	//{
		//Hide();
		ShiftPos(_pos);
		//Show();
	//}
}
//
//void AircraftPart::IsVisible(bool _f)
//{
//	m_is_visisble = _f;
//}
