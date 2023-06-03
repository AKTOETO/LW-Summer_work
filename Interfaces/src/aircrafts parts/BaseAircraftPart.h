#pragma once
#include "AircraftPart.h"
#include "../DrawableObject.h"

class BaseAircraftPart :
    public AircraftPart,
    public DrawableObject
{
protected:

    // фигура, которую надо отрисовать
    virtual void DrawModel() override {};

public:
    BaseAircraftPart(const HitBoxDrawableContext& _cnt)
        : AircraftPart(_cnt.m_hitbox), DrawableObject({ _cnt.m_hdc, _cnt.m_color }) {};

};

