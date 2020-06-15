#pragma once

#include "showBytes.h"
unsigned srl(unsigned x, int k)
{/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;
	/* ˼·����k�γ�����0x00ffffff���������룬��xsra����&�Ӷ�����λ��0 */
	unsigned w = sizeof(int) >> 3;
	unsigned mask = ~(((1 << k) - 1) << (w - k));
	/* (1<<k)-1 �ܹ���õ�λ����Ϊ1,��λΪ0������,������ȫΪ1,���Ǽ��������� w-k Ȼ��ȡ�� */
	return mask & xsra;
}

int sra(int x, int k)
{/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
	/* �����Ŀ�Ĺؼ������жϷ���λ�Ƿ�Ϊ1,ͨ�� test &= xsrl ��testΪ0�������λΪ0������test���䣨���ڷ���λλ�ã�*/
	unsigned w = sizeof(int) << 3;
	int test = 1 << (w - 1 - k);
	test &= xsrl;
	int mask = ~(test - 1);
	/* testΪ��ʱ��~(test-1)Ϊȫ�㣬����ı�xsrl; test��Ϊ��ʱ��~(test-1)Ϊ����λ�����λΪ1�����λΪ0���ı�xsrl */
	/* ˼·����k�γɵ�����0xff000000��0x00000000���������룬��xsrl����|�Ӷ�����λ��1������λ���ֲ��� */
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
