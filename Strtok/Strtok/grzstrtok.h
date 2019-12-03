#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDelim(char c, char* delim) {
	for (int i = 0; delim[i] != '\0'; i++)
		if (c == delim[i])
			return 1;
	return 0;
}

void skipDelims(char** str, char* delim) {
	while (isDelim(**str, delim)) (*str)++;
}

void skipNonDelims(char** str, char* delim) {
	while (!isDelim(**str, delim) && **str != '\0') (*str)++;
}

char* mstrtok(char* str, char* delim) {
	static char* prevEnd = NULL;
	if (str)
		prevEnd = str;
	if (prevEnd == NULL || *prevEnd == '\0')
		return NULL;

	skipDelims(&prevEnd, delim);
	char* start = prevEnd;
	skipNonDelims(&prevEnd, delim);

	if (*prevEnd != '\0') {
		*prevEnd = '\0';
		prevEnd++;
	}
	if (prevEnd == start)
		return NULL;
	return start;
}
