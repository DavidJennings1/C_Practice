#include <stdio.h>
#include <string.h>

int main()
{
    int x = 8;
    int y = 4;
    int ret;
    ret = (!strcmp(x , y));
    printf("%d", ret);
}