// Shift characters in string by amount

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("input: %s\n", argv[1]);
    char oldChar;
    char newChar;
    int key = 27;
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        oldChar = argv[1][i];
        if (oldChar >= 97 && oldChar <= 122)
        {
            if (key + oldChar > 122)
            {
                newChar = ((key + oldChar) % 26) + (oldChar - 122) + 96;
            }
            else
            {
                newChar = oldChar + key;
            }
        }
        else
        {
            newChar = oldChar;
        }
        printf("newChar: %c\n", newChar);
    }
    return 0;
}