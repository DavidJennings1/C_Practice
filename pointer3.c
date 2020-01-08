#include <stdio.h>

int main()
{
    int somenumbers[5];
    int *ptr = somenumbers; // Same as &somenumbers[0]
    for (int v = 2; ptr < &somenumbers[5]; ptr++)
    {
        *ptr = v;
        v = v * 2;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", somenumbers[i]);
    }
}