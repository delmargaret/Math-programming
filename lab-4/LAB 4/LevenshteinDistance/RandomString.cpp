#include "pch.h"
#include <stdlib.h>
#include <time.h>

void GetRandomString(char* str, const int stringLength) {
	srand(time(NULL));
	static const char alphabet[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < stringLength; ++i) {
		str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
	}

	str[stringLength] = 0;
}
