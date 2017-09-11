/* K&R2 exercise 1-16, page 30 */

/* compile (gcc) with flag: -ansi or -std=c89 to resolve conflicting library
   function getline()
   // comments, not supported in ANSI C */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line (revised) */
main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
    {
        printf("\n");
        printf("%s", longest);
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
        ++i; /* keep counting for longest past max output */
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}