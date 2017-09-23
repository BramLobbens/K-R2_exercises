#include <stdio.h>

#define MAXLINE 1000

void escape(char from[], char to[]);
void invert_escape(char from[], char to[]);

main()
{
    char input[MAXLINE], output[MAXLINE];
    fgets(input, MAXLINE, stdin);
    
    escape(input, output);
    printf("escaped: %s", output);
    
    
    invert_escape(output, input);
    printf("reverted: %s", input);

    return 0;
}

/* escape: convert newline and tab chars into visible sequences */
void escape(char from[], char to[])
{
    int i, j;
    for (i = j = 0; i < MAXLINE - 1 && from[i] != '\0'; ++i)
    {
        switch (from[i])
        {
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = from[i];
                break;
        }
    }
    to[j++] = '\n';
    to[j] = '\0';
}

/* inver_escape: convert string sequences of \n and \t into real chars */
void invert_escape(char from[], char to[])
{
    int i, j;
    for (i = j = 0; i < MAXLINE - 1 && from[j] != '\n'; ++i)
    {
        switch (from[j])
        {
            case '\\':
                ++j; /* check next char after '/' */
                if (from[j] == 'n') /* newline reached */
                {
                    to[i] = '\n';
                }
                else if (from[j++] == 't')
                {
                    to[i] = '\t';
                }
                break;
            default:
                to[i] = from[j++];
                break;
        }
    }
    to[j++] = '\n';
    to[j] = '\0';
}