/* K&R2 exercise 4-13, page 88 */

#include <stdio.h>
#include <string.h> /* strlen */

void reverse(char s[], int first, int last);

main()
{
    char s[] = "The quick brown fox jumps over the lazy dog";
    int len = strlen(s);
    reverse(s, 0, len - 1);

    printf("%s\n", s);
    return 0;
}

/* reverse: reverse characters in string s */
void reverse(char s[], int first, int last)
{
    char temp = s[first];
    s[first] = s[last];
    s[last] = temp;

    if (first < last)
    {
        reverse(s, ++first, --last);
    }
}
