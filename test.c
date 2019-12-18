#include <stdio.h>

int main()
{
    float i;
    scanf("%.2f", &i);
    int quarters = (i / .25);
    i = (i - (quarters * .25));
    printf("i = %.2f", i);
    int dimes = (i / .1);
    printf("%d %d", quarters, dimes);
}