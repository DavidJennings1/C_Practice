// Learn malloc usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main()
{
    int* b = malloc((512 * 4 )* sizeof(BYTE));
    if (b == NULL)
    {
        printf("crap");
        return 1;
    }
    for (int i = 0; i < 512; i++)
    {
        b[i] = i;
        // printf("%d\n", b[i]);
    }
    for (int i = 0; i < 512; i++)
    {
        printf("%d\n", b[i]);
    }

    free(b);

    int num = 1;
    char outFile[8];
    // sprintf(outFile, "%d.jpg\n", num);
    // printf("outFile = %s\n", outFile);
    return 0;
}