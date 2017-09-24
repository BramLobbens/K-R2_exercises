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

    for (i = j = 0; i < MAXLINE - 1 && from[i] != '\n'; ++i)
    {
        if (from[i] == '-' && i == 0) /* check for leading dash */
        {
            to[j++] = from[i];
        }
        else if ((tolower(from[i]) >= 'a' && tolower(from[i]) <= 'z') \
        || (from[i] >= '0' && from[i] <= '9'))
        {
            for (k = 0; k <=  from[i + 2] - from[i]; ++k)
            {
                if (to[j-1] == from[i] + k)
                {
                    ; /* ignore repeating occurences */
                }
                else
                {
                    to[j++] = from[i] + k;
                }
            }
        }
    }
    if (from[i - 1] == '-') /* check for trailing dash */
    {
        to[j++] = from[i - 1];
    }
    to[j++] = '\n';
    to[j] = '\0';
}
