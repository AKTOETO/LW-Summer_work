#ifndef LOCATION_H
#define LOCATION_H

#include "Constants.h"

//������� �����
class Location
{
protected:
	int m_x;
	int m_y;
public:
	Location(int InitX, int InitY); //�����������
	virtual ~Location(); //����������
	const int& GetX() const; //�������� �������� ���� m_x READ
	const int& GetY() const; //�������� �������� ���� m_y 
	void SetX(int NewX)  //�������� �������� ���� m_x WRITE
	{
		m_x = NewX;
	};
	void SetY(int NewY) //�������� �������� ���� m_y
	{
		m_y = NewY;
	};
};//Location

#endif //!LOCATION_H
