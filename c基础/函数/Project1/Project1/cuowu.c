#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int mainaa()
{
	/*FILE *fp = NULL;
	fopen("D:/test/1.txt", "rb");
	int errnum;

	if (fp == NULL)
	{
		errnum = errno;
	}*/

	FILE * fp = fopen("D:/test/1.txt","rb");

	perror("³öÏÖµÄ´íÎó");

	char *errstr = strerror(errno);

	fprintf(stderr, "´íÎó:%s\n", errstr);

	system("pause");

	return 0;

}