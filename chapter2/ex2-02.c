#include <stdio.h>

#define MAXLINE 1000

main()
{
    int c, i;
    char line[MAXLINE];
    
    for (i=0; (i<MAXLINE-1 == ((c=getchar()) != EOF)) == (c != '\n'); ++i) 
    {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    printf("%s", line);
    return 0;
}