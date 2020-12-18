#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <math.h>
#include<string>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
string NAMES[5] = { "Пешка","Конь", "Слон", "Ладья", "Ферзь" };
class chess_figure {

private:
	int value;
	string name;
	//Если pawn = true: фигура является пешкой, если false, то не пешкой 

public:
	bool pawn = false;
	//функция установки значений
	void Read();
	//функция получения значений
	void Init(int val, string name);
	//функция вывода
	void Display();
	chess_figure Add(chess_figure a, chess_figure b);
	void compare(chess_figure b);
	void zapolnenie_din_mass(chess_figure* mass, int N);
	void pawn_promotion();
};
void chess_figure::Read()
{



	int vibor;
	puts("Название фигуры");
	for (int i = 0; i < 5; i++)
	{

		cout << i + 1 << " " << NAMES[i] << "\n";

	}

	cin >> vibor;
	name = NAMES[vibor - 1];
	switch (vibor)
	{
	case 1: {value = 1; pawn = true; }break;
	case 2: {value = 3; }break;
	case 3: {value = 3; }break;
	case 4: {value = 5; }break;
	case 5: {value = 9; }break;
	}
	system("cls");

}
void chess_figure::Init(int Val, string Name)
{
	value = Val;
	name = Name;
	if (Name == NAMES[0])
		pawn = true;
	else
		pawn = false;
}
void chess_figure::Display()
{

	cout << name << " Ценность " << value << "\n";


}
void chess_figure::compare(chess_figure b)
{
	system("cls");
	string comp;



	if (value > b.value)
	{
		comp = " Лучше чем ";
	}
	if (value < b.value)
	{
		comp = " Хуже чем ";
	}
	if (value == b.value)
	{
		comp = " не хуже и не лучше чем ";
	}
	cout << name << " " << comp << " " << b.name;

}
chess_figure chess_figure::Add(chess_figure a, chess_figure b)
{
	system("cls");
	chess_figure Summa;
	Summa.value = a.value + b.value;
	Summa.name = a.name + " и " + b.name;

	return Summa;
}
void chess_figure::pawn_promotion()
{
	puts("Ваша пешка дошла до конца доски");
	puts("Выбирите фигуру, в которую она превратится");
	int vibor;
	puts("Название фигуры");
	for (int i = 1; i < 5; i++)
	{

		cout << i << " " << NAMES[i] << "\n";

	}

	cin >> vibor;
	name = NAMES[vibor];
	switch (vibor)
	{

	case 1: {value = 3; }break;
	case 2: {value = 3; }break;
	case 3: {value = 5; }break;
	case 4: {value = 9; }break;
	}
	system("cls");

}

//Заполнение динамического массива
void chess_figure::zapolnenie_din_mass(chess_figure* mass, int N)
{
	int size = sizeof(chess_figure);

	for (int i = 0; i < N; i++)
	{
		chess_figure t;
		t.name = NAMES[i];
		switch (i)
		{
		case 0: {t.value = 1; }break;
		case 1: {t.value = 3; }break;
		case 2: {t.value = 3; }break;
		case 3: {t.value = 5; }break;
		case 4: {t.value = 9; }break;
		}



		*(mass + (i)) = t;


	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	chess_figure A, B;

	A.Read();
	A.Display();
	B.Init(3, "Конь");
	B.Display();
	puts("");
	system("pause");
	system("cls");

	chess_figure* Sum;
	Sum = new (chess_figure);
	//chess_figure* Raz; Raz = (chess_figure*)malloc(sizeof(chess_figure));

	(*Sum) = Sum->Add(A, B);
	Sum->Display();


	puts("");
	system("pause");
	system("cls");
	//Сравнение A и B
	A.compare(B);
	puts("");
	system("pause");
	system("cls");
	if (A.pawn == true)
	{
		A.pawn_promotion();
		A.Display();
		puts("");
		system("pause");
		system("cls");
	}
	delete(Sum);

	//Массив динамических объектов класса 
	int N = 5;




	//динамический массив
	chess_figure* dinmas = new chess_figure[N];
	dinmas->zapolnenie_din_mass(dinmas, N);
	puts("Динамический массив");
	for (int i = 0; i < N; i++)
		(dinmas + i)->Display();









}