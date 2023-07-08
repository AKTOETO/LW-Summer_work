#include "pch.h"
#include "Barriers.h"


//===================================//
// А Б С Т Р А К Т Н Ы Й   К Л А С С //
//===================================//

// камень
void ABCBarrier::Rock()
{
	// камень
	MoveToEx(m_hdc, GetShiftedX(10), GetShiftedY(0), NULL);
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(10));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(90));
	LineTo(m_hdc, GetShiftedX(10), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(90));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(10));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(10), GetShiftedY(0));
}

// башня улучшения самолета
void ABCBarrier::Upgrade()
{
	MoveToEx(m_hdc, GetShiftedX(50), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(0));
}

// башня ухудшения самолета
void ABCBarrier::Downgrade()
{
	MoveToEx(m_hdc, GetShiftedX(50), GetShiftedY(100), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
}

ABCBarrier::ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color, short _id)
	:ABCUncontrollableObject(_hdc, _box, _color, BARRIER_SPEED, DIR::LEFT,_id)
{}


//=======================//
// П Р Е П Я Т С Т В И Я //
//=======================//

// легкое препятствие
Mountain::Mountain(HDC _hdc, short _id)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT, 100, 100 }, BLACK, _id)
{}

Mountain::Mountain(HDC _hdc, Position _pos, short _id)
	:ABCBarrier(_hdc, { _pos, 100, 100 }, BLACK, _id)
{}

void Mountain::Draw()
{
	Rock();
}

// большое препятствие
UpgradeTower::UpgradeTower(HDC _hdc, short _id)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT,80,100 }, GREEN, _id)
{}

void UpgradeTower::Draw()
{
	Upgrade();
}

// прямоугольник
DowngradeTower::DowngradeTower(HDC _hdc, short _id)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT,80,100 }, RED, _id)
{}

void DowngradeTower::Draw()
{
	Downgrade();
}
