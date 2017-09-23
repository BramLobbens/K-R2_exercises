#include <stdio.h>

#define SIZE 10

int binsearch(int x, int v[], int n);

main()
{
    int num, i;
    int numbers[SIZE];
    
    /* generate array values */
    for (i = 0; i < SIZE; ++i)
    {
        numbers[i] = (i << 2);
        printf("%d%s", numbers[i], (i < SIZE - 1) ? ", " : "\n");
    }
    
    num = 24;
    printf("\'%d\' found at position \'%d\'\n", num, binsearch(num, numbers, SIZE));
    
    return 0;
}

/* binsearch: find x in v */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x != v[mid]) /* no match */
    {
        mid = -1;
    }
    return mid;
}