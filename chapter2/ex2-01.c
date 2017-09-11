#include <stdio.h>
#include <limits.h>
#include <float.h>

#define NILL 0

/* determine the ranges of char, short, int and long, signed and unisgned
   as well as for float and double */
main()
{
    printf("unsigned char: %u to %u\n", NILL, UCHAR_MAX);
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned short: %d to %d\n", NILL, USHRT_MAX);
    printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned int: %u to %u\n", NILL, UINT_MAX);
    printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned long: %u to %lu\n",NILL, ULONG_MAX);
    printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    
    printf("float: %.0f to %.10e\n", FLT_MIN, FLT_MAX);
    printf("double: %.0f to %.10e\n", DBL_MIN, DBL_MAX);

    return 0;
}