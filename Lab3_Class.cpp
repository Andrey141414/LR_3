
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <math.h>
class kompleksnoe_chislo {

private:
	float mnimaya_chast;
	float vechestv_chast;
public:
	
	//функция установки значений
	void Read();
	//функция получения значений
	void Init(float m_c, float v_c);
	//функция вывода
	void Display();
	kompleksnoe_chislo Add(kompleksnoe_chislo a, kompleksnoe_chislo b);
	kompleksnoe_chislo Raz(kompleksnoe_chislo a, kompleksnoe_chislo b);
	void compare(kompleksnoe_chislo a, kompleksnoe_chislo b);
	void zapolnenie_din_mass(kompleksnoe_chislo* mass, int N);
};
void kompleksnoe_chislo::Read()
{
	

	printf("Введите мнимую часть числа - ");
	scanf("%f", &mnimaya_chast);
	while (getchar() != '\n');
	system("cls");
	printf("Введите весчественную часть числа - ");
	scanf("%f", &vechestv_chast);
	while (getchar() != '\n');
	system("cls");


	while (getchar() != '\n');
}
void kompleksnoe_chislo::Init(float m_c, float v_c)
{
	mnimaya_chast = m_c;
	vechestv_chast = v_c;
}
void kompleksnoe_chislo::Display()
{

	printf(" %.1fi  + %.1f", mnimaya_chast, vechestv_chast);
	puts("");
}
void kompleksnoe_chislo::compare(kompleksnoe_chislo a, kompleksnoe_chislo b)
{
	char znak;

	printf("Сравнение чисел %.1fi + %.1f  и  %.1fi + %.1f \nпо модулю\n", a.mnimaya_chast, a.vechestv_chast, b.mnimaya_chast, b.vechestv_chast);
	float amod = sqrt(a.vechestv_chast * a.vechestv_chast + a.mnimaya_chast * a.mnimaya_chast);
	float bmod = sqrt(b.vechestv_chast * b.vechestv_chast + b.mnimaya_chast * b.mnimaya_chast);
	if (amod > bmod)
	{
		znak = '>';
	}
	if (amod < bmod)
	{
		znak = '<';
	}
	if (amod == bmod)
	{
		znak = '=';
	}

	printf("%.1fi + %.1f  %c  %.1fi + %.1f", a.mnimaya_chast, a.vechestv_chast, znak, b.mnimaya_chast, b.vechestv_chast);
}
kompleksnoe_chislo kompleksnoe_chislo::Add(kompleksnoe_chislo a, kompleksnoe_chislo b)
{
	kompleksnoe_chislo Summa;
	Summa.mnimaya_chast = a.mnimaya_chast + b.mnimaya_chast;
	Summa.vechestv_chast = a.vechestv_chast + b.vechestv_chast;
	return Summa;
}
kompleksnoe_chislo kompleksnoe_chislo::Raz(kompleksnoe_chislo a, kompleksnoe_chislo b)
{
	kompleksnoe_chislo Raznost;
	Raznost.mnimaya_chast = a.mnimaya_chast - b.mnimaya_chast;
	Raznost.vechestv_chast = a.vechestv_chast - b.vechestv_chast;
	return Raznost;
}
//Заполнение динамического массива
void kompleksnoe_chislo::zapolnenie_din_mass(kompleksnoe_chislo* mass, int N)
{
	int size = sizeof(kompleksnoe_chislo);
	kompleksnoe_chislo a ;
	a.mnimaya_chast = 0;
	a.vechestv_chast = 1;
	for (int i = 0; i < N; i++)
	{
		a.mnimaya_chast = a.vechestv_chast +1;
		a.vechestv_chast = a.mnimaya_chast +1;
		*(mass + i * size) = a;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	kompleksnoe_chislo A, B;
	
	//A.Init(2.1, -5.0);
	A.Read();
	puts("Числа A и B");
	A.Display();
	B.Init(2.1,-5.0);
	B.Display();
	puts("");
	system("pause");
	system("cls");

	kompleksnoe_chislo *Sum = new kompleksnoe_chislo;
	kompleksnoe_chislo* Raz; Raz = (kompleksnoe_chislo *)malloc(sizeof(kompleksnoe_chislo));

	(*Sum) = Sum->Add(A, B);
	puts("A+B");
	Sum->Display();
	

	puts("");
	system("pause");
	system("cls");


	puts("A-B");
	(*Raz) = Raz->Raz(A, B);
	Raz->Display();
	system("pause");
	system("cls");
	//удаление
	free(Raz);
	delete(Sum);



	//Массив динамических объектов класса 
	const int N = 3;
	



	//динамический массив
	
	kompleksnoe_chislo* dinmas;
	dinmas = new kompleksnoe_chislo[N];
	dinmas->zapolnenie_din_mass(dinmas, N);
	puts("Динамический массив");
	for (int i = 0; i < N; i++)
	{
		(dinmas+i*sizeof(kompleksnoe_chislo))->Display();
	}
	
	
	
	delete(dinmas);
	
}

