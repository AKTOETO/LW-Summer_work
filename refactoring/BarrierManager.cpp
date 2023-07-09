#include "pch.h"
#include "BarrierManager.h"

void BarrierManager::ResetBarriersPosition(ManObjIt& _it)
{
	// выбор случайной координаты y
	(*_it)->Reposition({ GF_WIDTH, BR_RAND_Y_COORD((*_it)->GetHeight()) });

	// подбор координаты y
	// если это разные объекты и они пересекаются, 
	// то сдвигаем координату y
	for (auto it = begin(*m_objects); it != end(*m_objects);)
	{
		if (
			_it != it && IsCollision(**_it, **it)
			)
		{
			(*_it)->Reposition({ GF_WIDTH, BR_RAND_Y_COORD((*_it)->GetHeight()) });
			it = begin(*m_objects);
		}
		else
			it++;
	};
}

BarrierManager::BarrierManager(HDC _hdc, ManObjList*& _obj_lst)
	:ABCBaseManager(_hdc, _obj_lst)
{
}

void BarrierManager::ProcessDraw()
{
	// отрисовка всех барьеров
	FORALLIT->ProcessDraw();
}

void BarrierManager::ProcessLogic()
{
	// Проверка на выход барьера за границу экрана.
	// Так как барьер движется справа налево 
	// достаточно проверить не вышел ли барьер за 
	// левую границу экрана
	FORALL
	{
		// если правый край барьера 
		// вышел за левую границу экрана
		if ((*it)->GetShiftedX(100) < 0)
		{
			// перемещаем барьер
			ResetBarriersPosition(it);
		}
	}
}
