/* K&R2 exercise 5-1, page 97 */

#include <stdio.h>
#define SIZE 4

int getint(int *);

main()
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    {
        ;
    }

    while (n--)
    {
        printf("array[%d] -> '%d'\n", n, *(array + n));
    }
    return 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, val;

    while (isspace(c = getch())) /* skip whitespace */
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    if (val = (c == '-' || c == '+'))
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
        }
        else
        {
            ungetch(c = (sign == -1) ? '-' : '+' );
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

#include <stdio.h>
#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}