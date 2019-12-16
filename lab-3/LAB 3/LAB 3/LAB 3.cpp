#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include "Combi.h"
#include "Salesman.h"
#include "Auxil.h"
#include <time.h>
#define N (sizeof(AA)/2)
#define M 3
#define N1 5
#define SPACE(y) std::setw(y)<<" "
#define N2 5

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	
	int d[N1][N1] = {//0   1   2   3   4        
		{  INF, 10, 26, INF, 5},    //0
		{ 5,  INF,  20, 63, 79 },   //1
		{ 7, 15, INF, 86, 54 },      //2 
		{ 22, 53, 20, INF, 15 },       //3
		{ 88, 71, 52, 18, INF}, };   //4  
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

	system("pause");
	return 0;
}
