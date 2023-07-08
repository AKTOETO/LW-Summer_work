#include "pch.h"
#include "BaseManager.h"

ABCBaseManager::ABCBaseManager(HDC _hdc, ManObjList*& _obj_lst)
	:m_hdc(_hdc)
{
	m_objects = _obj_lst;
	//*m_objects = *_obj_lst;
}

ABCBaseManager::~ABCBaseManager()
{
	FORALL delete *it;
	delete m_objects;
}
