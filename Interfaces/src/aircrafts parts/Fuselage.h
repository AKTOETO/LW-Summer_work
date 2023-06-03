#pragma once
#include "BaseAircraftPart.h"

// фюзеляж
class Fuselage :
	public BaseAircraftPart
{
protected:

	// фигура, которую надо отрисовать
	virtual void DrawModel() override;

public:

	Fuselage(const HdcPos&);

};

