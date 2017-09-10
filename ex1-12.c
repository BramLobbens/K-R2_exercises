/* K&R2 exercise 1-12, page 21 */

#include <stdio.h>

main()
{
    int c;
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }
}