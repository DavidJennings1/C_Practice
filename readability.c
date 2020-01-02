// Calculate grade level of input text
// index = 0.0588 * L -0.296 * S - 15.8
// L is average number of letters per 100 words
// S is average number of sentences per 100 words

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string inputString = (get_string("Text: "));
    printf("%s\n", inputString);
    int letterCount;
    int wordCount;
    int sentenceCount;
    int n = strlen(inputString);
    for (int i = 0; i < n; i++)
    {
        if (inputString[i] == ' ')
        {
            wordCount++;
        }
        else if (inputString[i] == 33 || inputString[i] == 46 || inputString[i] == 63)
        {
            sentenceCount++;
        }
        else
        {
            letterCount++;
        }
    }
    printf("Letters: %i\nWords: %i\nSentences :%i", letterCount, wordCount, sentenceCount);
}