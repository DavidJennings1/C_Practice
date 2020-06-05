#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    srand(time(NULL));
    while(count < 15)
    {
        
        printf("%d\n",(rand()%3)+1);
        count++;
        
    }
    printf("%d\n",time(NULL));
    
    return 0;
}