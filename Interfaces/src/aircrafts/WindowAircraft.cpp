#include "../pch.h"
#include "WindowAircraft.h"

WindowAircraft::WindowAircraft(const HdcPos& _cnt)
	:BaseAircraft(10, _cnt.m_pos)
{
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt),
		new Window(_cnt)
	};
	
	m_shifts =
	{
		{10,20},
		{0,0},
		{12,15}
	};

	//m_aircraft_parts[2]->ShiftPos({ 120,15 });
}
