#include "pch.h"
#include "AircraftManager.h"

AircraftManager::AircraftManager(HDC _hdc, ManObjList*& _obj_lst)
	:ABCBaseManager(_hdc, _obj_lst)
{
	// добавление всех самолетов
	/*m_objects =
	{
		new LightAircraft	(m_hdc,	0),
		new FastAircraft	(m_hdc,	1),
		new VeryFastAircraft(m_hdc,	2),
		new BrokenAircraft	(m_hdc,	3),
	};*/

	// текущий самолет
	m_cur_aircraft = m_objects->begin();
}

void AircraftManager::ProcessDraw()
{
	(*m_cur_aircraft)->ProcessDraw();
}

void AircraftManager::ProcessLogic()
{
	// TODO забрать возможность самолета улетать за 
	// пределы игровой области
}

void AircraftManager::SetCurrentAircraft(ManObjIt _new_aircraft)
{
	// переношу новый самолет в позицию текущего
	(*_new_aircraft)->SetPos((*m_cur_aircraft)->GetPos());

	// скрываю текущий самолет и показываю новый
	(*m_cur_aircraft)->Hide();
	m_cur_aircraft = _new_aircraft;
	(*m_cur_aircraft)->Show();
}

const ManObjIt& AircraftManager::GetCurrentAircraft()
{
	return m_cur_aircraft;
}
