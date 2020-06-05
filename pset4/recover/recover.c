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
    int blockCount;
    BYTE buffer = malloc((blockCount * 512) * sizeof(BYTE));

    BYTE test[20484];
    FILE* file = fopen(argv[1], "r");
    fread(buffer, 512, 4, file);

    printf("%x, %x, %x, %x\n", test[0], test[1], test[2], test[3]);
    printf("%x, %x, %x, %x\n", test[511], test[512], test[513], test[514]);
    printf("%x, %x, %x, %x\n", test[1024], test[1025], test[1026], test[1027]);

    fclose(file);

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
