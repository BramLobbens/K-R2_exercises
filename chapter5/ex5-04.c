/* K&R2 exercise 5-4, page 107 */

#include <stdio.h>
#include <string.h>

#define MATCH 1
#define MISMATCH 0

int strend(char *s, char *t);

main()
{
    char line1[] = "The quick brown fox jumps over the lazy dog";
    char line2[] = "jumps over the lazy dog"; /* match */
    char line3[] = "hops over the crazy dog"; /* mismatch */

    printf("Expected result: %d --> result: %d\n", MATCH, strend(&line1[0], &line2[0]));
    printf("Expected result: %d --> result: %d\n", MISMATCH, strend(&line1[0], &line3[0]));

    return 0;
}

/* strend: return 1 if the string t occurs at the end of the string s,
zero otherwise */
int strend(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    while (*(s + len_s--) == *(t + len_t--))
    {
        if (len_t == 0) /* string match */
        {
            return MATCH;
        }
    }
    return MISMATCH;
}