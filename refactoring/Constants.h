#pragma once

// нажата ли клавиша
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//===================//
// ИГРОВЫЕ НАСТРОЙКИ //
//===================//

#define GF_WIDTH  1920						// ширина игрового поля
#define GF_HEIGHT 1080						// высота игрового поля
#define GF_RAND_HIGHT rand() % GF_HEIGHT	// случайная координата y
#define GF_RAND_WIDTH rand() % GF_WIDTH		// случайная координата x
#define BARRIER_SPEED 5						// скорость барьеров

//===============//
// К Л А В И Ш И //
//===============//

#define K_EXIT      27 // Esc
#define K_FORWARD   87 // W
#define K_BACKWARD  83 // S
#define K_LEFTWARD  65 // A
#define K_RIGHTWARD 68 // D
#define K_SHOOT		32 // Space

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

