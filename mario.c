#include <cs50.h>
#include <stdio.h>

int get_height(void);
void build_pyramid(int height);

int main(void)
{
    int height = get_height();
    printf("You entered: %i\n", height);
    build_pyramid(height);
}
int get_height(void)
{
    int i;
    do
    {
        i = get_int("Enter an integer between 1 and 8:\n");
    }
    while (i < 1 || i > 8);
    return i;
}
void build_pyramid(int height)
{
    int k = 1;
    for (int i = height; i > 0; i--)
    {
        int j = height;
        while (j > 1)
            {
                printf(" ");
                j--;
            }
        int m = k;
        while(m > 0)
            {
                printf("#");
                m--;
            }
        height--;
        k++;
        printf("\n");
    }
}
