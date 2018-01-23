/* K&R2 exercise 5-5, page 107 */

#include <stdio.h>

#define MAXLINE 1000
#define NUM 20

void _strncopy(char *s, char *t, int n);
void _strncat(char *s, char *t, int n);
int _strncmp(char *s, char *t, int n);

int main(void)
{
    char from[MAXLINE] = "The man in black fled across the desert";
    char to[MAXLINE];
    char ct[] = " and the gunslinger followed";
    char line1[] = "test driven development";
    char line2[] = "test driven envelopement";

    _strncopy(from, to, NUM);
    printf("%s\n", to);

    _strncat(&from[0], &ct[0], NUM);
    printf("%s\n", from);

    printf("%d\n", _strncmp(&line1[0], &line2[0], NUM));
    printf("%d\n", _strncmp(&line1[0], &line2[0], 4));

    return 0;
}

void _strncopy(char *s, char *t, int n)
{
    while (n-- && (*t++ = *s++) != '\0')
    {
	; /* copy s to t for len of n or until end of t */
    }
    *t = '\0';
}

void _strncat(char *s, char *t, int n)
{
    while (*s != '\0') /* find end of s */
    {
	s++;
    }
    while (n-- && (*s++ = *t++) != '\0')
    {
	; /* copy t for len of n or until end of t */
    }
    *s = '\0';
}

int _strncmp(char *s, char *t, int n)
{
    for ( ; *s == *t; s++, t++, n--)
    {
	if (*s == '\0' || n == 0)
	    /* equal if end of string or n reached */
	    return 0;
    }
    return *s - *t;
}
