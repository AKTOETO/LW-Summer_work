#pragma once
#include "BarrierManager.h"
#include "AircraftManager.h"
#include "MissileManager.h"

// списки объектов для просчета коллизий
struct CollisionsLists
{
	ManObjList* m_aircrafts;
	ManObjList* m_missiles;
	ManObjList* m_bars;

	CollisionsLists& operator=(CollisionsLists& _lst)
	{
		m_aircrafts = _lst.m_aircrafts;
		m_missiles = _lst.m_missiles;
		m_bars = _lst.m_bars;
		return *this;
	}
};

// управляющий взаимодействиями объектов,
// а также всеми менеджерами
class CollisionController :
    public BarrierManager,
	public AircraftManager,
	public MissileManager
{
protected:
	// просчет колизии
	bool IsCollision(const HitBox& _air, const HitBox& _bar);

	// списки объектов для просчета коллизий
	CollisionsLists m_collision_list;

	// матрица перехода
	std::vector<std::vector<int>> m_collis_mat;

	// есть ли пересечение текущего самолета и барьера
	std::vector<bool> m_is_collision;

	// было ли пересечение текущего самолета и барьера
	std::vector<bool> m_was_collision;
	

public:
	// конструктор и деструктор
	CollisionController(HDC _hdc, CollisionsLists& _col_lst);
	~CollisionController();

	// метод отрисовки и сдвига объектов
	virtual void ProcessDraw() override;

	// метод обработки событий 
	// (нажатие кнопок, выход за границы игрового поля, ...)
	virtual void ProcessLogic() override;
};

