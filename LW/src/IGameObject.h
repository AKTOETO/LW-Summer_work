#ifndef I_GAMEOBJECT_H
#define I_GAMEOBJECT_H

// интерфейс игрового объекта
class IGameObject
{
public:
	// чисто виртуальный метод обработки логики 
	virtual void ProcessLogic(float _time) = 0;
	// чисто виртуальный метод отрисовки объекта
	virtual void ProcessDraw() = 0;

};

#endif //!I_GAMEOBJECT_H