#pragma once
#include "showBytes.h"
unsigned replace_byte(unsigned x, int i, unsigned char b)
{// x = 0x12345678, i = 2, b = 0xab;
	unsigned xr = x & ((1 << i * 8) - 1);					// 0x00005678
	unsigned xl = (x >> (i + 1) * 8) << (i + 1) * 8;		// 0x12000000
	unsigned bt = (unsigned)b << (i * 8);					// 0x00ab0000
	return xr | xl | bt;									// 0x12ab5678
}

void test_hw2_60()
{
	unsigned x = 0x12345678;
	show_int(replace_byte(x, 2, 0xab));
	show_int(replace_byte(x, 0, 0xab));
}