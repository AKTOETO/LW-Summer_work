#pragma once
#include "pch.h"

// интерфейс части препятствия
class IBarrierPart
{
protected:
	// башня улучшений
	virtual void Upgrade() = 0;

	// башня понижения самолета
	virtual void Downgrade() = 0;

	// камень
	virtual void Rock() = 0;
};

// абстрактный базовый класс препятствия
class ABCBarrier :
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

	// башня улучшений
	virtual void Upgrade() override;

	// башня понижения самолета
	virtual void Downgrade() override;

private:

	// прячем объект
	void Hide();

	// показываем объект
	void Show();

public:
	// конструктор
	ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color);

	// отрисовка препятствия
	void ProcessDraw();
};

// камень
class Mountain :
	public ABCBarrier
{
public:

	// конструктор
	Mountain(HDC _hdc);

protected:

	// отрисовка препятствия
	virtual void Draw() override;
};

// Башня улучшения
class UpgradeTower :
	public ABCBarrier
{
public:
	// конструктор
	UpgradeTower(HDC _hdc);

protected:

	// отрисовка препятствия
	virtual void Draw() override;
};

// башня ухудшения
class DowngradeTower :
	public ABCBarrier
{
public:
	// конструктор
	DowngradeTower(HDC _hdc, HitBox _hb = { 400,300,80,100 });

protected:

	// отрисовка препятствия
	virtual void Draw() override;
};

// башня наследник
class InherDowngradeTower :
	public DowngradeTower
{
public:
	// конструктор
	InherDowngradeTower(HDC _hdc);

protected:

	virtual void Draw() override;
};