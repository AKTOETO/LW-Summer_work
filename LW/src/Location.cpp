#include "pch.h"
#include "Location.h"

//�����������
Location::Location(int InitX, int InitY)
{
	m_x = InitX;
	m_y = InitY;
}//Location()

//����������
Location::~Location()
{
	//������ ����
}

//�������� �������� ���� m_x READ
const int& Location::GetX() const
{
	return m_x;
};

//�������� �������� ���� m_y
const int& Location::GetY() const
{
	return m_y;
};