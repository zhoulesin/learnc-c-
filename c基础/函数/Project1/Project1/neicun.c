#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char name[100];
	char * desc;
	strcpy(name, "fsddf");

	desc = (char *)malloc(30 * sizeof(char));
	if (desc == NULL) {
		fprintf(stderr, "errrrrr");
	}
	else {
		strcpy(desc, "aaaaa");
	}

	//���·����ڴ�
	realloc(desc,100 * sizeof(char));
	if(desc == NULL){
		fprintf(stderr, "errrrrr");
	}
	else {
		strcat(desc, "addddddd");
	}

	printf("name=%s\n", name);
	printf("desc=%s\n", desc);

	//�ͷ��ڴ�
	free(desc);

	printf("desc=%s\n", desc);

	system("pause");

	return 0;

}