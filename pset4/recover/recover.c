#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int checkInput(char* key);
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 'e')
    {
        printf("Usage: ./recover filename");
        return 1;
    }
    else // Prompt for input text, generate cipher output
    {
    }

}
// Test key input for validity
int checkInput(char* key)
{
    printf("%s\n", key);
    int n = strlen(key);
    FILE* file = fopen(key, "w");
    if (file == NULL)
    {
        printf("Fail");
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        fprintf(file, "hello\n");
    }
    // Need to close file before re-opening for reading
    fclose(file);
    // Can't re-open using same pointer name?
    FILE* file1 = fopen(key, "r");

    char ch;
    while((ch = fgetc(file1)) != EOF)
    {
        printf("%c\n", ch);
    }
    fclose(file1);
}
