#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grzstrtok.h"

int main()
{
	char str[] = "Hello, world, dear Intel users\n";
	char* (*func) (char*, char*);
	func = mstrtok;
	char* pch = mstrtok(str, " ,.-");

	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = mstrtok(NULL, " ,.-");
	}

	printf("\n");
	char str2[] = "AAAAAAAAAAAAAAAAAAAAAA B CCCCCCCC";

	pch = mstrtok(str2, " ");

	while (pch != NULL)
	{
		if (strcmp(pch, "B") == 0) printf(" BBBBBBBBBBB ");
		else printf("%s", pch);
		pch = mstrtok(NULL, " ,-!");
	}

	return 0;
}
