#include "pch.h"
#include "Aircrafts.h"

//===================================//
// А Б С Т Р А К Т Н Ы Й   К Л А С С //
//===================================//

void ABCAircraft::Wing()
{
	MoveToEx(m_hdc, GetShiftedX(40), GetShiftedY(50), NULL);
	LineTo(m_hdc, GetShiftedX(35), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(45), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(60), GetShiftedY(50));
};

void ABCAircraft::Fuselage()
{
	MoveToEx(m_hdc, GetShiftedX(10), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(35));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(35));	// верхняя линия корпуса
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(75));
	LineTo(m_hdc, GetShiftedX(15), GetShiftedY(75));
	LineTo(m_hdc, GetShiftedX(10), GetY());
};

void ABCAircraft::Window()
{
	MoveToEx(m_hdc, GetShiftedX(70), GetShiftedY(35), NULL);
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(35));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(35));
}

void ABCAircraft::RearEngine()
{
	MoveToEx(m_hdc, GetShiftedX(10), GetShiftedY(40), NULL);
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(60));
	LineTo(m_hdc, GetShiftedX(15), GetShiftedY(70));
}

void ABCAircraft::UnderWingEngine()
{
	MoveToEx(m_hdc, GetShiftedX(55), GetShiftedY(65), NULL);
	LineTo(m_hdc, GetShiftedX(65), GetShiftedY(75));
	LineTo(m_hdc, GetShiftedX(65), GetShiftedY(85));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(90));
}

void ABCAircraft::BrokenFuselage()
{

	// фюзеляж
	MoveToEx(m_hdc, GetShiftedX(10), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(35));
	LineTo(m_hdc, GetShiftedX(40), GetShiftedY(35));

	// разлом
	LineTo(m_hdc, GetShiftedX(45), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(55), GetShiftedY(40));

	// фюзеляж
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(70));
	LineTo(m_hdc, GetShiftedX(95), GetShiftedY(95));
	LineTo(m_hdc, GetShiftedX(80), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(45), GetShiftedY(75));
	LineTo(m_hdc, GetShiftedX(20), GetShiftedY(75));
	LineTo(m_hdc, GetShiftedX(10), GetY());;
}

void ABCAircraft::BrokenWing()
{
	MoveToEx(m_hdc, GetShiftedX(40), GetShiftedY(50), NULL);
	LineTo(m_hdc, GetShiftedX(42), GetShiftedY(70));
	LineTo(m_hdc, GetShiftedX(20), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(60), GetShiftedY(50));
}

void ABCAircraft::BrokenWindow()
{
	MoveToEx(m_hdc, GetShiftedX(95), GetShiftedY(95), NULL);
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(72));
	LineTo(m_hdc, GetShiftedX(74), GetShiftedY(55));
}

ABCAircraft::ABCAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed)
	:HitBox(_box), m_hdc(_hdc), m_color(_color), m_speed(_speed) {};

void ABCAircraft::Hide()
{
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCAircraft::Show()
{
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCAircraft::ProcessDraw()
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
		shift = { -int(m_speed), 0 };

	// если нажата клавиша назад, двигаемся вниз
	else if (KEY_DOWN(K_RIGHTWARD))
		shift = { int(m_speed), 0 };

	// вызов метода сдвига объекта
	ShiftPos(shift);

	// показываем объект
	Show();
}

//=================//
// С А М О Л Е Т Ы //
//=================//

// Легкий самолет
LightAircraft::LightAircraft(HDC _hdc)
	: ABCAircraft(_hdc, { 50,50,100,50 }, RED, 5)
{}

void LightAircraft::Draw()
{
	Window();
	Fuselage();
	Wing();
}

// Быстрый самолет
FastAircraft::FastAircraft(HDC _hdc)
	:ABCAircraft(_hdc, { 50,50,100,50 }, BLACK, 10)
{}

void FastAircraft::Draw()
{
	Window();
	Fuselage();
	Wing();
	UnderWingEngine();
}

// Очень быстрый самолет
VeryFastAircraft::VeryFastAircraft(HDC _hdc)
	:ABCAircraft(_hdc, { 50,50,100,50 }, GREEN, 15)
{}

void VeryFastAircraft::Draw()
{
	Window();
	Fuselage();
	Wing();
	UnderWingEngine();
	RearEngine();
}

// Сломанный самолет
BrokenAircraft::BrokenAircraft(HDC _hdc)
	:ABCAircraft(_hdc, { 50,50,100,50 }, BLACK, 0)
{}

void BrokenAircraft::Draw()
{
	BrokenFuselage();
	BrokenWindow();
	BrokenWing();
}
