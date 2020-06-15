#ifndef is_little_endian_
#define is_little_endian_
#include <stdio.h>

int is_little_endian()
{
	int x = 1;
	char* p = (char*)&x;
	return p[0] & 0x1;
}

void print_endian()
{
	if (is_little_endian())
		printf("This is a little endian computer.");
	else
		printf("This is a big endian.");
}
#endif