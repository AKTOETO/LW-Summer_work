#include "pch.h"
#include "MoveableObject.h"

ABCMoveableObject::ABCMoveableObject(
	HDC _hdc, HitBox _box, COLORREF _color, float _speed, DIR _dir
)
	:HitBox(_box), m_hdc(_hdc), m_color(_color),
	m_speed(_speed), m_shift({0,0}), m_dir(_dir)
{}

ABCMoveableObject::~ABCMoveableObject()
{}

// метод скрытия объекта
void ABCMoveableObject::Hide()
{
	// зарисовываю фигуру белым цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}

// метод отображения объекта
void ABCMoveableObject::Show()
{
	// зарисовываю фигуру красным цветом
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}

// Отрисовка передвигаемого объекта
void ABCMoveableObject::ProcessDraw()
{
	// прячем объект
	Hide();

	// расчет сдвига
	CalcShiftPos();

	// вызов метода сдвига объекта
	ShiftPos(m_shift);

	// показываем объект
	Show();
}

void ABCMoveableObject::Reposition(Position _pos)
{
	Hide();
	Position::SetPos(_pos);
	Show();
}


const DIR& ABCMoveableObject::GetDir() const
{
	return m_dir;
}
