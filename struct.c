#include <stdio.h>
#include "testhead.h"


int main()
{
    struct test area;
    area.len = 4;
    area.wid = 6;
    printf("%d", area.len * area.wid);
}