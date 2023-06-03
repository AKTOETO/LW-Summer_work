#pragma once
#include "IAircraftPart.h"

// абстрактный класс
class AircraftPart :
	public IAircraftPart,
	public HitBox
{
protected:

	//// фигура, которую надо отрисовать
	//virtual void DrawModel() = 0;

	// контекст консоли
	// (наследник должен знать контекст консоли,
	// чтобы нарисовать в консоли что-либо)
	//const HDC& m_hdc;

private:

	//// цвет отрисовки фигуры
	//COLORREF m_color;
	//
	//// виден ли сейчас объект
	//bool m_is_visisble;
	//
	//// скрытие фигуры
	//void Hide();
	//
	//// отображение фигуры
	//void Show();

public:

	AircraftPart(const HitBoxContext&);
	virtual ~AircraftPart();

	// движение части самолета
	virtual void ProcessMove(Position) override;

	//// видно ли часть самолета
	//virtual void IsVisible(bool) override;

};
