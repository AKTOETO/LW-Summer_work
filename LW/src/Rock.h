#pragma once
#include "Barrier.h"
class Rock :
    public Barrier
{
protected:
	virtual void Draw() override;

public:
	Rock(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color = BLACK);
	~Rock();

	//virtual void ProcessDraw() override;
};

