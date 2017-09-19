#include <stdio.h>

#define MAXLINE 1000

int in_string(char c, char s[]);
int any(char s1[], char s2[]);
int getline(char s[],int lim);

main()
{
    int len;
    char input1[MAXLINE];
    char input2[MAXLINE];
    
    do
    {
        printf("s1: ");
    }
    while ((len = getline(input1, MAXLINE)) < 2);
    
    do
    {
        printf("s2: ");
    }
    while ((len = getline(input2, MAXLINE)) < 2);

    printf("%d\n", any(input1, input2));
    
    return 0;
}

/* any: return the first location in string s1 where any char from s2 occurs */
int any(char s1[], char s2[])
{
    int i;
    
    for (i = 0; s1[i] != '\0' && s1[i] != '\n'; ++i)
    {
        if (in_string(s1[i], s2))
        {
            return i;
        }
    }
    
    return -1;
}

/* in_string: return 1 if char c in string s, 0 otherwise */
int in_string(char c, char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
    int i, c;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
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