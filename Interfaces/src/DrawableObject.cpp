#include "pch.h"
#include "DrawableObject.h"

void DrawableObject::Hide()
{
	m_is_visisble = false;
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	DrawModel();
	DeleteObject(Pen);
}

void DrawableObject::Show()
{
	m_is_visisble = true;
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	DrawModel();
	DeleteObject(Pen);
}

DrawableObject::DrawableObject(const DrawableObjectContext& _cnt)
	:m_hdc(_cnt.m_hdc),
	m_color(_cnt.m_color),
	m_is_visisble(0)
{
}

DrawableObject::~DrawableObject()
{
}

void DrawableObject::ProcessDraw()
{
	if (m_is_visisble)
	{
		Hide();
		Show();
	}
}

void DrawableObject::SetVisible(bool _b)
{
	m_is_visisble = _b;
}
