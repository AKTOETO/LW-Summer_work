#pragma once
#include "../IGameObject.h"
#include "../barriers parts/IncludeBarrierParts.h"

class BaseBarrier :
    public IGameObject
{
protected:

	// список преп€тствий
	std::vector<BaseBarrierPart*> m_parts;

public:
	// конструктор
    BaseBarrier();

	virtual ~BaseBarrier();

	// получить список хитбоксов игрового объекта
	// (нужно дл€ обработки столкновений)
	std::list<HitBox> GetHitBoxes() const;

	// —делать объект видимым
	virtual void SetVisible() override;

	// —делать объект не видимым
	virtual void SetInvisible() override;

	// переместить объект на определенные координаты
	virtual void SetPosition(Position) override;

	// отрисовка
	virtual void ProcessDraw() override;

	// отрисовка динамичных объектов(пр€чем объект)
	virtual void ProcessHide() override;

	// отрисовка динамичных объектов(показываем объект)
	virtual void ProcessShow() override;

};

