#pragma once
#include "BaseBarrierPart.h"

class Rock :
    public BaseBarrierPart
{
protected:

	// фигура, которую надо отрисовать
	virtual void DrawModel() override;

public:

	Rock(const HdcPos&);
};

