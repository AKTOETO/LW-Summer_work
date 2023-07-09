#pragma once
#include "BarrierManager.h"
#include "AircraftManager.h"
#include "MissileManager.h"

// матрица целых чисел
using IntMatrix = std::vector<std::vector<int>>;

// матрица итераторов
using ManObjItMatrix = std::vector<std::vector<ManObjIt>>;

// списки объектов для просчета коллизий
struct CollisionsLists
{
	IntMatrix* m_collision_matrix;
	ManObjList* m_aircrafts;
	ManObjList* m_missiles;
	ManObjList* m_bars;

	CollisionsLists& operator=(CollisionsLists& _lst)
	{
		m_collision_matrix = _lst.m_collision_matrix;
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
	//bool IsCollision(const HitBox& _air, const HitBox& _bar);

	// списки объектов для просчета коллизий
	CollisionsLists m_collision_list;

	// матрица перехода
	ManObjItMatrix m_collis_matr;

	// есть ли пересечение текущего самолета и барьера
	std::vector<bool> m_is_collision;

	// было ли пересечение текущего самолета и барьера
	std::vector<bool> m_was_collision;
	
	// создание матрицы переходов с использованием итераторов
	void CreateCollisionMatrix();

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

