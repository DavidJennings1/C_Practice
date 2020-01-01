// Calculate grade level of input text
// index = 0.0588 * L -0.296 * S - 15.8
// L is average number of letters per 100 words
// S is average number of sentences per 100 words

#include <cs50.h>
#include <stdio.h>

int main()
{
    string inputString = (get_string("Text: "));
    printf("%s\n", inputString);
    int letterCount;
    int sentenceCount;
}