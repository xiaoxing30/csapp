#pragma once
#include <stdio.h>
 /*
  * Generate mask indicating leftmost 1 in x. Assume w = 32.
  * For example, 0xff00 -> 0x8000, and 0x6600 -> 0x4000;
  * If x = 0, then return 0.
  */
 /*
  * Your code should contain a total of at most 15 arithmetic, bitwise, and logical
  * operations.
  * Hint: First transform x into a bit vector of the form [O �� �� �� 011 �� . �� 1].
  */

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    /* �������ǵõ���һ���µ�λ���ϣ�Xn��xn��xnǰ��ÿһλ|��Ľ�������� X0 = x0|x1|x2|...|x30|x31. 
     * ��ʱ��XΪ����[0...011...1]��λ�������������ǿ��Ժ����׿��� leftmost 1 in x. 
    */
    return x ^ (x >> 1);    /* the bit of leftmost 1 in x is different from the same bit of (x >> 1), all other bits are the same. 
                               so, the result of ^ is [0...010...0] , the bit of 1 is the bit of leftmost 1 in x. */
}

void test_hw2_66()
{
    unsigned a = 0x80000000;
    unsigned b = 0x66000000;
    unsigned c = 0xff000000;
    unsigned d = 0;
    printf("%#x\n", leftmost_one(a));
    printf("%#x\n", leftmost_one(b));
    printf("%#x\n", leftmost_one(c));
    printf("%#x\n", leftmost_one(d));
}