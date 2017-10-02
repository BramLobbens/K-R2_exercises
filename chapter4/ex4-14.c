/* K&R2 exercise 4-14, page 91 */

#include <stdio.h>

#define swap(t, x, y)   t temp = x; \
                        x = y; \
                        y = temp;

main()
{
    int a = 1;
    int b = 2;

    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}