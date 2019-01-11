#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main1()
{
	//FILE *fp;
	//fp = fopen("D:/test/test.txt","w+");
	//fprintf(fp,"this is testing fprintf \n");
	//fputs("this is testing fputs\n", fp);
	//fclose(fp);

	//return 0;


	FILE *fp = NULL;
	char buff[255];

	fp = fopen("D:/test/test.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1:%s\n", buff);

	fgets(buff, 255, fp);
	printf("2:%s\n", buff);

	fgets(buff, 255, fp);
	printf("3:%s\n", buff);

	fclose(fp);

	system("pause");


	return 0;
}