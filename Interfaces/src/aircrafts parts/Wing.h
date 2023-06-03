#pragma once
#include "BaseAircraftPart.h"

// крыло
class Wing :
    public BaseAircraftPart
{
protected:

	// фигура, которую надо отрисовать
	virtual void DrawModel() override;

public:

	Wing(const HdcPos&);

};

