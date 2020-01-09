#include <stdio.h>

int fun(int n);

int main()
{
    int n = 3;
    printf("%d", fun(n));
}

int fun(int n)
{
    for (int i = 0; i < n; i++);
    if (n == 0)
    {
        return 1;
    }
    else
    {
        {
            printf("fun: %d\n", fun(n - 1));
        }
    }
}