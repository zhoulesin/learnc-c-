#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double pingjun(int num, ...) {

	va_list valist;
	va_start(valist, num);
	double sum = 0.0;

	for (int i = 0; i < num; i++) {
		sum += va_arg(valist, int);
	}


	va_end(valist);

	return sum / num;

}

int main123333() {
	printf("2,3,4,5 = %f\n", pingjun(4, 2, 3, 4, 5));
	printf("5 10 15 = %f\n", pingjun( 3, 5,10,15));

	system("pause");
	return 0;
}

