#define _CRT_SECURE_NO_WARNINGS
#include "gongju.h"

int main33(void)
{
	//int res = fun1(1, 3);

	//printf("%d\n", res);

	//int resss = max23(22, 33);
	//printf("%d\n", resss);

	//char[3] aa = { 'h','e','\0' };
	//printf("char mess :%s \n", aa);

	char str[100];
	int i = 1;
	char a;

	printf("Enter a value:");
	scanf("%s %d %c", &str, &i, &a);
	printf("\nyou enter:%s %d %c ",str
	,i,a);
	printf("\n");

	system("pause");

	return 0 ;

}

int fun1(int a,int b) {
	return a + b;
}