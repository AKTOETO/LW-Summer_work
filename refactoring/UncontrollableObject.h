#pragma once
#include "MoveableObject.h"



class ABCUncontrollableObject :
    public ABCMoveableObject
{
protected:

    // направление движения
    DIR m_dir;

    // создание сдвига позиции
    virtual void CalcShiftPos() override;

public:
    ABCUncontrollableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed, DIR _dir);
    ~ABCUncontrollableObject();
};

