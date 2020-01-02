#include "pch.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "rus");
	const char first[] = "сон";
	const char second[] = "донор";

	int distance = levenshtein_r(sizeof(first)-1, first, sizeof(second)-1, second);
	
	std::cout << "L(" << first << ", " << second << ") = " << distance << std::endl;

	const int firstStringLength = 300;
	const int secondStringLength = 250;
	const double numberOfChars[] = { 1./25., 1./20., 1./15., 1./10., 1./5., 1./2., 1 };

	char firstRandomString[firstStringLength + 1] = "";
	char secondRandomString[secondStringLength + 1] = "";

	GetRandomString(firstRandomString, firstStringLength);
	GetRandomString(secondRandomString, secondStringLength);

	clock_t t1 = 0, t2 = 0, t3, t4;

	std::cout << std::endl << "-- Levenshtein Distance -----" << std::endl;
	std::cout << std::endl << "--% of chars --- recursion -- dynamic progr. ---"
		<< std::endl;

	char firstPrefix[firstStringLength + 1] = "";
	char secondPrefix[secondStringLength + 1] = "";

	/*int sizeOfArray = sizeof(numberOfChars) / sizeof(double);

	for (int i = 0; i < sizeOfArray; i++) {
		int firstStrlen = (int)(numberOfChars[i] * firstStringLength);
		strncpy_s(firstPrefix, firstStringLength + 1, firstRandomString, firstStrlen);
		firstPrefix[firstStrlen + 1] = 0;

		int secondStrlen = (int)(numberOfChars[i] * secondStringLength);
		strncpy_s(secondPrefix, secondStringLength + 1, secondRandomString, secondStrlen);
		secondPrefix[secondStrlen + 1] = 0;

		t1 = clock();
		levenshtein_r(firstStrlen, firstPrefix, secondStrlen, secondPrefix);
		t2 = clock();

		t3 = clock();
		levenshtein(firstStrlen, firstPrefix, secondStrlen, secondPrefix);
		t4 = clock();

		std::cout.precision(1);
		std::cout << std::right << std::setw(2) 
			<< "     " << std::fixed << numberOfChars[i] * 100 << std::setw(2)
			<< "            " << std::left << std::setw(10) << (t2 - t1)
			<< "       " << std::setw(10) << (t4 - t3) << std::endl;

		firstPrefix[0] = 0;
		secondPrefix[0] = 0;
	}*/




	//for (int i = 8; i < std::min(firstStringLength, secondStringLength); i++)
	//{
	//	t1 = clock(); 
	//	levenshtein_r(i, firstRandomString, i - 2, secondRandomString); 
	//	t2 = clock();
	//	
	//	t3 = clock(); 
	//	levenshtein(i, firstRandomString, i - 2, secondRandomString); 
	//	t4 = clock();
	//	
	//	std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
	//		<< "        " << std::left << std::setw(10) << (t2 - t1)
	//		<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	//}
	system("pause");
	return 0;	
}

