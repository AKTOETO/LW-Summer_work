#pragma once
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

	//виртуальные ф-ии (позднее связывание)
	virtual void Show(); //показать ТОЧКУ на экране
	virtual void Hide();//скрыть ТОЧКУ 

	//ф-ии для раннего связывания
	//void Show(); //показать ТОЧКУ на экране
	//void Hide();//скрыть ТОЧКУ 
	void MoveTo(int NewX, int NewY);//переместить фигуру
};//Point
/*-----------------------------------*/
/*          КЛАСС Aircraft           */
/*-----------------------------------*/
class Aircraft :public Point
{
protected:
	int Radius; //радиус лица
	int EyeColor; //цвет глаз (0 - КРАСНЫЙ, 1 - КОРИЧНЕВЫЙ, 2 - ЧЕРНЫЙ, 3 - ЗЕЛЕНЫЙ)
public:
	Aircraft(int InitX, int InitY, int InitRadius, int InitEyeC); //конструктор
	~Aircraft(); //деструктор
	void Show(); //показать ЛИЦО на экране
	void Hide(); //скрыть ЛИЦО

	//ф-ии для раннего связывания
	/*void MoveTo(int NewX, int NewY);*/
};
//Цвет глаз
enum Color
{
	Red, Brown, Black, Green
};