#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include "Combi.h"
#include "Salesman.h"
#include "Auxil.h"
#include <time.h>
#define N (sizeof(AA)/2)
#define M 3
#define N1 10
#define SPACE(y) std::setw(y)<<" "
#define N2 10

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	//Задание 1
	std::cout << "----Задача 1---" << std::endl;
	char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " - Генератор множества всех подмножеств -";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация всех подмножеств  ";
	combi::subset s1(sizeof(AA) / 2);         // создание генератора   
	int  n = s1.getfirst();                   // первое (пустое) подмножество  //сформормировать массив индексов по битовой маске    
	while (n >= 0)                            // пока есть подмножества 
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n; i++)
			std::cout << AA[s1.ntx(i)] << ((i< n - 1) ? ", " : " ");  // получить i-й элемент массива индексов
		std::cout << "}";
		n = s1.getnext();                   // cледующее подмножество 
	};
	std::cout << std::endl << "всего: " << s1.count() << std::endl;

	//Задание 2
	std::cout << "----Задача 2---" << std::endl;
	char  BB[][2] = { "A", "B", "C", "D", "E" };
	std::cout << std::endl << " --- Генератор сочетаний ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(BB) / 2; i++)

		std::cout << BB[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(BB) / 2, 3);
	std::cout << "из " << xc.nn << " по " << xc.mm; // из исходного сколько сочетаний
	int  nn = xc.getfirst();
	while (nn >= 0)
	{

		std::cout << std::endl << xc.nc << ": { ";

		for (int i = 0; i < nn; i++)


			std::cout << BB[xc.ntx(i)] << ((i< nn - 1) ? ", " : " "); // номер сочетания  

		std::cout << "}";

		nn = xc.getnext();
	};
	std::cout << std::endl << "всего: " << xc.count() << std::endl;

	//Задание 3
	std::cout << "----Задача 3----" << std::endl;
	char  CC[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- Генератор перестановок ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(CC) / 2; i++)

		std::cout << CC[i] << ((i< sizeof(CC) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация перестановок ";
	combi::permutation p(sizeof(CC) / 2);
	__int64  nnn = p.getfirst();
	while (nnn >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";

		for (int i = 0; i < p.nnn; i++)

			std::cout << CC[p.ntx(i)] << ((i< p.nnn - 1) ? ", " : " ");

		std::cout << "}";

		nnn = p.getnext();
	};
	std::cout << std::endl << "всего: " << p.count() << std::endl;

	//Задание 4
	std::cout << "----Задача 4---" << std::endl;
	char  DD[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- Генератор размещений ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++)

		std::cout << DD[i] << ((i< N - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
	combi::accomodation s(N, M);
	int  n4 = s.getfirst();
	while (n4 >= 0)
	{

		std::cout << std::endl << std::setw(2) << s.na << ": { ";

		for (int i = 0; i < M; i++)

			std::cout << DD[s.ntx(i)] << ((i< n4 - 1) ? ", " : " ");

		std::cout << "}";

		n4 = s.getnext();
	};
	std::cout << std::endl << "всего: " << s.count() << std::endl;


	//Задание 5
	std::cout << "-----Задача 5----" << std::endl;
	int d[N1][N1] = {//0   1   2   3   4   5   6   7   8   9      
		{ 0,  45, INF, 25, 50, 120, 210, 75, 65, 290 },    //0
		{ 45,  0,  55, 20, 100, 210, 65, 86, 150, 140 },   //1
		{ 70, 20, 0, 10, 30, INF, 210, 75, 25, 170 },      //2 
		{ 80, 10, 40, 0, 10, 65, 120, 25, 50, 110 },       //3
		{ 30, 50, 20, 10, 0, 145, 90, 230, 15, 40 },       //4
		{ 20, 45, INF,25, 50, 0, 150, 70, 65, 90 },        //5
		{ 60, 15, 40, 120, 30, 50, 0, 77, 120, 15 },       //6
		{ 20, 45, 15 ,25, 50, 45, 150, 0, 65, 90 },        //7
		{ 30, 15, 60,45, 70, 250, 10, 70, 0, 75 },         //8
		{ 120, 40, 140,250, 50, 10, 130, 70, 65, 0 }, };   //9  
	int r[N1];                     // результат 
	int ss = salesman(
		N1,                        // [in]  количество городов 
		(int*)d,                   // [in]  массив [n*n] расстояний 
		r                          // [out] массив [n] маршрут 0 x x x x  

	);
	std::cout << std::endl << "-- Задача коммивояжера -- ";
	std::cout << std::endl << "-- количество  городов: " << N1;
	std::cout << std::endl << "-- матрица расстояний : ";
	for (int i = 0; i < N1; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N1; j++)

			if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

			else std::cout << std::setw(3) << "INF" << " ";
	}
	std::cout << std::endl << "-- оптимальный маршрут: ";
	for (int i = 0; i < N1; i++) std::cout << r[i] << "-->"; std::cout << 0;
	std::cout << std::endl << "-- длина маршрута     : " << ss;
	std::cout << std::endl;

	//Задание 6
	std::cout << "---Задача 6---" << std::endl;
	int dd[12*12 + 1], rr[12];
	auxil::start();
	for (int i = 0; i <= 12*12; i++)
		dd[i] = auxil::iget(10, 100);
	std::cout << std::endl << "-- Задача коммивояжера -- ";
	std::cout << std::endl << "-- количество ------ продолжительность -- ";
	std::cout << std::endl << "      городов           вычисления  ";
	clock_t t1, t2;
	for (int i = 5; i <= 12; i++)
	{
		t1 = clock();
		salesman(i, (int*)dd, rr);
		t2 = clock();
		std::cout << std::endl << SPACE(7) << std::setw(2) << i
			<< SPACE(15) << std::setw(5) << (t2 - t1);
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
