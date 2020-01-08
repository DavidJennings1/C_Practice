// Calculate grade level of input text

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void analyzeInput (string text, float *lnum, float *wnum, float *snum);

int main()
{
    float letters, words, sentences;
    string inputString = (get_string("Text: "));
    analyzeInput(inputString, &letters, &words, &sentences);
    // Coleman-Laiu index formula index = 0.0588 * L - 0.296 * S - 15.8
    float l = (100 / words) * letters; // Letters per 100 words
    float s = (100 / words) * sentences; // Sentences per 100 words
    float clIndex = .0588 * l - .296 * s - 15.8;
    printf("Letters: %f\n", letters);
    printf("Words: %f\n", words);
    printf("Sentences: %f\n", sentences);
    printf("Letters per 100 words: %f\n", l);
    printf("Sentences per 100 words: %f\n", s);
    printf("clIndex before rounding: %f\n", clIndex);
    clIndex = round(clIndex);
    printf("clIndex after rounding: %f\n", clIndex);
    if (clIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else if (clIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", clIndex);
    }
}

// Iterate over string and count letters, spaces, and ., ?, and !
void analyzeInput (string text, float *lnum, float *wnum, float *snum)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isblank(text[i]))
        {
            wordCount++;
        }
        else if  (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentenceCount++;
        }
        else
        {
            if (isalpha(text[i]))
            {
                letterCount++;
            }
        }
    }
    wordCount += 1;
    *lnum = letterCount;
    *wnum = wordCount;
    *snum = sentenceCount;
}