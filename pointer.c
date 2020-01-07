// Learning about pointers

#include <stdio.h>

void test(int *px, int *parr);

int main()
{
    int x = 12;
    int arr[] = {34, 4, 7, 9};
    int *parr = arr; // same as &arr[0]
    int *px = &x; // Set px to the memory location of x
    printf("Memory location of x: %x\n", &x); // Print memory location of x
    printf("Value at memory location of x: %d\n", *px); // Print value at memory location of x
    printf("Memory location from px: %x\n", px); // Print memory location of x
    test(px, arr);
    printf("Value of x after function: %d\n", x); // Print value of x after function
}

void test(int *px, int *parr)
{
    *px = 8; // Write new value to memory location of x
    printf("Arr value: %d\n", *parr);
}