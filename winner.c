#include <stdio.h>
#include <cs50.h>

bool print_winner(void);



// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i  = 0; i < candidate_count; i++)
    {
        float winner_test = ((float)voter_count / 2);
        if (candidates[i].votes > winner_test)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
