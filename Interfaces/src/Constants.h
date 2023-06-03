#pragma once

// нажата ли клавиша
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//===============//
// К Л А В И Ш И //
//===============//

#define K_EXIT      27 // Esc
#define K_FORWARD   87 // W
#define K_BACKWARD  83 // S
#define K_LEFTWARD  65 // A
#define K_RIGHTWARD 68 // D

//===========//
// Ц В Е Т А //
//===========//

#define RED        RGB(255, 0, 0)
#define WHITE      RGB(255, 255, 255)
#define BLACK      RGB(0, 0, 0)
#define WHITE_GRAY RGB(242, 242, 242)
#define BLUE       RGB(0, 0, 255)
#define GREEN      RGB(16, 255, 0)
#define YELLOW     RGB(254, 253, 0)

//=======================//
// Т И П Ы   Д А Н Н Ы Х //
//=======================//

// контекст унаследованных классов
struct HdcPos
{
	const HDC& m_hdc;	// контекст консоли
	Position m_pos;		// позиция части самолета

	HdcPos(const HDC& _hdc, Position _pos)
		: m_hdc(_hdc), m_pos(_pos) {};
};

// контекст отрисовываемого объекта
struct DrawableObjectContext
{
	const HDC& m_hdc;	// контекст консоли
	COLORREF m_color;	// цвет отрисовки части самолета

	DrawableObjectContext(const HDC& _hdc, COLORREF _color)
		:m_hdc(_hdc), m_color(_color) {};
};

// контекст конструктора абстрактного класса
struct HitBoxContext
{
	HitBox m_hitbox;	// хитбокс части самолета

	HitBoxContext(HitBox _hb)
		:m_hitbox(_hb) {};
};

// контекст базы части самолета
struct HitBoxDrawableContext :
	public DrawableObjectContext,
	public HitBoxContext
{
	HitBoxDrawableContext(const HDC& _hdc, COLORREF _color, HitBox _hb)
		: DrawableObjectContext(_hdc, _color), HitBoxContext(_hb){}
};