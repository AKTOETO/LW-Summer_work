#pragma once
#include "UncontrollableObject.h"

class Missile :
    public ABCUncontrollableObject
{
protected:

    // Отрисовка ракеты
    virtual void Draw() override;

public:

    // конструктор
    Missile(HDC _hdc, Position _box);
	~Missile();
};

