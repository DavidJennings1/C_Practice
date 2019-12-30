// Ciphertext generator using c(i) = (p(i) + k) % 26

// #include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int checkInput(char* key);

int main(int argc, char* argv[])
{

    if ((argc != 2) || checkInput(argv[1]) == 'e')
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    printf("Index number: %i", checkInput(argv[1]));
    return 0;
}

int checkInput(char* key)
{
     int n = strlen(key);
    for (int i = 0; i < n; i++)
    {
        if (key[i] < 48 || key[i] > 57)
        {
            char errorVal = 'e';
            return errorVal;
        }
    }
    int idx = atoi(key);
    return idx;
}
