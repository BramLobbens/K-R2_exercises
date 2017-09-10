/* K&R2 exercise 1-13, page 24 */

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 2 /* ourside a word */
#define MAX 10 /* maximum length of a word */

main()
{
    int c, i, state;
    int letter_count;
    int hist[MAX]; 
    for (i = 0; i < MAX; ++i)
    {
        hist[i] = 0;
    }
    
    state = OUT;
    letter_count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (letter_count > 0)
            {
                ++hist[letter_count];
            }
            letter_count = 0; /* reset letter count */
        }
        else if (state == OUT)
        {
            state = IN;
        }
        if (state == IN)
        {
            ++letter_count;
        }
    }
    printf("\n");
    
    for (i = 0; i < MAX; ++i)
    {
        printf(" %d", hist[i]);
    }
    printf("\n");
}