#pragma once
#include "../IGameObject.h"
#include "../barriers parts/IncludeBarrierParts.h"

class BaseBarrier :
    public IGameObject
{
protected:

	// список препятствий
	std::vector<BaseBarrierPart*> m_parts;

public:
	// конструктор
    BaseBarrier();

	virtual ~BaseBarrier();

	// получить список хитбоксов игрового объекта
	// (нужно для обработки столкновений)
	std::list<HitBox> GetHitBoxes() const;

	// Сделать объект видимым
	virtual void SetVisible() override;

	// Сделать объект не видимым
	virtual void SetInvisible() override;

	// переместить объект на определенные координаты
	virtual void SetPosition(Position) override;

	// отрисовка
	virtual void ProcessDraw() override;

};

