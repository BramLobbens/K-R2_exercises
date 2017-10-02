/* K&R2 exercise 4-12, page 88 */

#include <stdio.h>
#include <string.h> /* strlen */

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
    char string_output[32];
    int num = -2147483648; /* max neg int value -(2**(32-1)) */

    itoa(num, string_output);

    printf("%s\n", string_output);
    return 0;
}

/* itoa: convert n into a string */
void itoa(int n, char s[])
{
    static int i = 0;
    int j = 0;
    int sign = (n < 0) ? -1 : 1; /* adjusting n to -n fails for max neg value */

    if (sign < 0)
    {
        s[j++] = '-';
        i = j;
    }

    if (sign * (n / 10) != 0)
    {
        itoa(n / 10, s);
    }
    s[i++] = sign * (n % 10) + '0';

    s[i] = '\0';
}