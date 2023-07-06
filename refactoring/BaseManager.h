#pragma once
#include "pch.h"
#include "MoveableObject.h"

// абстрактный базовый класс для всех управляющих объектами
class ABCBaseManager
{
protected:
	// контекст консоли
	HDC m_hdc;

	// список обрабатываемых объектов
	std::vector<ABCMoveableObject*> m_objects;

public:
	// конструктор
	ABCBaseManager(HDC _hdc);

	// виртуальный деструктор по умолчанию
	virtual ~ABCBaseManager() = default;

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() = 0;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() = 0;

	// возврат константной ссылки на список объектов
	std::vector<ABCMoveableObject*> GetObjectVector() const;
};

// макросы для выполнения действий для каждого элемента
#define FORALL for (auto it = begin(m_objects); it != end(m_objects); it++)
#define FORALLIT FORALL (*it)
