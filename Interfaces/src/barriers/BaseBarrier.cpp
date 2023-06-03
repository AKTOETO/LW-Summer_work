#include "../pch.h"
#include "BaseBarrier.h"

BaseBarrier::BaseBarrier()
{}


BaseBarrier::~BaseBarrier()
{
	for (auto& el : m_parts)
		delete el;
}

std::list<HitBox> BaseBarrier::GetHitBoxes() const
{
	std::list<HitBox> out;
	for (auto& el : m_parts)
		out.push_back(el->GetHitBox());
	return out;
}

void BaseBarrier::SetVisible()
{
	for (auto& el : m_parts)
		el->SetVisible(1);
}

void BaseBarrier::SetInvisible()
{
	for (auto& el : m_parts)
		el->SetVisible(0);
}

void BaseBarrier::SetPosition(Position _pos)
{
	for (auto& el : m_parts)
		el->CalcShiftPos(_pos);
}

void BaseBarrier::ProcessDraw()
{
	for (auto& el : m_parts)
		el->ProcessDraw();
}

void BaseBarrier::ProcessHide()
{
	for (auto& el : m_parts)
		el->ProcessHide();
}

void BaseBarrier::ProcessShow()
{
	for (auto& el : m_parts)
		el->ProcessShow();
}
