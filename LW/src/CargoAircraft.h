#pragma once
#include "Aircraft.h"
class CargoAircraft :
    public Aircraft
{
protected:
    // функция отрисовки фигуры
    virtual void Draw() override;

public:
    CargoAircraft(int InitX, int InitY, const HDC& _hdc, int _speed = 10,
        HitBox _hb = { 10,10 }, COLORREF _color = RED, bool is_mooveable = 1);
};

