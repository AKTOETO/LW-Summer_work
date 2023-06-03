#pragma once
#include "pch.h"

// интерфейс части препятствия
class IBarrierPart
{
protected:
	// камень
	virtual void Rock() = 0;

	// большой камень
	virtual void HugeRock() = 0;

	// прямоугольник
	virtual void Rectangle() = 0;
};

// абстрактный базовый класс препятствия
class ABCBaseBarrier :
	public IBarrierPart,
	public HitBox
{
protected:
	COLORREF m_color;	// цвет препятствия
	HDC m_hdc;			// контекст консоли

	// Отрисовка препятствия
	virtual void Draw() = 0;

	// части препятствия
	// камень
	virtual void Rock() override;

	// большой камень
	virtual void HugeRock() override;

	// прямоугольник
	virtual void Rectangle() override;

private:

	// прячем объект
	void Hide();

	// показываем объект
	void Show();

public:
	// конструктор
	ABCBaseBarrier(HDC _hdc, HitBox _box, COLORREF _color);

	// отрисовка препятствия
	void ProcessDraw();
};

// легкое препятствие
class LightBarrier :
	public ABCBaseBarrier
{
public:
	// конструктор
	LightBarrier(HDC _hdc);

	// отрисовка препятствия
	virtual void Draw() override;
};

// большое препятствие
class HugeBarrier :
	public ABCBaseBarrier
{
public:
	// конструктор
	HugeBarrier(HDC _hdc);

	// отрисовка препятствия
	virtual void Draw() override;
};

// прямоугольник
class RectBarrier :
	public ABCBaseBarrier
{
public:
	// конструктор
	RectBarrier(HDC _hdc);

	// отрисовка препятствия
	virtual void Draw() override;
};
