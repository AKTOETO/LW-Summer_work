#pragma once
#include "pch.h"

// интерфейс части самолета
class IAircraftPart
{
protected:
	// крыло
	virtual void Wing() = 0;

	// фюзеляж
	virtual void Fuselage() = 0;

	// окно
	virtual void Window() = 0;

	// кломаный фюзеляж
	virtual void BrokenFuselage() = 0;
};

// Абстрактный базовый класс самолета
// реализует функции отрисовки частей самолета
class ABCBaseAircraft:
	public IAircraftPart,
	public HitBox
{
protected:

	float m_speed;		// скорость самолета
	COLORREF m_color;	// цвет самолета
	HDC m_hdc;			// контекст консоли

	// Отрисовка текущего самолета
	virtual void Draw() = 0;

	// части самолета
	// крыло
	virtual void Wing() override;

	// фюзеляж
	virtual void Fuselage() override;

	// иллюминатор
	virtual void Window() override;

	// сломанный самолет
	virtual void BrokenFuselage() override;

public:
	// конструктор
	ABCBaseAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
	
	// метод скрытия объекта
	void Hide();

	// метод отображения объекта
	void Show();
	
	// процесс отрисовки самолета
	// и обработки перемещения самолета
	void ProcessDraw();
};

//=================//
// С А М О Л Е Т Ы //
//=================//

// легкий самолет
class LightAircraft :
	public ABCBaseAircraft
{
public:
	// конструктор
	LightAircraft(HDC _hdc);

	// Отрисовка самолета
	virtual void Draw() override;
};

// сломанный самолет
class BrokenAircraft :
	public ABCBaseAircraft
{
public:
	// конструктор
	BrokenAircraft(HDC _hdc);

	// Отрисовка самолета
	virtual void Draw() override;
};

// только фюзеляж
class FuselageAircraft :
	public ABCBaseAircraft
{
public:
	// конструктор
	FuselageAircraft(HDC _hdc);

	// Отрисовка самолета
	virtual void Draw() override;
};