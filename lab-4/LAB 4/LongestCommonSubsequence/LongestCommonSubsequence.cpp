#include "pch.h"
#include "LCS.h"

int main()
{
	setlocale(LC_ALL, "rus");
	char x[] = "HRWCYUJ", y[] = "WLPCAU";

	std::cout << std::endl
		<< "-- наибольшая общая подпоследовательость - LCS(рекурсия)" << std::endl;
	std::cout << std::endl << "последовательность X: " << x;
	std::cout << std::endl << "последовательность Y: " << y;
	int s = lcs_r(
		sizeof(x) - 1,  // длина   последовательности  X   
		x,       // последовательность X
		sizeof(y) - 1,  // длина   последовательности  Y
		y       // последовательность Y
	);

	std::cout << std::endl << "          длина LCS: " << s << std::endl;

	char z[100] = "";

	int l = lcs(x, y, z);

	std::cout << std::endl
		<< "-- наибольшая общая подпоследовательость - LCS(динамическое"
		<< "программирование)" << std::endl;
	std::cout << std::endl << "последовательость X: " << x;
	std::cout << std::endl << "последовательость Y: " << y;
	std::cout << std::endl << "                LCS: " << z;
	std::cout << std::endl << "          длина LCS: " << l;
	std::cout << std::endl;

	system("pause");
	return 0;

}
