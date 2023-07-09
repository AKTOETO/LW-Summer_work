#pragma once
#include "HitBox.h"

inline bool IsCollision(const HitBox& _obj1, const HitBox& _obj2)
{
	int r1 = _obj1.GetX() + _obj1.GetWidth();
	int b1 = _obj1.GetY() + _obj1.GetHeight();
	int r2 = _obj2.GetX() + _obj2.GetWidth();
	int b2 = _obj2.GetY() + _obj2.GetHeight();
	return (_obj1.GetX() < r2) && (_obj2.GetX() < r1) && (_obj1.GetY() < b2) && (_obj2.GetY() < b1);
}
