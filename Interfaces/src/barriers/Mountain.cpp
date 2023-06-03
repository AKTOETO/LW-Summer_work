#include "../pch.h"
#include "Mountain.h"

Mountain::Mountain(const HdcPos& _cnt)
{
	m_parts =
	{
		new Rock(_cnt)
	};

	SetVisible();
}
