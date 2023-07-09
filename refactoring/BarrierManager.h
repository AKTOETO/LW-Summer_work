#pragma once
#include "BaseManager.h"
#include "Barriers.h"

// управляющий барьерами
class BarrierManager :
    public ABCBaseManager
{
protected:
	// переместить барьер
	void ResetBarriersPosition(ManObjIt&);

public:
	// конструктор
	BarrierManager(HDC _hdc, ManObjList*& _obj_lst);

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() override;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() override;
};
