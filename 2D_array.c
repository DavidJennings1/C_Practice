// Populate 2D array

#include <stdio.h>

int main()
{
    int testArray[3][5];
    int num1 = 1, num2 = 1;
    for (int i = 0; i < 3; i++)
    {
        // Populate array
        for (int j = 0; j < 5; j++)
        {
            testArray[i][j] = num1, num2;
            printf("i = %d: ", testArray[i]);
            printf("j = %d\n", testArray[i][j]);
            num1++;
            num2++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // int idx = i;
            if (testArray[i][j] == 15)
            {
                printf("Found at index %d", i);
                break;
            }
        }
    }
}