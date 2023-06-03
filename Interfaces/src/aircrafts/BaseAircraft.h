#pragma once
#include "../ControlableObject.h"
#include "../IGameObject.h"
#include "../aircrafts parts/IncludeParts.h"

class BaseAircraft :
	public IGameObject,
	public ControlableObject,
	public Position
{
private:
	// сдвиг объекта
	virtual void ProcessMove(Position _shift) override;

protected:

	// смещени€ объектов
	std::vector<Position> m_shifts;

	// список частей самолета
	std::vector<BaseAircraftPart*> m_aircraft_parts;

public:
	// запрет пустого конструктора
	BaseAircraft() = delete;

	// конструктор
	BaseAircraft(float _speed, Position _pos);

	virtual ~BaseAircraft();

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

