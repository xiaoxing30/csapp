#pragma once
#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise. 
   Assume w = 32 */
int odd_ones(unsigned x)
{
    x ^= (x >> 16);    //得到16个间隔16位的^ x0 = X0^X16
    x ^= (x >> 8);     //得到8个间隔8位的^   x0 = X0^X16^X8^X24 = X0^X8^X16^X24
    x ^= (x >> 4);     //得到4个间隔4位的^   x0 = X0^X16^X8^X24 ^ X4^X20^X12^X28
    x ^= (x >> 2);     //得到2个间隔2位的^   x0 = X0^X16^X8^X24 ^ X4^X20^X12^X28 ^ X2^X18^X10^X26^X6^X22^X14^X30
    x ^= (x >> 1);     //得到1个间隔1位的^   x0 = X0^X1^X2^...^X29^X30^X31
    
/*
    //还可以这么写
    x ^= (x >> 1);
    x ^= (x >> 2);
    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);
*/
    /* 此时, x 的最低位为所有位的^的结果，即 x31^x30^x29^...^x1^x0 , 由^的性质可知,奇数个1^的结果为1，偶数为0 */
    return x & 1;
}

void test_hw2_65()
{
    unsigned a = 0xffffffff;
    unsigned b = 0xfffffffe;
    printf("%d\n", odd_ones(a));
    printf("%d\n", odd_ones(b));
}