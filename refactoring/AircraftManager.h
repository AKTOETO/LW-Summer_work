#pragma once
#include "BaseManager.h"
#include "Aircrafts.h"

class AircraftManager :
    public ABCBaseManager
{
protected:
	// указатель на текущий самолет
	ManObjIt m_cur_aircraft;

public:
	// конструктор
	AircraftManager(HDC _hdc, ManObjList*& _obj_lst);

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() override;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() override;

	// установка текущего самолета
	void SetCurrentAircraft(ManObjIt);

	// получение текущего самолета
	const ManObjIt& GetCurrentAircraft();
};

