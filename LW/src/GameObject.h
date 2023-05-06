#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point.h"

// структура поля вокруг игрового объекта
struct HitBox
{
	int m_width;	// ширина
	int m_height;	// высота

	// конструктор по умолчанию
	HitBox() : m_width(0), m_height(0) {};

	// конструктор с параметрами
	HitBox(int _width, int _height)
		: m_width(_width), m_height(_height) {};

	// получить смещение в пикселях исходя из смещения в процентах
	int GetShiftX(int _percents) { return (m_width * _percents / 100); }
	int GetShiftY(int _percents) { return (m_height * _percents / 100); };
};

// класс игрового объекта
class GameObject : public Point
{
protected:
	HitBox m_hitbox;	// область игрового объекта
	HDC m_hdc;			// контекст консоли
	COLORREF m_color;

	// функция отрисовки фигуры
	virtual void Draw();

public:
	// конструктор, принимающий координаты левого верзнего угла
	// игрового объекта
	GameObject(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color);
	virtual ~GameObject();

	// чисто виртуальные методы обработки логики и отрисовки объекта
	virtual void ProcessLogic(float _time);
	virtual void ProcessDraw();

	// Методы получения характеристик игрового объекта
	const int& GetWidth() const;
	const int& GetHeight() const;

	// методы установки отборабения или скрытия объекта
	virtual void Show() override;
	virtual void Hide() override;
};

#endif