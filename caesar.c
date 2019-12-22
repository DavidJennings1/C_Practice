// Ciphertext generator using c(i) = (p(i) + k) % 26

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Hello, %s", argv[1]);
    }
    else if (argc > 2)
    {
        printf("Hello, %s %i", argv[1], argv[2]);
    }
    else
    {
        printf("error");
    }
    
}