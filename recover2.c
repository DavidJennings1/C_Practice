// Recover deleted .jpg images

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkInput(char *key);

int main(int argc, char *argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 'e')
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else // Prompt for input text, generate cipher output
    {
        printf("argc: %d\n", argc);
        printf("argv: %d\n", *argv[0]);
        printf("argv: %d\n", *argv[1]);
        return 0;
    }

}
// Test key input for validity
int checkInput(char *key)
{
    int n = strlen(key);
    printf("string length: %d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("argv[%d] = %c\n", key[i], key[i]);
        if (key[i] < 48 || key[i] > 57)
        {
            char errorVal = 'e';
            return errorVal;
        }
    }
}