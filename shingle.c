#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    for(int i =0; i < 10; i++)
    {
        int num = rand();
        printf("%i\n", (num % 3) + 1);
    }
    return 0;
}