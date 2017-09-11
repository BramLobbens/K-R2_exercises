/* K&R2 exercise 1-15, page 27 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double fahr_to_celc(int f);

main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, fahr_to_celc(fahr));
    }
    return 0;
}

double fahr_to_celc(int fahr)
{
    return (5.0/9.0) * (fahr-32);
}