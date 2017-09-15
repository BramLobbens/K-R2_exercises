#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int htoi(char line[]);
int getline(char line[], int maxline);

main()
{
    int len; /* current line length */
    char hex[MAXLINE]; /* hexadecimal input line */
    char dec[MAXLINE]; /* decimal output line */
    
    while ((len = getline(hex, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            printf("%d\n", htoi(hex));
        }
        else
        {
            printf("%s\n", "");
        }
    }
    
    return 0;
}

/* htoi: convert s (string of hexadecimal digits) to integer */
int htoi(char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0; isdigit(s[i]) ||
    (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'x'); ++i)
    {
        /* ignore initial 0x values */
        if ((s[i] == '0' && i == 0) || (tolower(s[i]) == 'x' && i == 1))
        {
            n = 0; 
        }
        /* 0-9 base 16 */
        else if isdigit(s[i])
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
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}