#ifndef CLOUD_H
#define CLOUD_H

#include "Barrier.h"

class Cloud :
    public Barrier
{
protected:
    virtual void Draw() override;

public:
    Cloud(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color = BLACK);
};

#endif