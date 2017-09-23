#include <stdio.h>

main()
{
    int unsigned num;
    num = 183;
    
    printf("%d\n", bitcount(num));
    
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    
    for (b = 0; x != 0; x &= (x - 1))
    {
        b++;
    }
    return b;
}