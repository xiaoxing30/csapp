#pragma once
#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise. 
   Assume w = 32 */
int odd_ones(unsigned x)
{
    x ^= (x >> 16);    //�õ�16�����16λ��^ x0 = X0^X16
    x ^= (x >> 8);     //�õ�8�����8λ��^   x0 = X0^X16^X8^X24 = X0^X8^X16^X24
    x ^= (x >> 4);     //�õ�4�����4λ��^   x0 = X0^X16^X8^X24 ^ X4^X20^X12^X28
    x ^= (x >> 2);     //�õ�2�����2λ��^   x0 = X0^X16^X8^X24 ^ X4^X20^X12^X28 ^ X2^X18^X10^X26^X6^X22^X14^X30
    x ^= (x >> 1);     //�õ�1�����1λ��^   x0 = X0^X1^X2^...^X29^X30^X31
    
/*
    //��������ôд
    x ^= (x >> 1);
    x ^= (x >> 2);
    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);
*/
    /* ��ʱ, x �����λΪ����λ��^�Ľ������ x31^x30^x29^...^x1^x0 , ��^�����ʿ�֪,������1^�Ľ��Ϊ1��ż��Ϊ0 */
    return x & 1;
}

void test_hw2_65()
{
    unsigned a = 0xffffffff;
    unsigned b = 0xfffffffe;
    printf("%d\n", odd_ones(a));
    printf("%d\n", odd_ones(b));
}