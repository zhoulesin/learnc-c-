#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mainssss()
{
	char name[100];

	strcpy(name, "sdsfdf");

	char *desc;

	desc = (char *)malloc(200 * sizeof(char));

	if (desc == NULL)
	{
		fprintf(stderr, "err happened");
	}
	else {
		strcpy(desc, "sfdsdfd");
	}

	printf("name:%s\n", &name);
	printf("desc:%s\n", desc);

	system("pause");

	return 0;
}