// Ciphertext generator using c(i) = (p(i) + k) % 26

// #include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int checkInput(char* key);

int main(int argc, char* argv[])
{
    if ((argc != 2) || checkInput(argv[1]) == 99)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    printf("Success \n");
    printf("%s\n", argv[1]);
    printf("Return value: %i\n", checkInput(argv[1]));
    return 0;
}

int checkInput(char* key)
{
     int n = strlen(key);
    for (int i = 0; i < n; i++)
    {
        if (key[i] < 48 || key[i] > 57)
        {
            printf("not a number\n");
            return 99;
        }
    }
    int idx = atoi(key);
    printf("Result of atoi: %i\n", idx);
    return idx;
}
