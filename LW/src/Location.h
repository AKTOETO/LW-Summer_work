#ifndef LOCATION_H
#define LOCATION_H

#include "Constants.h"

//базовый класс
class Location
{
protected:
	int m_x;
	int m_y;
public:
	Location(int InitX, int InitY); //конструктор
	virtual ~Location(); //деструктор
	const int& GetX() const; //получить значение поля m_x READ
	const int& GetY() const; //получить значение поля m_y 
	void SetX(int NewX);  //заменить значение поля m_x WRITE
	void SetY(int NewY); //заменить значение поля m_y
};//Location

#endif //!LOCATION_H
