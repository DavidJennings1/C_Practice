// Returns minimum number of coins to make change
#include <stdio.h>
#include <math.h>
#include "cs50.h"

float getChangeAmount(void);

int main(void)
{
    float change = getChangeAmount(); // User input
    // Convert to integer to avoid float precision issues
    int cents = round(change * 100);
    int quarters = (cents / 25);
    int leftAfterQuarters = (cents % 25);
    int dimes = (leftAfterQuarters / 10);
    int leftAfterDimes = (cents % 10);
    int nickels = (leftAfterDimes / 5);
    int pennies = (cents % 5);
    printf("%d\n", quarters + dimes + nickels + pennies);
}
// Prompt for user input
float getChangeAmount(void)
{
    float i;
    do
    {
        i = get_float("Enter change owed: ");
    } 
    while (i <= 0);
    return i;
}
