#include <stdio.h>

int main(void)
{
    float i;
    printf("Enter amount\n");
    scanf("%f", &i);
    if ((i / .25 ) > 1)
    {
        int quarters = (i / .25);
        printf("%d quarters ",  quarters);
        i = i - (quarters * .25);
        printf("%f", i);
    }
}
