#pragma once
#include "BaseManager.h"
#include "Missle.h"

// управляющий ракетами
class MissileManager :
    public ABCBaseManager
{
protected:
	// можно ли выстрелить
	bool m_can_shoot;

	// был ли выстрел
	bool m_was_shoot;

	// позиция выстрела
	Position m_launch_pos;

public:
	// конструктор
	MissileManager(HDC _hdc, ManObjList*& _obj_lst);

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() override;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() override;

	// запуск ракеты
	void SetLaunchPosition(Position);

	// можно ли выпустить ракету
	void SetCanShoot(bool);

	// удаление ракеты
	ManObjIt DeleteMissile(ManObjIt&);
};

