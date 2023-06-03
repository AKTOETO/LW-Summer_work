#pragma once
#include "pch.h"

class IGameObject
{
public:

	// Сделать объект видимым
	virtual void SetVisible() = 0;

	// Сделать объект не видимым
	virtual void SetInvisible() = 0;

	// переместить объект на определенные координаты
	virtual void SetPosition(Position) = 0;

	// отрисовка
	virtual void ProcessDraw() = 0;
};

