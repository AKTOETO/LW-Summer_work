#pragma once
#include "pch.h"

class DrawableObject
{
protected:

	// фигура, которую надо отрисовать
	virtual void DrawModel() = 0;

	// контекст консоли
	// (наследник должен знать контекст консоли,
	// чтобы нарисовать в консоли что-либо)
	const HDC& m_hdc;

private:

	// цвет отрисовки фигуры
	COLORREF m_color;

	// виден ли сейчас объект
	bool m_is_visisble;

	// скрытие фигуры
	void Hide();

	// отображение фигуры
	void Show();

public:

	DrawableObject(const DrawableObjectContext&);
	virtual ~DrawableObject();

	// отрисовка статичного объекта 
	virtual void ProcessDraw();

	// отрисовка динамичного объекта (пр€чем)
	virtual void ProcessHide();

	// отрисовка динамичного объекта (показываем)
	virtual void ProcessShow();

	// видно ли объект
	virtual void SetVisible(bool);
};

