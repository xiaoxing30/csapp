#pragma once

#include "showBytes.h"
unsigned srl(unsigned x, int k)
{/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;
	/* 思路是由k形成诸如0x00ffffff这样的掩码，与xsra进行&从而将高位置0 */
	unsigned w = sizeof(int) >> 3;
	unsigned mask = ~(((1 << k) - 1) << (w - k));
	/* (1<<k)-1 能够获得低位连续为1,高位为0的掩码,但不能全为1,于是继续向左移 w-k 然后取反 */
	return mask & xsra;
}

int sra(int x, int k)
{/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
	/* 这个题目的关键点是判断符号位是否为1,通过 test &= xsrl ，test为0如果符号位为0，否则test不变（处于符号位位置）*/
	unsigned w = sizeof(int) << 3;
	int test = 1 << (w - 1 - k);
	test &= xsrl;
	int mask = ~(test - 1);
	/* test为零时，~(test-1)为全零，不会改变xsrl; test不为零时，~(test-1)为符号位及其高位为1，其低位为0，改变xsrl */
	/* 思路是由k形成的诸如0xff000000或0x00000000这样的掩码，与xsrl进行|从而将高位置1或所有位保持不变 */
	return mask | xsrl;
}

void test_hw2_63()
{
	int x = 0x80000000;
	int xl = srl(x, 8);
	int xa = sra(x, 8);
	show_int(xl);
	show_int(xa);
}
