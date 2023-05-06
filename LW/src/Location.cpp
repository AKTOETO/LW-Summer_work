#include "pch.h"
#include "Location.h"

//конструктор
Location::Location(int InitX, int InitY)
{
	m_x = InitX;
	m_y = InitY;
}//Location()

//деструктор
Location::~Location()
{
	//пустое поле
}

//получить значение поля m_x READ
const int& Location::GetX() const
{
	return m_x;
};

//получить значение поля m_y
const int& Location::GetY() const
{
	return m_y;
};