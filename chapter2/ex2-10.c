#include <stdio.h>

int lower(char c);

main()
{
    char s = 'K';
    
    printf("%c\n", lower(s));
    return 0;
}

/* lower: convert uppercase letters to lowercase */
int lower(char c)
{
    return c = (c < 'a') ? c + ('a' - 'A') : c;
}