/*
Find number of elements in array and reverse order of elements
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testarr[6] = {3, 5, 34, 88, 14, 55};
    int length = sizeof(testarr) / sizeof(testarr[0]); //total bytes / bytes in each element
    int temparr[length];
    printf("Array is %d elements long.\n", length);
    for (int i = 0; i < length; i++)
    {
        printf("Original array = %i\n", testarr[i]);
    }
    printf("\n");
    for (int i = length-1, j = 0; i >= 0; i--, j++)
    {
        temparr[j] = testarr[i];
    }
    for (int i = 0; i < length; i++)
    {
        printf("temparr = %i\n", temparr[i]);
    }
    for (int i = 0; i < length; i++)
    {
        testarr[i] = temparr[i];
    }
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("Reversed original array = %i\n", testarr[i]);
    }
}
