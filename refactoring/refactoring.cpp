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
//#include "Aircrafts.h"
//#include "Barriers.h"
//#include "Missle.h"
#include "CollisionController.h"

using namespace std;           // Пространство имен std

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); // указатель на консольное окно

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	srand(time(NULL));

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
			// создание списков сталкивающихся объектов
			CollisionsLists col_lst;			

			// создание самолетов
			col_lst.m_aircrafts = new ManObjList(
				{
					new LightAircraft(hdc, 0),
					new FastAircraft(hdc, 1),
					new VeryFastAircraft(hdc, 2),
					new BrokenAircraft(hdc, 3)
				}
			);

			// создание барьеров
			col_lst.m_bars = new ManObjList(
				{
					 new Mountain(hdc, 0),
					 new Mountain(hdc, 1),
					 new Mountain(hdc, 2),
					 new Mountain(hdc, 3),
					 new Mountain(hdc, 4),
					 new UpgradeTower(hdc, 5),
					 new DowngradeTower(hdc, 6),
				}
			);

			// создание матрицы переходов
			// m_collis_mat[i][j] = t
			// i - номер самолета из массива aircrafts
			// j - номер препятствия из массива bars
			// t - номер полученного после пересечения самолета из массива aircrafts
			col_lst.m_collision_matrix = new IntMatrix(
				{
					{3, 3, 3, 3, 3, 1, 0},
					{3, 3, 3, 3, 3, 2, 0},
					{3, 3, 3, 3, 3, 2, 1},
					{3, 3, 3, 3, 3, 3, 3},
				}
			);

			// создание ракет (изначально их нет)
			col_lst.m_missiles = new ManObjList;

			// создание управляющего коллизиями
			CollisionController controller(hdc, col_lst);

			// главный цикл программы
			while (!KEY_DOWN(K_EXIT))
			{
				controller.ProcessDraw();
				controller.ProcessLogic();
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
