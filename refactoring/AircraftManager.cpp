#include "pch.h"
#include "AircraftManager.h"

AircraftManager::AircraftManager(HDC _hdc, ManObjList*& _obj_lst)
	:ABCBaseManager(_hdc, _obj_lst)
{
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

void AircraftManager::SetCurrentAircraft(ManObjIt& _new_aircraft)
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
