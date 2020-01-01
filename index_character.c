// Shift characters in string by amount

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char oldChar;
    char newChar;
    int key = atoi(argv[1]);
    string plainText = get_string("plaintext: ");
    int n = strlen(plainText);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        oldChar = plainText[i];
        if (oldChar >= 65 && oldChar <= 90)
        {
            newChar = (((oldChar - 65) + key) % 26) + 65;
        }
        else if (oldChar >= 97 && oldChar <= 122)
        {
            newChar = (((oldChar - 96) + key) % 26) + 96;
        }
        else
        {
            newChar = oldChar;
        }
        printf("%c", newChar);
    }
    printf("\n");
    return 0;
}