/* K&R2 exercise 1-17, page 31 */

/* compile (gcc) with flag: -ansi or -std=c89 to resolve conflicting library
   function getline()
   // comments, not supported in ANSI C */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define MINLINE 80 /*  minimum length of lines to be printed */

int getline(char line[], int maxline);

/* print all lines longer than 80 characters */
main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > MINLINE)
        {
            printf("%s", line);
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while ((c=getchar()) != EOF && c != '\n')
    {
        if (i < lim)
        {
            s[i] = c;
        }
        ++i; /* keep counting past max output */
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
