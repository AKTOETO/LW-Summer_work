#pragma once

// возможные события в программе
enum class Events
{
	DESTROY_AIRCRAFT,	// уничтожение самолета

	// передвижение
	STOP,		// стоим
	UPWARD,		// движемся вверх
	RIGHTWARD,	// движемся вправо
	DOWNWARD,	// движемся вниз
	LEFTWARD,	// движемся влево
};

