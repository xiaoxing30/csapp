#pragma once

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w = 32 */
int any_odd_one(unsigned x)
{
    /* when there is no odd bit of x equal 1, x&0x55555555 equal 0 */
    return !!(x & 0x55555555); /* 0x55555555 like: 0101 0101 0101 0101 ... */
}