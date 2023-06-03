#include "../pch.h"
#include "BaseAircraft.h"

void BaseAircraft::ProcessMove(Position _shift)
{
	for (auto& el : m_aircraft_parts)
		el->ProcessMove(_shift);
}

BaseAircraft::BaseAircraft(
	float _speed, Position _pos
):
	ControlableObject(_speed),
	Position(_pos)
{
	SetPosition({ 0,0 });
}

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
	for (int i=0;i<m_aircraft_parts.size();i++)
		m_aircraft_parts[i]->SetPos(
			{ _pos.GetX() + m_shifts[i].GetX(),
			_pos.GetY() + m_shifts[i].GetY()});
}

void BaseAircraft::ProcessDraw()
{
	for (auto& el : m_aircraft_parts)
		el->ProcessDraw();
}

void BaseAircraft::ProcessHide()
{
	for (auto& el : m_aircraft_parts)
		el->ProcessHide();
}

void BaseAircraft::ProcessShow()
{
	for (auto& el : m_aircraft_parts)
		el->ProcessShow();
}
