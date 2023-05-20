
// класс перечислений возможных направлений
// игрового управл€емого объекта
enum class Dir
{
	STOP,   // нет движени€
	UP,     // вверх
	DOWN,   // вниз
	LEFT,   // влево
	RIGHT   // вправо
};

// местоположение
class Position
{
protected:
	int m_x;
	int m_y;
public:
	Position(int _x, int _y) :m_x(_x), m_y(_y) {};
	Position(const Position& _pos)
	{
		this->m_x = _pos.m_x;
		this->m_y = _pos.m_y;
	}
	Position() = delete;

	Position* SetX(int _x) { m_x = _x; return this; }
	Position* SetY(int _y) { m_y = _y; return this; }

	const int& GetX() const { return m_x; }
	const int& GetY() const { return m_y; }
};

// интерфейс части
class IAircraftPart
{
	// ќтрисовка хвоста
	virtual void Draw(const Position&) = 0;

	// сдвиг части самолета
	virtual void Move(Dir) = 0;
};

// класс самолета
class AircraftPart :
	public IAircraftPart
{
private:
	// позици€ части самолета
	Position* m_pos;


};

// абстрактный класс тела
class Body :
	public IAircraftPart
{

};

// интерфейс хвоста
class ITail
{

};