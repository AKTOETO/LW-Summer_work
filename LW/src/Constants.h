#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "pch.h"

static HDC hdc;// Объявим контекст устройства
// Контекст устройства по сути это структура,
// содержащая описание видеокарты на вашем компьютере
// и всех необходимых графических элементов

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



#endif //!CONSTANTS_H
