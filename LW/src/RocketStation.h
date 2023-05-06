#pragma once
#include "Barrier.h"
class RocketStation :
    public Barrier
{
protected:
    virtual void Draw() override;

public:
    RocketStation(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color);

};

