#include "pch.h"
#include "BarrierManager.h"

BarrierManager::BarrierManager(HDC _hdc, ManObjList*& _obj_lst)
	:ABCBaseManager(_hdc, _obj_lst)
{
	// добавление всех барьеров
	/*m_objects =
	{
		new Mountain		(m_hdc, 0),
		new Mountain		(m_hdc, 1),
		new Mountain		(m_hdc, 2),
		new UpgradeTower	(m_hdc, 3),
		new DowngradeTower	(m_hdc, 4),
	};*/
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
		// TODO поправить рандомный спавн объектов
		// (они могут спавниться друг на друге)

		// если правый край барьера 
		// вышел за левую границу экрана
		if ((*it)->GetShiftedX(100) < 0)
		{
			// перемещаем барьер
			(*it)->Reposition({ GF_WIDTH,  GF_RAND_HIGHT });
		}
	}
}
