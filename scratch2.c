#include <stdio.h>
#include <string.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    // if (argc != 2)
    // {
    //     printf("Usage: ./caesar key");
    //     return 1;
    // }
    // printf("Success\n");
    // printf("Argument input: %s", argv[1]);
    for (int i = 0; i < argc; i++)
    {
        int j = 0;
        while (j != '\0')
        {
            printf("here %c\n", argv[i][j]);
            j++;
        }
    }
}
