#pragma once
#include "pch.h"
#include "MoveableObject.h"

// список объектов из менеджера
using ManObjList = std::list<ABCMoveableObject*>;

// итератор на объект из менеджера
using ManObjIt = ManObjList::iterator;

// абстрактный базовый класс для всех управляющих объектами
class ABCBaseManager
{
protected:
	// контекст консоли
	HDC m_hdc;

	// список обрабатываемых объектов
	ManObjList* m_objects;

public:
	// конструктор
	ABCBaseManager(HDC _hdc, ManObjList*& _obj_lst);

	// виртуальный деструктор по умолчанию
	virtual ~ABCBaseManager();

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() = 0;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() = 0;
};

// макросы для выполнения действий для каждого элемента
#define FORALL for (auto it = begin(*m_objects); it != end(*m_objects); it++)
#define FORALLIT FORALL (*it)
#define FORALLP(vec, it_name) for (auto it_name = begin(vec); it_name != end(vec); it_name++)
