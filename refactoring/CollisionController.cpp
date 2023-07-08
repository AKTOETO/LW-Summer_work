#include "pch.h"
#include "CollisionController.h"

bool CollisionController::IsCollision(const HitBox& _air, const HitBox& _bar)
{
	int r1 = _air.GetX() + _air.GetWidth();
	int b1 = _air.GetY() + _air.GetHeight();
	int r2 = _bar.GetX() + _bar.GetWidth();
	int b2 = _bar.GetY() + _bar.GetHeight();
	return (_air.GetX() < r2) && (_bar.GetX() < r1) && (_air.GetY() < b2) && (_bar.GetY() < b1);
}

CollisionController::CollisionController(HDC _hdc, CollisionsLists& _col_lst)
	:AircraftManager(_hdc, _col_lst.m_aircrafts),
	MissileManager(_hdc, _col_lst.m_missiles),
	BarrierManager(_hdc, _col_lst.m_bars)
{
	// список препятствий
	m_collision_list = _col_lst;

	// матрица перехода
	m_collis_mat.resize(
		m_collision_list.m_aircrafts->size(),
		std::vector<int>(m_collision_list.m_bars->size(), 3)
	);

	// m_collis_mat[i][j] = t
	// i - номер самолета из массива aircrafts
	// j - номер препятствия из массива bars
	// t - номер полученного после пересечения самолета из массива aircrafts
	// t - id самолета, который храниться в самом объекте самолета
	m_collis_mat =
	{
		{3, 3, 3, 1, 0},
		{3, 3, 3, 2, 1},
		{3, 3, 3, 2, 1},
		{3, 3, 3, 3, 3},
	};

	// создание массивов необходимых для обработки нажатия кнопки
	m_is_collision.resize(m_collision_list.m_bars->size(), 0);
	m_was_collision.resize(m_collision_list.m_bars->size(), 0);
}

CollisionController::~CollisionController()
{
}

void CollisionController::ProcessDraw()
{
	// рисуем и двигамем самолеты, ракеты, барьеры
	AircraftManager::ProcessDraw();
	MissileManager::ProcessDraw();
	BarrierManager::ProcessDraw();
}

void CollisionController::ProcessLogic()
{
	// ОБРАБОТКА КОЛЛИЗИЙ

	// проходимся по всем барьерам
	FORALLP(*m_collision_list.m_bars, bar)
	{
		// проверка пересечения всех барьеров со всеми ракетами
		FORALLP(*m_collision_list.m_missiles, miss)
		{
			// обработка столкновения ракеты с барьером
			if (IsCollision(**bar, **miss))
			{
				// перемещаем барьер в правую часть экрана
				(*bar)->Reposition({ GF_WIDTH, GF_RAND_HIGHT });

				// удаляем ракету 
				miss = DeleteMissile(miss);

				// проверяем, есть ли еще ракеты
				if (miss == m_collision_list.m_missiles->end())break;
			}
		}

		int bars_ind = (*bar)->GetId();
		// проверка пересечения всех барьеров со всеми самолетами
		// если самолет и препятствие пересеклось
		if (IsCollision((*GetCurrentAircraft())->GetHitBox(), **bar))
		{
			m_is_collision[bars_ind] = 1;
		}
		else
		{
			m_is_collision[bars_ind] = 0;
			m_was_collision[bars_ind] = 0;
		}

		// если сейчас есть пересечение, а шаг назад его не было
		if (m_is_collision[bars_ind] && !m_was_collision[bars_ind])
		{
			// получаем индекс нового самолета
			int new_aircraft_ind = m_collis_mat
				[(*GetCurrentAircraft())->GetId()][bars_ind];

			// устанавливаем новый самолет
			ManObjIt new_aircraft_iter = m_collision_list.m_aircrafts->begin();
			std::advance(new_aircraft_iter, new_aircraft_ind);
			AircraftManager::SetCurrentAircraft(new_aircraft_iter);

			// пересечение случилось
			m_was_collision[bars_ind] = 1;
		}
	}

	// ЗАПУСК ЛОГИКИ МЕНЕДЖЕРОВ
	AircraftManager::ProcessLogic();

	// установка позиции запуска ракеты
	MissileManager::SetLaunchPosition(
		(*GetCurrentAircraft())->GetShiftedPosition(90, 50)
	);

	// если самолет взорван, стрелять нельзя
	MissileManager::SetCanShoot(
		(*GetCurrentAircraft())->GetId() != 3
	);

	MissileManager::ProcessLogic();
	BarrierManager::ProcessLogic();
}
