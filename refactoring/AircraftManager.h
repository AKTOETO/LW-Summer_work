#pragma once
#include "BaseManager.h"
#include "Aircrafts.h"

class AircraftManager :
    public ABCBaseManager
{
protected:
	// указатель на текущий самолет
	ABCMoveableObject* m_cur_aircraft;

public:
	// конструктор
	AircraftManager(HDC _hdc);

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() override;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() override;

	// установка текущего самолета
	void SetCurrentAircraft(ABCMoveableObject*&);

	// получение хитбокса текущего самолета
	const HitBox& GetHitBoxOfCurrentAircraft() const;
};

