
#include "stdafx.h"
#include "Auxil.h" 
#include <ctime>    



namespace auxil
{
	void start()     // �����  ���������� ��. �����
	{
		srand((unsigned)time(NULL));
	};
	double dget(double a, double b) // �������� ��������� �����
	{
		return ((double)rand() / (double)RAND_MAX)*(b - a) + a;
	};
	int iget(int a, int b)         // �������� ��������� �����
	{
		return (int)dget((double)a, (double)b);
	};
}
