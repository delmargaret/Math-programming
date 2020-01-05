#include "pch.h"
#include "RandomString.h"
#include "Levenshtein.h"

using namespace std;

int main()
{
	srand(time(NULL));

	const int firstStringLength = 300;
	const int secondStringLength = 250;
	const double numberOfChars[] = { 1./50., 1./40., 1./35., 1./30., 1./25., 1./20 };

	char firstRandomString[firstStringLength + 1];
	char secondRandomString[secondStringLength + 1];

	GetRandomString(firstRandomString, firstStringLength);
	GetRandomString(secondRandomString, secondStringLength);

	cout << endl << "-- Levenshtein Distance -----" << endl;
	cout << endl << "--length --- recursion -- dynamic progr. -- LDistancde--- "
		<< endl;

	int sizeOfArray = sizeof(numberOfChars) / sizeof(double);

	for (int i = 0; i < sizeOfArray; i++) {
		int firstStrlen = (int)(numberOfChars[i] * firstStringLength);
		int secondStrlen = (int)(numberOfChars[i] * secondStringLength);

		clock_t t1 = clock();
		int distance = levenshtein_r(firstStrlen, firstRandomString, secondStrlen, secondRandomString);
		clock_t t2 = clock();

		clock_t t3 = clock();
		levenshtein(firstStrlen, firstRandomString, secondStrlen, secondRandomString);
		clock_t t4 = clock();

		cout << right << setw(2) << firstStrlen << "/" << setw(2) << secondStrlen
			<< "        " << left << setw(10) << (t2 - t1)
			<< "   " << setw(10) << (t4 - t3) 
			<< "        " << setw(2) << distance << endl;
	}

	system("pause");
	return 0;	
}

