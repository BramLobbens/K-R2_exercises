/* buggy: to fix */

#include <stdio.h>

#define MAXLINE 1000

void expand(char from[], char to[]);

main()
{
    char input[MAXLINE];
    char output[MAXLINE];
    fgets(input, MAXLINE, stdin);
    
    expand(input, output);
    printf("%s", output);
    
    return 0;
}

void expand(char from[], char to[])
{
    int i, j, k;
    int start, end, flag, d;
    flag = 0;
    for (i = j = 0; i < MAXLINE - 1 && from[i] != '\n'; ++i)
    {
        if (from[i] == '-' && i == 0) /* check for leading dash */
        {
            to[j++] = from[i];
        }
        else if (tolower(from[i]) >= 'a' && tolower(from[i]) <= 'z')
        {
            if (from[i] == to[j - 1])
            {
                start = from[j];
                end = from[i];
                i += 2;
            }
            else
            {
                start = from[i];
                end = from[i + 2];
            }
            for (k = 0; k <=  end - start; ++k)
            {
                to[j++] = from[i] + k;
            }
        }
    }
    if (from[i - 2] == '-') /* check for trailing dash */
    {
        to[j++] = '-';
    }
    to[j++] = '\n';
    to[j] = '\0';
}