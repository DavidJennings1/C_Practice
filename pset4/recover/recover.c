#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int checkInput(char* key);
int readBlock(BYTE* buffer, char* key);


int main(int argc, char *argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 1)
    {
        printf("Usage: ./recover filename");
        return 1;
    }
    BYTE* buffer = malloc(512);
    readBlock(buffer, argv[1]);
    if (buffer[0] == 0 & buffer[1] == 0xd8 & buffer[2] == 0 & (buffer[3] >= 0 & buffer[3]<= 0))
    {
        printf("yes\n");
    }
    else
    {
        {
            printf("no\n");
        }
    }
        for (int i = 0; i < 512; i++)
    {
        printf("%d\n", buffer[i]);
    }
    




    free(buffer);

}

// Test key input for validity
int checkInput(char* key)
{
    int n = strlen(key);
    FILE* file = fopen(key, "r");
    if (file == NULL)
    {
        printf("Fail");
        return 1;
    }
}

    // Read block to buffer
int readBlock(BYTE* buffer, char* key)
{
    printf("in function\n");

    FILE* file = fopen(key, "r");
    fread(buffer, 1, 512, file);


    printf("%x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    fclose(file);

    
    return 1;
}
