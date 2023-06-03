#include "../pch.h"
#include "Aircraft.h"

Aircraft::Aircraft(const HdcPos& _cnt)
	:BaseAircraft(10)
{
	// добавляем части самолета в список объектов самолета
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt)
	};

	// сдвигаем крыло
	m_aircraft_parts[0]->ShiftPos({ 40,20 });

	// отображаем все части самолета
	SetVisible();
}
