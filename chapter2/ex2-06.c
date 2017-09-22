#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned num, map;
    int position;
    int n;
    
    num = 16;
    map = 1;
    position = 4;
    n = 5;
    
    printf("%u\n", setbits(num, position, n, map));
    
    return 0;
}

/* setbits: returns x with the n bits that begin at position p set to the
rightmost n bits of y, leaving the other bits unchanged. */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((x >> (p + 1 - n)) ^ 0) | y;
}