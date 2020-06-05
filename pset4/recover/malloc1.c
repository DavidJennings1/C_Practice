// Learn malloc usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int* b = malloc(sizeof(int));
    if (b == NULL)
    {
        return 1;
    }
    *b = 4;
    printf("%d\n", *b);
    free(b);

    int num = 1;
    char outFile[8];
    sprintf(outFile, "%d.jpg\n", num);
    printf("outFile = %s\n", outFile);
    return 0;
}