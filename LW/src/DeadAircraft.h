#ifndef DEADAIRCRAFT_H
#define DEADAIRCRAFT_H

#include "Aircraft.h"
class DeadAircraft :
    public Aircraft
{
protected:
	// функция отрисовки фигуры
	virtual void Draw() override;

public:
	DeadAircraft(
		int InitX, int InitY, const HDC& _hdc, int _speed = 10,
		HitBox _hb = { 10,10 }, COLORREF _color = RED, bool is_mooveable = 1
	);

};

#endif