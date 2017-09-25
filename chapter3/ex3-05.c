#include <stdio.h>
#include <string.h> /* strlen */

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
    char string_output[32];
    int num = 30;
    int base = 16;
    
    itob(num, string_output, base);
    
    printf("%s\n", string_output);
    return 0;
}

/* itob: convert int 'n' into a base 'b' char representation in string s */
void itob(int n, char s[], int b)
{
    int i;
    int sign = (n < 0) ? -1 : 1;
    
    i = 0;
    do
    {
        if (n >= 0 && n <= 9)
        {
            s[i++] = sign * (n % b) + '0';
        }
        else
        {
            s[i++] = sign * (n % b) - 10 + 'A';
        }
    }
    while ((n /= b) != 0);
    
    if (sign < 0)
    {
        s[i++] = '-';
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