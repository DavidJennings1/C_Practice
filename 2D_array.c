// Populate 2D array

#include <stdio.h>

int main()
{
    int testArray[5][5];
    // Start value for array
    int num1 = 0;
    for (int i = 0; i < 5; i++)
    {
        // Populate array
        for (int j = 0; j < 5; j++)
        {
            testArray[i][j] = num1;
            // Print the value at each array location
            printf("i(%d),j(%d) = %d\n", i, j, testArray[i][j]);
            num1++;
        }
    }
    // Search array for value and print index of value
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (testArray[i][j] == 12)
            {
                printf("Found at i(%d),j(%d)\n\n", i, j);
                break;
            }
        }
    }
    // Populate array with values ajacent to selected value in testArray
    int avg[9];
    int i = 2, j = 2;
    avg[0] = testArray[i-1][j-1];
    avg[1] = testArray[i-1][j];
    avg[2] = testArray[i-1][j+1];
    avg[3] = testArray[i][j-1];
    avg[4] = testArray[i][j];
    avg[5] = testArray[i][j+1];
    avg[6] = testArray[i+1][j-1];
    avg[7] = testArray[i+1][j];
    avg[8] = testArray[i+1][j+1];
    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", avg[i]);
    }

    return 0;
}