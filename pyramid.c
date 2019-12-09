#include <stdio.h>

int get_positive_int(void);
int build_screen(int x);

int main()
{
    printf("Enter a positive integer > 0 for width\n");
    int x = get_positive_int();
    printf("You entered %d\n", x);
    for (int i = 0; i < x; i++)
    {
        int j = x-1;
        while (j >= 0)
        {
        build_screen(j);
        printf("\n");
        j--;
        }
    return 0;
    }
}
int get_positive_int(void)
{
    int i, j;
    do
    {
       scanf("%d", &i);
    } 
    while (i < 1);
}
int build_screen(int x)
{
    for (int i = 0; i < x; i++)
    {
        // for (int j = 1; j++;)
        {
            printf("#");
            // printf("Hello %d, %d\n", x, y);
        }
        // printf("\n");
    }
}
