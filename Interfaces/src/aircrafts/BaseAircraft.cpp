#include "../pch.h"
#include "BaseAircraft.h"

void BaseAircraft::ProcessMove(Position _shift)
{
	for (auto& el : m_aircraft_parts)
		el->ProcessMove(_shift);
}

BaseAircraft::BaseAircraft(
	float _speed
):
	ControlableObject(_speed)
{}

BaseAircraft::~BaseAircraft()
{
	for (auto& el : m_aircraft_parts)
		delete el;
}

std::list<HitBox> BaseAircraft::GetHitBoxes() const
{
	std::list<HitBox> out;
	for (auto& el : m_aircraft_parts)
		out.push_back(el->GetHitBox());
	return out;
}

void BaseAircraft::SetVisible()
{
	for (auto& el : m_aircraft_parts)
		el->SetVisible(1);
}

void BaseAircraft::SetInvisible()
{
	for (auto& el : m_aircraft_parts)
		el->SetVisible(0);
}

void BaseAircraft::SetPosition(Position _pos)
{
	for (auto& el : m_aircraft_parts)
		el->CalcShiftPos(_pos);
}

void BaseAircraft::ProcessDraw()
{
	for (auto& el : m_aircraft_parts)
		el->ProcessDraw();
}
