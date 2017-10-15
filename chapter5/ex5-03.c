/* K&R2 exercise 5-3, page 107 */

#include <stdio.h>

#define MAXLINE 1000

void _strcat(char *s, char *t);

main()
{
    char line1[MAXLINE] = "The quick brown fox ";
    char line2[] = "jumps over the lazy dog";

    _strcat(&line1[0], &line2[0]);
    printf("%s\n", line1);

    return 0;
}

/* strcat: concatenate t to end of s; s must be big enough */
void _strcat(char *s, char *t)
{
    while (*s != '\0') /*find end of s */
    {
        s++;
    }
    while ((*s++ = *t++) != '\0') /* copy t */
    {
        ;
    }
}