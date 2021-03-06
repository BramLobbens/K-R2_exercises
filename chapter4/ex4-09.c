/* K&R2 exercise 4-9, page 79 */
/* Solution: EOF is defined as -1, change buffer type from char to in */

#include <stdio.h>
#include <stdlib.h> /* atof() */
#include <math.h> /* sin(), exp(), pow() */ /* link with -lm flag */
#include <string.h> /* strlen() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VARIABLE 'a' /* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);
double head(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
main()
{
    int type;
    double op2, var;
    char s[MAXOP];

    printf("head: '#'%-6cduplicate: '&'%-6cswap: '?'%-6cclear: '!'\n", ' ', ' ', ' ');
    printf("sine: 's'%-6cpow: '^'%-12cexp: 'e'\n", ' ', ' ');
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:
                if (var == head())
                {
                    duplicate();
                }
                else
                {
                    var = head();
                }
                break;
            case '=': /* assign variables */
                push(var);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case 's':
                push(sin(pop()));
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '#':
                printf("head: %g\n", head());
                break;
            case '&':
                duplicate();
                break;
            case '?':
                swap();
                break;
            case '!':
                clear();
                printf("caution: stack is cleared\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* head: return top value from stack without popping */
double head(void)
{
    if (sp > 0)
    {
        return val[sp - 1];
    }
    else
    {
        return 0.0;
    }
}

/* duplicate: duplicate top of the stack */
void duplicate(void)
{
    push(head());
}

/* swap: swap the top two elements of the stack */
void swap(void)
{
    int tmp = head();
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
}

/* clear: clear the stack */
void clear(void)
{
    while (sp-- != 0)
    {
        val[sp] = 0.0;
    }
}

#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';

    i = 0;
    if (c == '-')
    {
        if (isdigit(c = getch()))
        {
            s[++i] = c;
        }
        else
        {
            ungetch(c);
            return '-';
        }
    }
    if (!isdigit(c) && c != '.')
    {
        return c; /* not a number */
    }
    if (tolower(c) >= 'a' && tolower(c) <= 'z' && tolower(c) != 'e' && tolower(c) != 's')
    {
        return VARIABLE;
    }
    if (c == '=')
    {
        return c;
    }
    if (isdigit(c)) /* collect integer part */
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.') /* collect fraction part */
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}

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

