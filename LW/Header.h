#pragma once

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*-----------------------------------------------------------------*/
/*               Р Е А Л И З А Ц И Я   К Л А С С О В               */
/*-----------------------------------------------------------------*/

/*-----------------------------------*/
/*          КЛАСС Location           */
/*-----------------------------------*/
//базовый класс
class Location
{
protected:
	int X;
	int Y;
public:
	Location(int InitX, int InitY); //конструктор
	~Location(); //деструктор
	int GetX(); //получить значение поля X READ
	int GetY(); //получить значение поля Y 
	void SetX(int NewX)  //заменить значение поля X WRITE
	{ 
		X = NewX;
	};
	void SetY(int NewY) //заменить значение поля Y
	{ 
		Y = NewY;
	}; 
};//Location

/*-----------------------------------*/
/*            КЛАСС Point            */
/*-----------------------------------*/
//Производный класс
class Point : public Location
{
protected:
	bool Visible; //светиться точка или нет
public:
	Point(int InitX, int InitY); //конструктор
	~Point(); //деструктор
	bool IsVisisble(); //узнать про светимость точки
	void SetVisible(bool NewVisible) { Visible = NewVisible; }; //поменять светимость

	// виртуальные ф-ии (позднее связывание)
	virtual void Show(); //показать ТОЧКУ на экране
	virtual void Hide();//скрыть ТОЧКУ 
	void Drag(); // движение объекта

	//ф-ии для раннего связывания
	//void Show(); //показать ТОЧКУ на экране
	//void Hide();//скрыть ТОЧКУ 
	//void Drug(); // движение объекта

	// движение 
	void MoveTo(int NewX, int NewY);//переместить фигуру

};//Point


/*-----------------------------------*/
/*          КЛАСС Aircraft           */
/*-----------------------------------*/
class Aircraft :public Point
{
private:
	void Draw();

public:
	Aircraft(int InitX, int InitY); //конструктор
	~Aircraft(); //деструктор

	// виртуальные ф-ии (позднее связывание)
	void Show(); //показать на экране
	void Hide(); //скрыть

	// раннего связывания
	//void MoveTo(int NewX, int NewY);
};