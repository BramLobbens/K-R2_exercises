/* K&R2 exercise 4-11, page 83 */

#define NUMBER '0'

/* stack.c */
void push(double);
double pop(void);

/* getop.c */
int getop(char []);

/* getch.c */
int getch(void);
void ungetch(int);