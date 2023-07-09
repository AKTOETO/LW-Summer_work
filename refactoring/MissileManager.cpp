#include "pch.h"
#include "MissileManager.h"

MissileManager::MissileManager(HDC _hdc, ManObjList*& _obj_lst)
	:ABCBaseManager(_hdc, _obj_lst), m_can_shoot(1), m_was_shoot(0), m_launch_pos(0, 0)
{
}

void MissileManager::ProcessDraw()
{
	// рисуем каждую ракету
	FORALLIT->ProcessDraw();
}

void MissileManager::ProcessLogic()
{
	// запуск ракеты если
	// возможен выстрел и
	// выстрела ранее не было и
	// была нажата кнопка выстрела
	if (
		m_can_shoot &&
		!m_was_shoot &&
		KEY_DOWN(K_SHOOT)
		)
	{
		m_objects->emplace_back(
			new Missile(m_hdc, m_launch_pos,
				// если не было добавлено ракет в список, индекс новой - 0,
				// иначе индекс новой - индекс последней ракеты + 1
				(!m_objects->empty()? m_objects->back()->GetId() + 1 : 0)
			)
		);
		m_was_shoot = 1;
	}
	// если же кнопка не нажата, записываем это
	else if (!KEY_DOWN(K_SHOOT)) m_was_shoot = 0;


	// обработка выхода за игровое поле
	FORALL
	{
		// если вышли за границы поля, удаляем ракету
		if (
			(*it)->GetX() > GF_WIDTH || (*it)->GetShiftedX(100) < 0 ||
			(*it)->GetY() > GF_HEIGHT + GF_SHIFT ||(*it)->GetShiftedY(100) < GF_SHIFT
			)
		{
			it = DeleteMissile(it);
			if (it == end(*m_objects))break;
		}
	}
}

void MissileManager::SetLaunchPosition(Position _pos)
{
	m_launch_pos = _pos;
}

void MissileManager::SetCanShoot(bool _flag)
{
	m_can_shoot = _flag;
}

ManObjIt MissileManager::DeleteMissile(ManObjIt& _missile)
{
	(*_missile)->Hide();
	delete (*_missile);
	return m_objects->erase(_missile);
}
