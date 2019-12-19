#include <stdio.h>

int main()
{
    float i;
    scanf("%f", &i);
    int y = i * 100;
    int quarters = (y / 25);
    int leftover = (y % 25);
    printf("%d quarters\n", quarters);
    printf("%d leftover", leftover);

    // i = (i - (quarters * .25));
    // printf("i = %f", i);
    // float dimes = (i / .1);
    // printf("%d, %d", quarters, dimes);
}