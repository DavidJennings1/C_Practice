// Figure out how to round

#include <stdio.h>
#include <math.h>

int main()
{
    float num = ((float)49/(float)2);
    printf("%f\n", num);
    num = roundf(num);
    printf("%d\n", (int)num);
}