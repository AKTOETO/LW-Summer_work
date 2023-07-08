#pragma once
#include "MoveableObject.h"

class ABCUncontrollableObject :
    public ABCMoveableObject
{
protected:

    // создание сдвига позиции
    virtual void CalcShiftPos() override;

public:
    ABCUncontrollableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed, DIR _dir, short _id);
    virtual ~ABCUncontrollableObject();
};

