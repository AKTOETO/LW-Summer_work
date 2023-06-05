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

	// двигатель сзади
	virtual void RearEngine() = 0;

	// двигатель под крылом
	virtual void UnderWingEngine() = 0;

	// cломаный фюзеляж
	virtual void BrokenFuselage() = 0;

	// сломанное крыло
	virtual void BrokenWing() = 0;

	// сломанное окно
	virtual void BrokenWindow() = 0;

};

// Абстрактный базовый класс самолета
// реализует функции отрисовки частей самолета
class ABCAircraft:
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

	// двигатель сзади
	virtual void RearEngine() override;

	// двигатель под крылом
	virtual void UnderWingEngine() override;

	// сломанный самолет
	virtual void BrokenFuselage() override;

	// сломанное крыло
	virtual void BrokenWing() override;

	// сломанное окно
	virtual void BrokenWindow() override;

public:
	// конструктор
	ABCAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
	
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
	public ABCAircraft
{
public:
	// конструктор
	LightAircraft(HDC _hdc);

protected:

	// Отрисовка самолета
	virtual void Draw() override;
};

// быстрый самолет
class FastAircraft :
	public ABCAircraft
{
public:
	// конструктор
	FastAircraft(HDC _hdc);

protected:

	// Отрисовка самолета
	virtual void Draw() override;
};

// очень быстрый самолет
class VeryFastAircraft :
	public ABCAircraft
{
public:
	// конструктор
	VeryFastAircraft(HDC _hdc);

protected:

	// отрисовка самолета
	virtual void Draw() override;
};

// сломанный самолет
class BrokenAircraft :
	public ABCAircraft
{
public:
	// конструктор
	BrokenAircraft(HDC _hdc);

protected:

	// Отрисовка самолета
	virtual void Draw() override;
};