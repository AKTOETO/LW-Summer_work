#include "pch.h"
#include "BarrierManager.h"

BarrierManager::BarrierManager(HDC _hdc)
	:ABCBaseManager(_hdc)
{
	// добавление всех барьеров
	m_objects =
	{
		new Mountain(m_hdc),
		new Mountain(m_hdc),
		new Mountain(m_hdc),
		new UpgradeTower(m_hdc),
		new DowngradeTower(m_hdc),
	};
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
