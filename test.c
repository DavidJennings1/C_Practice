#include <stdio.h>
// #include <cs50.h>
#include <math.h>


float getChangeAmount(void);

int main()
{
    float change = getChangeAmount();
    printf("Entered amount = %f\n", change);
    int cents = round(change * 100);
    printf("Converted to cents = %d\n", cents);
    int quarters = (cents / 25);
    int leftAfterQuarters = (cents % 25);
    int dimes = (leftAfterQuarters / 10);
    int leftAfterDimes = (leftAfterQuarters % 10);
    int nickels = (leftAfterDimes / 5);
    int pennies = (leftAfterDimes % 5);
    printf("%d quarters\n%d dimes\n%d nickels\n%d pennies\n",
           quarters, dimes, nickels, pennies);
    printf("%d\n", quarters + dimes + nickels + pennies);
}
float getChangeAmount(void)
{
    float i;
    do
    {
        printf("Enter change owed: ");
        scanf("%f", &i);
    } 
    while (i <= 0);
    return i;
}