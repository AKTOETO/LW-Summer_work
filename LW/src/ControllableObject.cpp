#include "pch.h"
#include "ControllableObject.h"

void ControllableObject::Move(float _time)
{
	// если объект видимый
	if (m_visible)
	{
		Hide();

		switch (m_dir)
		{
		case DIR::UP:
			m_y -= int(m_speed * _time);
			break;
		case DIR::DOWN:
			m_y += int(m_speed * _time);
			break;
		case DIR::LEFT:
			m_x -= int(m_speed * _time);
			break;
		case DIR::RIGHT:
			m_x += int(m_speed * _time);
			break;
		}

		Show();
	}
}

ControllableObject::ControllableObject(
	int _x, int _y, const HDC& _hdc, float _speed, HitBox _hb, COLORREF _color, bool is_mooveable
) :
	GameObject(_x, _y, _hdc, _hb, _color), m_speed(_speed), m_dir(DIR::STOP),
	m_is_controllable(is_mooveable)
{
}

void ControllableObject::ProcessLogic(float _time)
{
	// обработка нажатых клавиш
	// если нажата клавиша вперед, двигаемся вверх
	if (m_is_controllable && KEY_DOWN(K_FORWARD)) m_dir = DIR::UP;

	// если нажата клавиша назад, двигаемся вниз
	else if (m_is_controllable && KEY_DOWN(K_BACKWARD)) m_dir = DIR::DOWN;

	// если нажата клавиша назад, двигаемся вниз
	else if (m_is_controllable && KEY_DOWN(K_LEFTWARD)) m_dir = DIR::LEFT;

	// если нажата клавиша назад, двигаемся вниз
	else if (m_is_controllable && KEY_DOWN(K_RIGHTWARD)) m_dir = DIR::RIGHT;

	// если ничего не нажато или объект обездвижен, надо остановиться
	else m_dir = DIR::STOP;

	// вызов метода сдвига объекта
	Move(_time);
}

void ControllableObject::SetControllable(bool _b)
{
	m_is_controllable = _b;
}
