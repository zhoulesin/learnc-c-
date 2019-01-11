#include <stdio.h>
#include <stdlib.h>

int mainsads()
{
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d\t\n", fibonaci(i));
	}

	system("pause");

	return 0;
}

int fibonaci(int i) {
	if (i == 0) {
		return 0;
	}

	if (i == 1)
	{
		return 1;
	}

	return fibonaci(i - 1) + fibonaci(i - 2);
}