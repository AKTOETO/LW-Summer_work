#pragma once
#include "pch.h"

class IGameObject
{
public:

	// —делать объект видимым
	virtual void SetVisible() = 0;

	// —делать объект не видимым
	virtual void SetInvisible() = 0;

	// переместить объект на определенные координаты
	virtual void SetPosition(Position) = 0;

	// отрисовка статичниых объектов
	virtual void ProcessDraw() = 0;

	// отрисовка динамичных объектов(пр€чем объект)
	virtual void ProcessHide() = 0;

	// отрисовка динамичных объектов(показываем объект)
	virtual void ProcessShow() = 0;
};

