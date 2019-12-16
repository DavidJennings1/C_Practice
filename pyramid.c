#include <stdio.h>

int get_positive_int(void);
int build_pyramid(int height);

int main()
{
    printf("Enter a positive integer > 0 for height\n");
    int height = get_positive_int();
    printf("You entered %d\n", height);
    build_pyramid(height);
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
int build_pyramid(int height)
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
        int j = hash_qty;
        while(j > 0)
            {
                printf("#");
                j--;
            }
        height--;
        hash_qty++;
        printf("\n");
    }
}
