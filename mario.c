#include "cs50.h"
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
    for (int i = height; i > 0; i--)
    {
        for (int space_qty = i-1; space_qty > 0; space_qty--)
        {
            printf(" ");
        }
        for (int hash_qty = height-i+1; hash_qty > 0; hash_qty--)
        {
            printf("#");
        }
        printf("\n");
    }
}
