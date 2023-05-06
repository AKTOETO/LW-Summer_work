#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

#include "GameObject.h"

// класс перечислений возможных направлений
// игрового управляемого объекта
enum class DIR
{
    STOP,   // нет движения
    UP,     // вверх
    DOWN,   // вниз
    LEFT,   // влево
    RIGHT   // вправо
};

class ControllableObject :
    public GameObject
{
private:
    // функция, передвигающая объект
    void Move(float _time);

protected:
    DIR m_dir;
    float m_speed;
    bool m_is_controllable;

    // функция отрисовки фигуры
    //virtual void Draw() override;

public:

    // конструктор и деструктор
    ControllableObject(
        int _x, int _y, const HDC& _hdc, float _speed = 10, HitBox _hb = {10,10}, COLORREF _color = RED, bool is_mooveable = 1
    );
    virtual ~ControllableObject();

    // методы обработки логики и отрисовки объекта
    virtual void ProcessLogic(float _time) override;

    // установить состояние: управляем или нет
    void SetControllable(bool);
};

#endif //!CONTROLLABLEOBJECT_H