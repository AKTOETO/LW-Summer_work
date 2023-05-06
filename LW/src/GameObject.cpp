#include "pch.h"
#include "GameObject.h"

void GameObject::Draw()
{
}

GameObject::GameObject(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color)
	:Point(_x, _y), m_hdc(_hdc), m_hitbox(_hb), m_color(_color)
{}

GameObject::~GameObject()
{
}

void GameObject::ProcessLogic(float _time)
{
}

void GameObject::ProcessDraw()
{
	Hide();
	//Rectangle(m_hdc, m_x, m_y, m_x+m_hitbox.m_width, m_y+m_hitbox.m_height);
	Show();
}

const int& GameObject::GetWidth() const
{
	return m_hitbox.m_width;
}

const int& GameObject::GetHeight() const
{
	return m_hitbox.m_height;
}

void GameObject::Show()
{
	m_visible = true;
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}

void GameObject::Hide()
{
	m_visible = false;
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}
