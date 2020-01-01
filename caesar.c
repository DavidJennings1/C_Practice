// Ciphertext generator using c(i) = (p(i) + k) % 26

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int checkInput(string key);

int main(int argc, string argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 'e')
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else // Prompt for input text, generate cipher output
    {
        char oldChar;
        char newChar;
        int key = atoi(argv[1]);
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");
        int n = strlen(plainText);
        for (int i = 0; i < n; i++)
        {
            oldChar = plainText[i];
            // If char is uppercase add key value
            if (oldChar >= 65 && oldChar <= 90)
            {
                newChar = (((oldChar - 65) + key) % 26) + 65;
            }
            // If char is lowercase add key value
            else if (oldChar >= 97 && oldChar <= 122)
            {
                newChar = (((oldChar - 97) + key) % 26) + 97;
            }
            // If char is anything else do nothing
            else
            {
                newChar = oldChar;
            }
            printf("%c", newChar);
        }
        printf("\n");
    }
    return 0;
}

// Test key input for validity
int checkInput(string key)
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
}
