#include "pch.h"
#include "AircraftManager.h"

AircraftManager::AircraftManager(HDC _hdc)
	:ABCBaseManager(_hdc), m_cur_aircraft(nullptr)
{
	// добавление всех самолетов
	m_objects =
	{
		new LightAircraft(m_hdc),	// 0
		new FastAircraft(m_hdc),	// 1
		new VeryFastAircraft(m_hdc),// 2
		new BrokenAircraft(m_hdc),	// 3
	};

	// текущий самолет
	m_cur_aircraft = m_objects[0];
}

void AircraftManager::ProcessDraw()
{
	m_cur_aircraft->ProcessDraw();
}

void AircraftManager::ProcessLogic()
{
	// TODO забрать возможность самолета улетать за 
	// пределы игровой области
}

void AircraftManager::SetCurrentAircraft(ABCMoveableObject*& _new_aircraft)
{
	// переношу новый самолет в позицию текущего
	_new_aircraft->SetPos(m_cur_aircraft->GetPos());
	
	// скрываю текущий самолет и показываю новый
	m_cur_aircraft->Hide();
	m_cur_aircraft = _new_aircraft;
	m_cur_aircraft->Show();
}

const HitBox& AircraftManager::GetHitBoxOfCurrentAircraft() const
{
	return m_cur_aircraft->GetHitBox();
}
