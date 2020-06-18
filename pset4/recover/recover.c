#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int checkInput(char* key);
int readBlock(BYTE* buffer, int blockCount, char* key);
int writeBlock(BYTE* buffer);


int main(int argc, char *argv[])
{
    // Check for correct command line input
    if ((argc != 2) || checkInput(argv[1]) == 1)
    {
        printf("Usage: ./recover filename");
        return 1;
    }
    int blockCount = 0;

    BYTE* buffer = malloc(512);
    int is_jpg = readBlock(buffer, blockCount, argv[1]);


    while(1)
    {
    if (is_jpg == 1)

    {
        for (int i = 0; i < 512; i++)
    {
        printf("%x\n", buffer[i]);
    }
        printf("from card.raw %x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        writeBlock(buffer);
        break;
    }

    else
    {
        blockCount++;
        is_jpg = readBlock(buffer, blockCount, argv[1]);
    }
    }
    printf("%d\n", blockCount);

    FILE* file2 = fopen("pic.jpg", "r");
    fread(buffer, 1, 512, file2);

    printf("from pic.jpg %x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    fclose(file2);

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
int readBlock(BYTE* buffer, int blockCount, char* key)
{
    printf("in function%d\n", blockCount);

    FILE* file = fopen(key, "r");
    fseek(file, (blockCount * 512), SEEK_SET);
    fread(buffer, 1, 512, file);
    fclose(file);


    if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] >= 0xe0 & buffer[3]<= 0xef))
    {
        return 1;
    }
    else
    {
        return 0;
    }    
    return 0;
}

int writeBlock(BYTE* buffer)
{
        FILE* test = fopen("pic.jpg", "wb");
        fwrite(buffer, 1, 512, test);
        fclose(test);
}
