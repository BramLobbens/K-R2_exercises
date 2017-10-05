/* K&R2 exercise 5-2, page 97 */

#include <stdio.h>
#define SIZE 4

double getfloat(double *);

main()
{
    int n;
    double array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    {
        ;
    }

    while (n--)
    {
        printf("array[%d] -> '%g'\n", n, *(array + n));
    }
    return 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
double getfloat(double *pn)
{
    int c, sign;
    double power = 1.0;

    while (isspace(c = getch())) /* skip whitespace */
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0.0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    if (c == '-' || c == '+')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
        }
        else
        {
            ungetch((sign == -1) ? '-' : '+' );
            return 0.0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch()) /* get integer part */
    {
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.')
    {
        while (isdigit(c = getch())) /* get fraction part */
        {
            power *= 10.0;
            *pn = 10.0 * *pn + (c - '0');
        }
    }
    *pn /= power;
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
