#pragma once
#include "BaseAircraftPart.h"
class Window :
    public BaseAircraftPart
{
protected:

	// фигура, которую надо отрисовать
	virtual void DrawModel() override;

public:

	Window(const HdcPos&);
};

