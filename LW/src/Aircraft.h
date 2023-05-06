#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "ControllableObject.h"


class Aircraft : public ControllableObject
{
protected:
	// функция отрисовки фигуры
	virtual void Draw() override;

public:
	Aircraft(int InitX, int InitY, const HDC& _hdc, int _speed = 10, HitBox _hb = {10,10}, COLORREF _color = RED, bool is_mooveable = 1); //конструктор
	virtual ~Aircraft(); //деструктор

	// чисто виртуальные методы обработки логики и отрисовки объекта
	/*virtual void ProcessLogic(float _time) override;*/

};

#endif //!AIRCRAFT_H