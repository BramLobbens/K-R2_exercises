/* K&R2 exercise 1-9, page 20 */

#include <stdio.h>

main()
{
    int c;
    int blanks;
    
    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++blanks;
        }
        else
        {
            blanks = 0;
        }
        if (blanks <= 1)
        {
            putchar(c);
        }
        
    }
}