/* K&R2 exercise 4-2, page 73 */

#include <stdio.h>
#include <ctype.h> /* isspace(), isdigit(), tolower() */

#define MAXLINE 32 /* maximum input line length */

int getline(char line[], int max);
double atof(char s[]);

/* print double from string */
main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0)
    {
        printf("%g\n", atof(line));
    }
    return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, j, k;

    for (i = 0; isspace(s[i]); i++) /* skip whitespace */
    {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i++]) == 'e')
    {
        if (s[i] == '-')
        {
            for (j = 0, k = ++i; isdigit(s[k]); k++) /* find power of e */
            {
                j = 10 * j + (s[k] - '0');
            }
            while (j-- > 0)
            {
                power *= 10.0;
            }
        }
        else /* if positive power */
        {
            for (j = 0, k = i; isdigit(s[k]); k++) /* find power of e */
            {
                j = 10 * j + (s[k] - '0');
            }
            while (j-- > 0)
            {
                val *= 10.0;
            }
        }
    }
    return sign * val / power;
}
