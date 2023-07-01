#pragma once
#include "UncontrollableObject.h"

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
	public ABCUncontrollableObject
{
protected:

	// части препятствия
	// камень
	virtual void Rock() override;

	// башня улучшений
	virtual void Upgrade() override;

	// башня понижения самолета
	virtual void Downgrade() override;

public:
	// конструктор
	ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color);
};

// камень
class Mountain :
	public ABCBarrier
{
public:

	// конструктор
	Mountain(HDC _hdc);

	// конструктор с заданием позиции
	Mountain(HDC _hdc, Position _pos);

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
	DowngradeTower(HDC _hdc);

protected:

	// отрисовка препятствия
	virtual void Draw() override;
};
