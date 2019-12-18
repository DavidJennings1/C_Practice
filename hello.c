#include <stdio.h>
#include "cs50.h"
void hello(int n);

int main()
{
    int r;
    {
        scanf ("%d",& r);
    }
    printf("the number entered was %d\n", r);
    
    hello(r);
    return 0;
}

void hello(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("hello, world!\n");
    }
}