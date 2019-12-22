#include <stdio.h>
#include "cs50.h"

int main()
{
    char i = ('H');
    printf("%i\n", i);
    // string j = ("This works");
    string j = get_string("Enter string: ");
    printf("%s\n", j);
}