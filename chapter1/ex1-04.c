/* K&R2 exercise 1-4, page 13 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celc = 0, 10, 20, ..., 100 */
main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;  /* lower limit of temperature table */
    upper = 100;    /* upper limit */
    step = 10;  /* step size */
    
    celsius = lower;
    
    printf("%s\t\t%s\n", "Celsius", "Fahrenheit");
    
    while (celsius <= upper) 
    {
        fahr = ((celsius * 9.0) / 5.0) + 32.0;
        printf("%3.0f\t\t%7.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}