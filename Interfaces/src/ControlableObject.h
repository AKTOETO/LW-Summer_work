#pragma once

// класс перечислений возможных направлений
// игрового управл€емого объекта
enum class DIR
{
    STOP,   // нет движени€
    UP,     // вверх
    DOWN,   // вниз
    LEFT,   // влево
    RIGHT   // вправо
};

// класс упарвл€емого объекта
class ControlableObject
{
private:
    // функци€, передвигающа€ объект
    void GenerateShift(float _time);

    DIR m_dir;      // текущее направление
    float m_speed;  // скорость передвижени€
    bool m_controllable;

    // функци€, выполн€юща€ сдвиг контроллируемого объекта
    // путем смещений координат на _shift
    virtual void ProcessMove(Position _shift) = 0;

public:

    // конструктор
    ControlableObject(float _speed);

    // методы обработки логики и отрисовки объекта
    virtual void ProcessLogic(float _time);

    // можно двигатьс€ или нет
    void SetControllable(bool);
};

