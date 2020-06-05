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
<<<<<<< HEAD
    else // Prompt for input text, generate cipher output
    {
    }
=======
    int blockCount;
    BYTE buffer = malloc((blockCount * 512) * sizeof(BYTE));

    BYTE test[20484];
    FILE* file = fopen(argv[1], "r");
    fread(buffer, 512, 4, file);

    printf("%x, %x, %x, %x\n", test[0], test[1], test[2], test[3]);
    printf("%x, %x, %x, %x\n", test[511], test[512], test[513], test[514]);
    printf("%x, %x, %x, %x\n", test[1024], test[1025], test[1026], test[1027]);

    fclose(file);
>>>>>>> 4bdd11ba78ff1cca03d97ce5dd0e3c6b22d6044e

}
// Test key input for validity
int checkInput(char* key)
{
    printf("%s\n", key);
    int n = strlen(key);
<<<<<<< HEAD
    FILE* file = fopen(key, "w");
=======
    FILE* file = fopen(key, "r");
>>>>>>> 4bdd11ba78ff1cca03d97ce5dd0e3c6b22d6044e
    if (file == NULL)
    {
        printf("Fail");
        return 1;
    }
<<<<<<< HEAD
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
=======
    // for (int i = 0; i < 10; i++)
    // {
    //     fprintf(file, "hello\n");
    // }
    // // Need to close file before re-opening for reading
    // fclose(file);
    // // Can't re-open using same pointer name?
    // FILE* file1 = fopen(key, "r");

    // char ch;
    // while((ch = fgetc(file1)) != EOF)
    // {
    //     printf("%c\n", ch);
    // }
    // fclose(file1);
>>>>>>> 4bdd11ba78ff1cca03d97ce5dd0e3c6b22d6044e
}
