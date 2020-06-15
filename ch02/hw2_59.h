#pragma once
#include "showBytes.h"

int hw2_59(int x, int y)
{
	x &= (1 << 8) - 1;		// x���������Ч�ֽڣ�����λ������0
	y &= ((1 << (8 * sizeof(int))) - 1) << 8;	// y�������Ч�ֽڱ���0
	return x | y;
}

void test_hw2_59()
{
	int x = 0x89abcdef;
	int y = 0x76543210;
	int a = 0x12345678;
	int b = 0xabcdefab;
	show_int(hw2_59(x, y));
	show_int(hw2_59(a, b));
}