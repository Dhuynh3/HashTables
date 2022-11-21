#include <windows.h>
#include <iostream>

int main() {


	for (int i = 0; i < 100; i++) {

		int res = i % 50;
		printf("Res :%i	Index :%i\n", res, i);

	}

	return 0;
}