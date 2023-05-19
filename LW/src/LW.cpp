/**************************************************************************
*               КАФЕДРА №304 2 КУРС ООП ЛАБОРАТОРНАЯ РАБОТА               *
***************************************************************************
*Project type :Win64 Console Application                                  *
*Project name :LW.sln					         			              *
*File name    :LW.cpp                                                     *
*Language     :C++                                                        *
*Programmers  :Плоцкий Богдан Андреевич     М3О-211Б-21      		      *
*Modified By  :Плоцкий Богдан Андреевич     М3О-211Б-21                   *
*Created      :1.05.2023                                                  *
*Last revision:20.05.2023                                                 *
*Comments	  :Динамический полиморфизм                                   *
**************************************************************************/

#include "pch.h"

#include "Aircraft.h"
#include "DeadAircraft.h"
#include "SlowAircraft.h"
#include "CargoAircraft.h"
#include "RocketCarrierAircraft.h"

#include "Rock.h"
#include "Cloud.h"
#include "RocketStation.h"

using namespace std;           // Пространство имен std

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//
//HDC hdc;// Объявим контекст устройства
//// Контекст устройства по сути это структура,
//// содержащая описание видеокарты на вашем компьютере
//// и всех необходимых графических элементов

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); //указатель на консольное окно
bool Collision(const Aircraft& _air, const Barrier& _bar);

template<class t>
inline void PrintVec(const vector<t>& _vec, string _sep = " ", string _end = "\n")
{
	for (const auto& el : _vec)cout << el << _sep;
	cout << _end;

}

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
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			// массив указателей на самолеты
			// тут будет 5 элементов
			std::vector<Aircraft*> aircrafts =
			{
				new SlowAircraft(100, 100, hdc, 7, {100,100}, BLUE),    // SlowAircraft 0
				new CargoAircraft(100, 100, hdc, 7, {100,100}, GREEN),  // CargoAircraft 1
				new DeadAircraft(100, 100, hdc, 0, {150,150}, BLACK),  // DeadAircraft 2
				new RocketCarrierAircraft(100, 100, hdc, 10, {150,150}, YELLOW),  // RocketCarrierAircraft 3
			};

			// массив указателей на препятствия
			// тут будет 3 элемента
			std::vector<Barrier*> bars =
			{
				new Rock(900, 200, hdc, { 50,50 }, BLACK),  // Rock
				new Cloud(300, 300, hdc, { 20,70 }, BLUE),  // Clouds			
				new RocketStation(500, 400, hdc, { 45,150 }, RED)     // RocketStation
			};

			// матрица пересечений
			// collis[i][j] = t
			// i - номер самолета из массива aircrafts
			// j - номер препятствия из массива bars
			// t - номер полученного после пересечения самолета из массива aircrafts
			std::vector<std::vector<int>> collis =
			{
				{2, 0, 1},
				{2, 0, 3},
				{2, 2, 2},
				{2, 0, 3},
			};

			// есть ли пересачение самолета с текущим препятствием
			std::vector<bool> is_collision(bars.size(), 0);
			// было ли пересачение самолета с текущим препятствием
			std::vector<bool> was_changed(bars.size(), 0);

			// указатель на текущий самолет
			int cur_aircraft_index = 0;
			Aircraft* cur_air = aircrafts[cur_aircraft_index];
			cur_air->Show();

			// главный цикл программы
			while (!KEY_DOWN(K_EXIT))
			{
				// отрисовка всех препятствий
				std::for_each(bars.begin(), bars.end(), [](const auto& _bar) {_bar->ProcessDraw(); });

				// просчет логики и отрисовка самолета
				cur_air->ProcessLogic(1);

				// обработка столкновений
				for (int j = 0; j < collis[0].size(); j++)
				{
					//PrintVec(is_collision);
					//PrintVec(was_changed);

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
bool Collision(const Aircraft& _air, const Barrier& _bar)
{
	int r1 = _air.GetX() + _air.GetWidth();
	int b1 = _air.GetY() + _air.GetHeight();
	int r2 = _bar.GetX() + _bar.GetWidth();
	int b2 = _bar.GetY() + _bar.GetHeight();
	return (_air.GetX() < r2) && (_bar.GetX() < r1) && (_air.GetY() < b2) && (_bar.GetY() < b1);
}
