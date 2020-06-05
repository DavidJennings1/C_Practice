// Reverse order of row in 2d array
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
    return 0;    
}