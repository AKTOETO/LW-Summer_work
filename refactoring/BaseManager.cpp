#include "pch.h"
#include "BaseManager.h"

ABCBaseManager::ABCBaseManager(HDC _hdc)
	:m_hdc(_hdc)
{
}

std::vector<ABCMoveableObject*> ABCBaseManager::GetObjectVector() const
{
	return m_objects;
}
