#include "pch.h"
#include "ControllableObject.h"

void ABCControllableObject::CalcShiftPos()
{
	// обработка нажатых клавиш
	// если нажата клавиша вперед, двигаемся вверх
	if (KEY_DOWN(K_FORWARD))
	{
		m_shift = { 0, -int(m_speed) };
		m_dir = DIR::UP;
	}

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_BACKWARD))
	{
		m_shift = { 0, int(m_speed) };
		m_dir = DIR::DOWN;
	}

	// если нажата клавиша влево, двигаемся влево
	else if (KEY_DOWN(K_LEFTWARD))
	{
		m_shift = { -int(m_speed), 0 };
		m_dir = DIR::LEFT;
	}

	// если нажата клавиша вправо, двигаемся вправо
	else if (KEY_DOWN(K_RIGHTWARD))
	{
		m_shift = { int(m_speed), 0 };
		m_dir = DIR::RIGHT;
	}
	else
	{
		m_shift = { 0,0 };
		m_dir = DIR::STOP;
	}

}

ABCControllableObject::ABCControllableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed)
	:ABCMoveableObject(_hdc, _box, _color, _speed)
{
}

ABCControllableObject::~ABCControllableObject()
{
}
