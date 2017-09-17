#include <stdio.h>
#include <ctype.h>

#define MAXLEN 18 /* max input: 0x7fffffffffffffff */

long htoi(char line[]);
int getline(char line[], int maxline);

main()
{
    int len, i; /* current line length */
    char hexvalue[MAXLEN+1]; /* hexadecimal input line + /0 term. */
    
    while ((len = getline(hexvalue, MAXLEN+1)) > 0)
    {
        if (len > 1)
        {
            printf("%ld\n", htoi(hexvalue));
        }
        
        for (i = 0; i < MAXLEN+1; ++i)
        {
            hexvalue[i] = ' ';
        }
    }
    
    return 0;
}

/* htoi: convert s (string of hexadecimal digits) to integer */
long htoi(char s[])
{
    int i, j; 
    long n;
    
    j = 0;
    /* skip past 0x value */
    if (s[0] == '0' && tolower(s[1]) == 'x')
    {
        j = 2;
    }
    
    n = 0;
    for (i = j; isdigit(s[i]) ||
        (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'); ++i)
    {
        /* 0-9 base 16 */
        if isdigit(s[i])
        {
            n = 16 * n + (s[i] - '0');
        }
        /* a-f base 16 */
        else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
        {
            n = 16 * n + ((tolower(s[i]) - 'a') + 10);
        }
    }
    
    return n;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
         s[i] = c;
    }
    s[++i] = '\0';
    
    return i;
}