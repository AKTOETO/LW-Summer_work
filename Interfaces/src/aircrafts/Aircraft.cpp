#include "../pch.h"
#include "Aircraft.h"

Aircraft::Aircraft(const HdcPos& _cnt)
	:BaseAircraft(10, _cnt.m_pos)
{
	// добавляем части самолета в список объектов самолета
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt)
	};

	m_shifts =
	{
		{40,20},
		{0,0},
	};
	// сдвигаем крыло
	m_aircraft_parts[0]->ShiftPos({ 40,20 });
}
