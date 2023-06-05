#include "pch.h"
#include "Barriers.h"


//===================================//
// А Б С Т Р А К Т Н Ы Й   К Л А С С //
//===================================//

	// камень
void ABCBaseBarrier::Rock()
{
	// камень
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
};

// большой камень
void ABCBaseBarrier::HugeRock()
{
	// большой камень
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(35), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(20));
	LineTo(m_hdc, GetX(), GetY());
};

// прямоугольник
void ABCBaseBarrier::Rectangle()
{
	// прямоугольник
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
};

void ABCBaseBarrier::Hide()
{
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCBaseBarrier::Show()
{
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

ABCBaseBarrier::ABCBaseBarrier(HDC _hdc, HitBox _box, COLORREF _color)
	:HitBox(_box), m_hdc(_hdc), m_color(_color) 
{}

void ABCBaseBarrier::ProcessDraw()
{
	// прячем объект
	Hide();

	// показываем объект
	Show();
}

//=======================//
// П Р Е П Я Т С Т В И Я //
//=======================//

// легкое препятствие
LightBarrier::LightBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 200,500,50,50 }, YELLOW)
{}

void LightBarrier::Draw()
{
	Rock();
}

// большое препятствие
HugeBarrier::HugeBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 200,200,100,100 }, GREEN)
{}

void HugeBarrier::Draw()
{
	HugeRock();
}

// прямоугольник
RectBarrier::RectBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 400, 300, 150,150 }, BLACK)
{}

void RectBarrier::Draw()
{
	Rectangle();
}
