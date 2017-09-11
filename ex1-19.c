#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char line[], char reversed[], int linesize);

/* print input line in reverse */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char reversed[MAXLINE]; /* reversed output line */
    
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 2) {
            reverse(line, reversed, len);
            printf("%s", reversed);
        } else { 
            printf("%s", line);
        }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse input line s */
void reverse(char s[], char rev[], int len)
{
    int i;
    len -= 2; /* ignore '\n' and '\0' chars */
    
    for (i=0; i <= len; ++i) {
        rev[i] = s[len-i];
    }
    rev[++len] = '\n';
    rev[++len] = '\0';
}