#include <stdio.h>
#include <string.h> /* strlen */

void itoa(int n, char s[], int m);
void reverse(char s[]);

main()
{
    char string_output[32];
    int num = -2147483648; /* max neg int value -(2**(32-1)) */
    int field_with = 16; /* total output length */
    
    itoa(num, string_output, field_with);
    
    printf("%s\n", string_output);
    return 0;
}

/* itoa: convert n to characters in s with left padding */
void itoa(int n, char s[], int m)
{
    int i;
    int sign = (n < 0) ? -1 : 1; /* adjusting n to -n fails for max neg value */
    
    i = 0;
    do
    {
        s[i++] = sign * (n % 10) + '0';
    } 
    while (sign * (n /= 10) != 0);
    
    if (sign < 0)
    {
        s[i++] = '-';
    }
    for (; i < m; ++i) /* add left padding */
    {
        s[i] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; ++i, --j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
