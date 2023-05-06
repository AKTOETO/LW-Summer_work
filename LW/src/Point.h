#ifndef POINT_H
#define POINT_H

#include "Location.h"

//Производный класс
class Point : public Location
{
protected:
	bool m_visible; //светиться точка или нет
public:
	Point(int InitX, int InitY); //конструктор
	virtual ~Point(); //деструктор
	bool IsVisisble(); //узнать про светимость точки
	void SetVisible(bool NewVisible) { m_visible = NewVisible; }; //поменять светимость

	// виртуальные ф-ии (позднее связывание)
	virtual void Show(); //показать ТОЧКУ на экране
	virtual void Hide();//скрыть ТОЧКУ 

};//Point

#endif //!POINT_H
