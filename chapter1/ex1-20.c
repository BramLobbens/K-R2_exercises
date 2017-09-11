#include <stdio.h>

#define MAXLINE 1000 /* max line input size */
#define TABSIZE 4 /* 4 spaces */

int detab(char line[], int maxline);

/* replace tabs in input with spaces of length TABSIZE */
main()
{
    int len, i;
    char line[MAXLINE];
    
    while ((len = detab(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }
    return 0;
}

/* detab: read a line into s, replace tabs with spaces, return length */
int detab(char s[], int lim)
{
    int c, i, j;
    
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        if (c == '\t') 
        {
            s[i] = ' ';
            for (j = 1; j < TABSIZE; ++j) 
            {
                s[++i] = ' ';
            }
        } 
        else 
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