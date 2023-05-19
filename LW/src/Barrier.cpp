#include "pch.h"
#include "Barrier.h"

Barrier::Barrier(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color)
	:GameObject(_x, _y, _hdc, _hb, _color)
{
}

