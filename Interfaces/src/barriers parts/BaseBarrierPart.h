#pragma once
#include "../DrawableObject.h"
#include "../HitBox.h"

class BaseBarrierPart :
    public DrawableObject,
    public HitBox
{
protected:

    // фигура, которую надо отрисовать
    virtual void DrawModel() override {};

public:
    BaseBarrierPart(const HitBoxDrawableContext& _cnt)
        : DrawableObject({ _cnt.m_hdc, _cnt.m_color }), HitBox(_cnt.m_hitbox) {};

};