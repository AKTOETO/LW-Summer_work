#pragma once
#include "../pch.h"

// интерфейс части самолета
class IAircraftPart
{
public:
	// движение части самолета
	virtual void ProcessMove(Position) = 0;

	// Видно ли част самолета
	//virtual void IsVisible(bool) = 0;
};
