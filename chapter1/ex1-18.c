/* K&R2 exercise 1-18, page 31 */

/* compile (gcc) with flag: -ansi or -std=c89 to resolve conflicting library
   function getline()
   // comments, not supported in ANSI C */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);

/* remove trailing blanks and tabs and blank lines */
main()
{
    int len, i;
    char line[MAXLINE];
    
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > 1) /* blank lines (length 1) won't be printed */
        {
            for (i = len-1; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'); --i)
            {
                ;
            }
            line[++i] = '\n';
            line[++i] = '\0';
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