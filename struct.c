#include <stdio.h>
#include "struct_test.h"

void house_data (char *name, float width, float length);

int main()
{
    struct house sunland;
    sunland.name = "Section";
    sunland.width = 36;
    sunland.length = 32;
    house_data(sunland.name, sunland.width, sunland.length);
    return 0;
}
void house_data (char *name, float width, float length)
{
    printf("%c\n%.2f\n", name[0], width * length);
}
