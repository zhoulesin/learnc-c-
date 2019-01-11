#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) (x>y?x:y)

int main123() {

	char aa[] = { 'a','1','f' };

	printf("max is %d\n", MAX(aa, 55));
	system("pause");
	return 0;
}