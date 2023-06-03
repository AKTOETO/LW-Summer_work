#include "pch.h"
#include "ControlableObject.h"

void ControlableObject::GenerateShift(float _time)
{
	// сдвиг координат
	Position shift(0,0);

	// выбор сдвига
	switch (m_dir)
	{
	case DIR::UP:
		shift = { 0, -int(m_speed * _time) };
		break;
	case DIR::DOWN:
		shift = { 0, int(m_speed * _time) };
		break;
	case DIR::LEFT:
		shift = { -int(m_speed * _time),0 };
		break;
	case DIR::RIGHT:
		shift = { int(m_speed * _time),0 };
		break;
	}

	if(m_controllable)
		// сдвиг объекта на консоли
		ProcessMove(shift);
}

ControlableObject::ControlableObject(float _speed)
	:m_speed(_speed), m_dir(DIR::STOP), m_controllable (1)
{
}

void ControlableObject::ProcessLogic(float _time)
{
	// обработка нажатых клавиш
	// если нажата клавиша вперед, двигаемся вверх
	if (KEY_DOWN(K_FORWARD)) m_dir = DIR::UP;

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_BACKWARD)) m_dir = DIR::DOWN;

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_LEFTWARD)) m_dir = DIR::LEFT;

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_RIGHTWARD)) m_dir = DIR::RIGHT;

	// если ничего не нажато или объект обездвижен, надо остановиться
	else m_dir = DIR::STOP;

	// вызов метода сдвига объекта
	GenerateShift(_time);
}

void ControlableObject::SetControllable(bool _f)
{
	m_controllable = _f;
}
