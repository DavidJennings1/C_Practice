#include <stdio.h>
<<<<<<< HEAD
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
=======
#include "testhead.h"


int main()
{
    struct test area;
    area.len = 4;
    area.wid = 6;
    printf("%d", area.len * area.wid);
}
>>>>>>> 4bdd11ba78ff1cca03d97ce5dd0e3c6b22d6044e
