#include <stdio.h>
#include <stdlib.h>

double jiecheng(i);

int mainwere()
{
	int i = 15;
	printf("%d ½×³ËÊÇ %f\n",i,jiecheng(i) );

	system("pause");
	return 0;
}

double jiecheng(int i) {
	if (i <= 1) {
		return 1;
	}
	return i * jiecheng(i - 1);
}
