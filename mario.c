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
    int hash_qty = 1;
    for (int i = height; i > 0; i--)
    {
        int space_qty = height;
        while (space_qty > 1)
            {
                printf(" ");
                space_qty--;
            }
        int k = hash_qty;
        while(k > 0)
            {
                printf("#");
                k--;
            }
        height--;
        hash_qty++;
        printf("\n");
    }
}
