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
	// проверка на вылет самолета из игровой области
	// если же вылет произошел, возвращаем самолет обратно

	// проверка верхней границы
	if ((*m_cur_aircraft)->GetY() < GF_SHIFT)
		(*m_cur_aircraft)->Reposition({ (*m_cur_aircraft)->GetX(), GF_SHIFT });

	// проверка нижней границы
	else if ((*m_cur_aircraft)->GetShiftedY(100) >= GF_HEIGHT + GF_SHIFT)
		(*m_cur_aircraft)->Reposition(
			{
				(*m_cur_aircraft)->GetX(),
				GF_HEIGHT + GF_SHIFT - (*m_cur_aircraft)->GetHeight()
			}
	);

	// проверка правой границы
	if ((*m_cur_aircraft)->GetShiftedX(100) >= GF_WIDTH)
		(*m_cur_aircraft)->Reposition(
			{
				GF_WIDTH - (*m_cur_aircraft)->GetWidth(),
				(*m_cur_aircraft)->GetY()
			}
	);

	// проверка левой границы
	else if ((*m_cur_aircraft)->GetX() < 0)
		(*m_cur_aircraft)->Reposition({ 0, (*m_cur_aircraft)->GetY() });
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
