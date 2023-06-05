#include "pch.h"
#include "Aircrafts.h"

//===================================//
// А Б С Т Р А К Т Н Ы Й   К Л А С С //
//===================================//

void ABCBaseAircraft::Wing()
{
	// крыло нижнее
	MoveToEx(m_hdc, GetShiftedX(50), GetShiftedY(75), NULL);
	LineTo(m_hdc, GetShiftedX(65), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(60), GetShiftedY(100));
};

void ABCBaseAircraft::Fuselage()
{
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(70));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetX(), GetY());
};

void ABCBaseAircraft::Window()
{
	// окно
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
};

void ABCBaseAircraft::BrokenFuselage()
{
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(40));
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetX(), GetY());
};

ABCBaseAircraft::ABCBaseAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed)
	:HitBox(_box), m_hdc(_hdc), m_color(_color), m_speed(_speed) {};

void ABCBaseAircraft::Hide()
{
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCBaseAircraft::Show()
{
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCBaseAircraft::ProcessDraw()
{
	// прячем объект
	Hide();

	Position shift(0, 0);
	// обработка нажатых клавиш
	// если нажата клавиша вперед, двигаемся вверх
	if (KEY_DOWN(K_FORWARD))
		shift = { 0, -int(m_speed) };

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_BACKWARD))
		shift = { 0, int(m_speed) };

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_LEFTWARD))
		shift = { -int(m_speed),0 };

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_RIGHTWARD))
		shift = { int(m_speed),0 };

	// вызов метода сдвига объекта
	ShiftPos(shift);

	Show();
}

//=================//
// С А М О Л Е Т Ы //
//=================//

// Легкий самолет
LightAircraft::LightAircraft(HDC _hdc)
	: ABCBaseAircraft(_hdc, { 0,0,100,50 }, RED, 10)
{}

void LightAircraft::Draw()
{
	Fuselage();
	Wing();
}

// Сломанный самолет
BrokenAircraft::BrokenAircraft(HDC _hdc)
	:ABCBaseAircraft(_hdc, { 0,0,100,50 }, GREEN, 0)
{}

void BrokenAircraft::Draw()
{
	BrokenFuselage();
	Wing();
}

// Только фюзеляж
FuselageAircraft::FuselageAircraft(HDC _hdc)
	:ABCBaseAircraft(_hdc, { 0,0,100,50 }, YELLOW, 5)
{}

void FuselageAircraft::Draw()
{
	Fuselage();
}


