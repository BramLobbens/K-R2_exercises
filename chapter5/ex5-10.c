/* K&R2 exercise 5-10, page 118 */
/**
 * Usage: use '\*' as input instead of '*' for multiplication in bash
 */

#include <stdio.h>
#include <stdlib.h> /* strtol() */

#define MAXVAL 100 /* maximum depth of the val stack */

int sp = 0; /* next free stack position */
int val[MAXVAL]; /* value stack */
int *pval = val;

void push(long int l)
{
    if (sp < MAXVAL)
	val[sp++] = l;
    else
	printf("error: stack full, can't push %ld\n", l);
}

long int pop(void)
{
    if (sp > 0)
	return val[--sp];
    else {
	printf("error: stack empty\n");
	return 0;
    }
}

int main(int argc, char *argv[])
{
    long int op2;

    while (--argc) {
	
	/* push only two numbers on stack */
	if (pval - 2 > 0) {
	    *++argv;
	    switch (**argv) {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
		push(strtol(*argv, NULL, 10));
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
		if (op2 != 0)
		    push(pop() / op2);
		else
		    printf("error: zero divisor\n");
		break;
	    default:
		printf("error: unknown command %s\n", *argv);
		break;
	    }
	}
    }
    printf("%ld\n", pop());
    return 0;
}
