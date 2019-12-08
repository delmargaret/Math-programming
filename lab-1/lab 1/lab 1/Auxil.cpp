
#include "stdafx.h"
#include "Auxil.h" 
#include <ctime>    



namespace auxil
{
	void start()     // старт  генератора сл. чисел
	{
		srand((unsigned)time(NULL));
	};
	double dget(double a, double b) // получить случайное число
	{
		return ((double)rand() / (double)RAND_MAX)*(b - a) + a;
	};
	int iget(int a, int b)         // получить случайное число
	{
		return (int)dget((double)a, (double)b);
	};
}
