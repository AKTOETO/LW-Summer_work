/**************************************************************************
*               КАФЕДРА №304 2 КУРС ООП ЛАБОРАТОРНАЯ РАБОТА               *
***************************************************************************
*Project type :Win64 Console Application                                  *
*Project name :refactoring.sln					         			      *
*File name    :refactoring.cpp                                            *
*Language     :C++                                                        *
*Programmers  :Плоцкий Богдан Андреевич     М3О-211Б-21      		      *
*Modified By  :Плоцкий Богдан Андреевич     М3О-211Б-21                   *
*Created      :01.05.2023                                                 *
*Last revision:06.06.2023                                                 *
*Comments	  :ИНТЕРФЕЙСЫ И АБСТРАКТНЫЕ БАЗОВЫЕ КЛАССЫ                    *
**************************************************************************/

#include "pch.h"
#include "Aircrafts.h"
#include "Barriers.h"

using namespace std;           // Пространство имен std

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); // указатель на консольное окно
bool Collision(const ABCAircraft& _air, const ABCBarrier& _bar);

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		HDC hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			// количество самолетов
			const int aircraft_number = 4;

			// массив указателей на самолеты
			ABCAircraft* aircrafts[aircraft_number] =
			{
				new LightAircraft(hdc),		// 0
				new FastAircraft(hdc),		// 1
				new VeryFastAircraft(hdc),	// 2
				new BrokenAircraft(hdc),	// 3
			};

			// количество препятствий
			const int barrier_number = 3;

			// массив указателей на препятствия
			// тут будет 3 элемента
			ABCBarrier* bars[barrier_number] =
			{
				new Mountain(hdc),
				new UpgradeTower(hdc),
				new DowngradeTower(hdc),
			};

			// матрица пересечений
			// collis[i][j] = t
			// i - номер самолета из массива aircrafts
			// j - номер препятствия из массива bars
			// t - номер полученного после пересечения самолета из массива aircrafts
			int collis[aircraft_number][barrier_number] =
			{
				{3, 1, 0},
				{3, 2, 0},
				{3, 2, 1},
				{3, 3, 3},
			};

			// есть ли пересечение самолета с текущим препятствием
			bool is_collision[barrier_number];

			// обнуляем весь массив
			for (int i = 0; i < barrier_number; i++)
				is_collision[i] = 0;

			// было ли пересечение самолета с текущим препятствием
			bool was_changed[barrier_number];

			// обнуляем весь массив
			for (int i = 0; i < barrier_number; i++)
				was_changed[i] = 0;

			// указатель на текущий самолет
			int cur_aircraft_index = 0;
			ABCAircraft* cur_air = aircrafts[cur_aircraft_index];

			// главный цикл программы
			while (!KEY_DOWN(K_EXIT))
			{
				// отрисовка всех препятствий
				for (int i = 0; i < barrier_number; i++)
					bars[i]->ProcessDraw();

				// Отрисовка
				cur_air->ProcessDraw();

				// обработка столкновений
				for (int j = 0; j < barrier_number; j++)
				{
					// если самолет и препятствие пересеклось
					if (Collision(*cur_air, *bars[j]))
					{
						is_collision[j] = 1;
					}
					else
					{
						is_collision[j] = 0;
						was_changed[j] = 0;
					}

					// если сейчас есть пересечение, а шаг назад его не было
					if (is_collision[j] && !was_changed[j])
					{
						// новый индекс самолета
						int new_aircraft = collis[cur_aircraft_index][j];

						// переношу конечный самолет в текущие координаты
						aircrafts[new_aircraft]->SetX(cur_air->GetX());
						aircrafts[new_aircraft]->SetY(cur_air->GetY());

						// выключаю видимость текущего самолета
						// и включаю видимость конечного
						cur_air->Hide();
						aircrafts[new_aircraft]->Show();

						// присваиваю текущий самолет текущему указателю на самолет
						cur_air = aircrafts[new_aircraft];

						// меняю текущий номер самолета
						cur_aircraft_index = new_aircraft;

						// пересечение случилось
						was_changed[j] = 1;
					}
				}
				// ждем 10 миллисекунд
				Sleep(10);
			}
		}//end if
	}//end if
	return 0;
}//end main()


/*---------------------------------------------------------------------*/
/*               Р Е А Л И З А Ц И Я   Ф У Н К Ц И Й                   */
/*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*  Создать консольное окно  */
/*---------------------------*/
HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//новая версия Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // получить заголовок окна
	SetConsoleTitle(title);						// установить новый заголовок окна
	Sleep(100);									// ждем смены заголовка окна (100 мс);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// определяем дескриптор окна
	SetConsoleTitle((LPWSTR)str);				//возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}
//end GetConcolWindow()

// просчет колизии
bool Collision(const ABCAircraft& _air, const ABCBarrier& _bar)
{
	int r1 = _air.GetX() + _air.GetWidth();
	int b1 = _air.GetY() + _air.GetHeight();
	int r2 = _bar.GetX() + _bar.GetWidth();
	int b2 = _bar.GetY() + _bar.GetHeight();
	return (_air.GetX() < r2) && (_bar.GetX() < r1) && (_air.GetY() < b2) && (_bar.GetY() < b1);
}