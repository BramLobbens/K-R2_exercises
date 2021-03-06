#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned num;
    int position;
    int n;
    
    num = 16;
    position = 3;
    n = 3;
    
    printf("%u\n", invert(num, position, n));
    
    return 0;
}

/* invert: return x with the n bits that begin at the position p inverted, 
leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n)
{
    return x + (x >> (p + 1 - n)) ^ ~(~0 << n);
}