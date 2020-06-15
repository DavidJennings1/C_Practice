#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int checkInput(char* key);
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 1)
    {
        printf("Usage: ./recover filename");
        return 1;
    }
    // BYTE buffer[1027];
    int blockCount;
    BYTE* buffer = malloc(sizeof(BYTE));

    FILE* file = fopen(argv[1], "r");
    fread(buffer, 512, 3, file);

    printf("%x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%x, %x, %x, %x\n", buffer[511], buffer[512], buffer[513], buffer[514]);
    printf("%x, %x, %x, %x\n", buffer[1024], buffer[1025], buffer[1026], buffer[1027]);

    fclose(file);
    free(buffer);

}
// Test key input for validity
int checkInput(char* key)
{
    printf("%s\n", key);
    int n = strlen(key);
    FILE* file = fopen(key, "r");
    if (file == NULL)
    {
        printf("Fail");
        return 1;
    }

}
