#pragma once
#include "pch.h"

// направление движения
enum class DIR
{
    STOP,
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class ABCMoveableObject :
    public HitBox
{
protected:

    float m_speed;      // скорость объекта
    COLORREF m_color;	// цвет самолета	
    HDC m_hdc;			// контекст консоли
    Position m_shift;   // сдвиг объекта
    DIR m_dir;          // направление движения

    // Отрисовка текущего объекта
    virtual void Draw() = 0;

    // создание сдвига позиции
    virtual void CalcShiftPos() = 0;

public:
    ABCMoveableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
    ~ABCMoveableObject();

    // метод перемещения объекта на определенные координаты
    void Reposition(Position _pos);

    // метод скрытия объекта
    void Hide();

    // метод отображения объекта
    void Show();

    // Отрисовка передвигаемого объекта
    void ProcessDraw();

    // получить текущее направление движения
    const DIR& GetDir() const;
};

