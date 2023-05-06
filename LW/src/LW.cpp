/**************************************************************************
*               КАФЕДРА №304 2 КУРС ООП ЛАБОРАТОРНАЯ РАБОТА               *
***************************************************************************
*Project type :Win64 Console Application                                  *
*Project name :LW.sin					         			              *
*File name    :LW.cpp                                                     *
*Language     :C++                                                        *
*Programmers  :Плоцкий Богдан Андреевич     М3О-211Б-21      		      *
*Modified By  :Плоцкий Богдан Андреевич     М3О-211Б-21                   *
*Created      :21.04.2023                                                 *
*Last revision:22.04.2023                                                 *
*Comments	  :ПРОСТЕЙШАЯ ИЕРАРХИЯ КЛАССОВ                                *
**************************************************************************/

#include "pch.h"
//#include <windows.h>
//#include <conio.h>
//#include <iostream>    
//#include "Header.h"
//#include "src/Game.h"
#include "Aircraft.h"
#include "Rock.h"


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
			// самолеты
			//Aircraft sm(100, 100, hdc, 5, {150,100});

			// массив указателей на самолеты
			// тут будет 5 элементов
			std::vector<Aircraft*> aircrafts =
			{
				new Aircraft(100, 100, hdc, 15, {150,50}),        // Aircraft
				new Aircraft(100, 100, hdc, 10, {10,100}, BLACK),  // CargoAircraft
				new Aircraft(100, 100, hdc, 5, {100,100}, BLUE),    // SlowAircraft
				new Aircraft(100, 100, hdc, 0, {150,10}, GREEN, 0),// DestroyedAircraft
				new Aircraft(100, 100, hdc, 10, {50,50}, YELLOW),  // RocketCarrierAircraft
			};

			// препятствия
			//Rock rc(200, 200, hdc, { 50,50 });

			// массив указателей на препятствия
			// тут будет 3 элемента
			std::vector<Barrier*> bars =
			{
				new Rock(200, 200, hdc, { 50,50 }),       // Rock
				new Rock(600, 300, hdc, { 20,70 }, RED),  // Clouds			
				new Rock(200, 400, hdc, { 90,90 }, GREEN) // RocketStation
			};

			// матрица пересечений
			// collis[i][j] = t
			// i - номер самолета из массива aircrafts
			// j - номер препятствия из массива bars
			// t - номер полученного после пересечения самолета из массива aircrafts
			std::vector<std::vector<int>> collis =
			{
				{3, 2, 4},
				{3, 2, 1},
				{3, 2, 2},
				{3, 3, 3},
				{3, 2, 4},
			};

			// указатель на текущий самолет
			Aircraft* cur_air = aircrafts[0];
			cur_air->Show();

			// главный цикл программы
			while (!KEY_DOWN(K_EXIT))
			{
				// отрисовка всех препятствий
				std::for_each(bars.begin(), bars.end(), [](const auto& _bar) {_bar->ProcessDraw(); });

				// просчет логики и отрисовка самолета
				cur_air->ProcessLogic(1);
				cur_air->ProcessDraw();

				// проверка на пересечение
				for (int i = 0; i < collis.size(); i++)
				{
					for (int j = 0; j < collis[i].size(); j++)
					{
						// если самолет и препятствие пересеклось
						if (Collision(*aircrafts[i], *bars[j]))
						{
							//cout << i << " " << j << endl;
							// переношу конечный самолет в текущие координаты
							aircrafts[collis[i][j]]->SetX(cur_air->GetX());
							aircrafts[collis[i][j]]->SetY(cur_air->GetY());

							// выключаю видимость текущего самолета
							// и включаю видимость конечного
							cur_air->Hide();
							aircrafts[collis[i][j]]->Show();

							// присваиваю текущий самолет текущему указателю на самолет
							cur_air = aircrafts[collis[i][j]];
						}
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
