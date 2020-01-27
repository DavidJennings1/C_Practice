#include <stdio.h>
#include <string.h>

int main()
{
    char x[4] = "Emma";
    char y[4] = "Emma";
    int ret;
    // Returns 1 (true) if equal
    ret = (!strcmp(x, y));
    printf("%d", ret);
}