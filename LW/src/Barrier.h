#ifndef BARRIER_H
#define BARRIER_H
#include "GameObject.h"

class Barrier : public GameObject
{
public:
	Barrier(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color);
};

#endif