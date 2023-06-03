#include "../pch.h"
#include "SlowAircraft.h"

SlowAircraft::SlowAircraft(const HdcPos& _cnt)
	:BaseAircraft(5)
{
	// добавляем части самолета в список объектов самолета
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt)
	};

	// сдвигаем крыло
	m_aircraft_parts[0]->ShiftPos({ 20,40 });
}
