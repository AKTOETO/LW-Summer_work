#pragma once
#include "pch.h"

class IBarrierPart
{
protected:
	// крыло
	virtual void Rock() = 0;

	// фюзеляж
	virtual void HugeRock() = 0;

	// окно
	virtual void Rectangle() = 0;

};

class ABCBaseBarrier :
	public IBarrierPart,
	public HitBox
{
protected:
	COLORREF m_color;
	HDC m_hdc;

	// Отрисовка текущего самолета
	virtual void Draw() = 0;

	// части препятствия
	virtual void Rock() override
	{
		// камень
		MoveToEx(m_hdc, GetX(), GetY(), NULL);
		LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
	};

	virtual void HugeRock() override
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

	virtual void Rectangle() override
	{
		// прямоугольник
		MoveToEx(m_hdc, GetX(), GetY(), NULL);
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
	};

private:
	void Hide()
	{
		// зарисовываю фигуру белым цветом
		HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
		SelectObject(m_hdc, Pen);
		Draw();
		DeleteObject(Pen);
	};

	void Show()
	{
		// зарисовываю фигуру красным цветом
		HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
		SelectObject(m_hdc, Pen);
		Draw();
		DeleteObject(Pen);
	};

public:
	ABCBaseBarrier(HDC _hdc, HitBox _box, COLORREF _color)
		:HitBox(_box), m_hdc(_hdc), m_color(_color) {};

	void ProcessDraw()
	{
		// прячем объект
		Hide();

		// показываем объект
		Show();
	}
};

// легкое препятствие
class LightBarrier :
	public ABCBaseBarrier
{
public:
	LightBarrier(HDC _hdc) :
		ABCBaseBarrier(_hdc, { 200,500,50,50 }, YELLOW)
	{}

	// Отрисовка самолета
	virtual void Draw() override
	{
		Rock();
	}
};

// большое препятствие
class HugeBarrier :
	public ABCBaseBarrier
{
public:
	HugeBarrier(HDC _hdc) :
		ABCBaseBarrier(_hdc, { 200,200,100,100 }, GREEN)
	{}

	// отрисовка
	virtual void Draw() override
	{
		HugeRock();
	}
};

// прямоугольник
class RectBarrier :
	public ABCBaseBarrier
{
public:
	RectBarrier(HDC _hdc):
		ABCBaseBarrier(_hdc, {400, 300, 150,150}, BLACK)
	{}

	// отрисовка 
	virtual void Draw() override
	{
		Rectangle();
	}
};
