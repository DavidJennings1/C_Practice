#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            /* Retrieve current pixel values, average the values and
               change pixel values to the average. */
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            float avg = (red + green + blue) / 3;

            // Round result and cast to int
            image[i][j].rgbtRed = (int)roundf(avg);
            image[i][j].rgbtGreen = (int)roundf(avg);
            image[i][j].rgbtBlue = (int)roundf(avg);

        }
    }
    return;
}

// Convert image to sepia

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Retrieve current pixel color and store in variable
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            // Apply sepia algorithm and cap value at 255
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Round result and cast to int
            image[i][j].rgbtRed = (int)roundf(sepiaRed);
            image[i][j].rgbtGreen = (int)roundf(sepiaGreen);
            image[i][j].rgbtBlue = (int)roundf(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Write values to temporary array starting at the end of each row
    RGBTRIPLE tempArray[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1, k = 0; j >= 0; j--, k++)
        {
            tempArray[i][k] = image[i][j];
        }
    }
    // Write reversed values back to original array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempArray[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array to store processed values without messing up original
    RGBTRIPLE tempBlurImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Case 1 - upper left corner
            if (i == 0 & j == 0)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[4];
                boxData[0] = image[i][j];
                boxData[1] = image[i][j + 1];
                boxData[2] = image[i + 1][j];
                boxData[3] = image[i + 1][j + 1];

                // Add values of each color together and get average
                for (int k = 0; k < 4; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 4;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 4;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 4;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 2 - middle top row
            if (i == 0 & j > 0 & j < width)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[6];
                boxData[0] = image[i][j - 1];
                boxData[1] = image[i][j];
                boxData[2] = image[i][j + 1];
                boxData[3] = image[i + 1][j - 1];
                boxData[4] = image[i + 1][j];
                boxData[5] = image[i + 1][j + 1];
                for (int k = 0; k < 6; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 6;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 6;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 6;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 3 - upper right corner
            if (i == 0 & j > 0 & j == width - 1)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[4];
                boxData[0] = image[i][j - 1];
                boxData[1] = image[i][j];
                boxData[2] = image[i + 1][j - 1];
                boxData[3] = image[i + 1][j];
                // Add values of each color together and get average
                for (int k = 0; k < 4; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 4;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 4;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 4;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 4 - middle left column
            if (i > 0 & i < height & j == 0)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[6];
                boxData[0] = image[i - 1][j];
                boxData[1] = image[i - 1][j + 1];
                boxData[2] = image[i][j];
                boxData[3] = image[i][j + 1];
                boxData[4] = image[i + 1][j];
                boxData[5] = image[i + 1][j + 1];
                // Add values of each color together and get average
                for (int k = 0; k < 6; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 6;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 6;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 6;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 5 - center
            if ((i > 0 & i < height) & (j > 0 & j < width))
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[9];
                boxData[0] = image[i - 1][j - 1];
                boxData[1] = image[i - 1][j];
                boxData[2] = image[i - 1][j + 1];
                boxData[3] = image[i][j - 1];
                boxData[4] = image[i][j];
                boxData[5] = image[i][j + 1];
                boxData[6] = image[i + 1][j - 1];
                boxData[7] = image[i + 1][j];
                boxData[8] = image[i + 1][j + 1];
                // Add values of each color together and get average
                for (int k = 0; k < 9; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 9;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 9;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 9;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 6 - middle right column
            if (i > 0 & i < height & j == width - 1)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[6];
                boxData[0] = image[i - 1][j - 1];
                boxData[1] = image[i - 1][j];
                boxData[2] = image[i][j - 1];
                boxData[3] = image[i][j];
                boxData[4] = image[i + 1][j - 1];
                boxData[5] = image[i + 1][j];

                // Add values of each color together and get average
                for (int k = 0; k < 6; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 6;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 6;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 6;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 7 - lower left corner
            if (i == height - 1 & j == 0)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[4];
                boxData[0] = image[i - 1][j];
                boxData[1] = image[i - 1][j + 1];
                boxData[2] = image[i][j];
                boxData[3] = image[i][j + 1];
                // Add values of each color together and get average
                for (int k = 0; k < 4; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 4;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 4;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 4;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }
            // Case 8 - middle bottom row
            if (i == height - 1 & j > 0 & j < width)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[6];
                boxData[0] = image[i - 1][j - 1];
                boxData[1] = image[i - 1][j];
                boxData[2] = image[i - 1][j + 1];
                boxData[3] = image[i][j - 1];
                boxData[4] = image[i][j];
                boxData[5] = image[i][j + 1];
                // Add values of each color together and get average
                for (int k = 0; k < 6; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 6;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 6;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 6;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }

            // Case 9 - lower right corner
            if (i == height - 1 & j == width - 1)
            {
                float tempRed = 0, tempGreen = 0, tempBlue = 0;
                RGBTRIPLE boxData[4];
                boxData[0] = image[i - 1][j - 1];
                boxData[1] = image[i - 1][j];
                boxData[2] = image[i][j - 1];
                boxData[3] = image[i][j];
                // Add values of each color together and get average
                for (int k = 0; k < 4; k++)
                {
                    tempRed = tempRed + boxData[k].rgbtRed;
                    tempGreen = tempGreen + boxData[k].rgbtGreen;
                    tempBlue = tempBlue + boxData[k].rgbtBlue;
                }
                float avgRed = tempRed / 4;
                if (avgRed > 255)
                {
                    avgRed = 255;
                }
                float avgGreen = tempGreen / 4;
                if (avgGreen > 255)
                {
                    avgGreen = 255;
                }
                float avgBlue = tempBlue / 4;
                if (avgBlue > 255)
                {
                    avgBlue = 255;
                }
                // Round result and cast to int
                tempBlurImage[i][j].rgbtRed = (int)roundf(avgRed);
                tempBlurImage[i][j].rgbtGreen = (int)roundf(avgGreen);
                tempBlurImage[i][j].rgbtBlue = (int)roundf(avgBlue);
            }
        }
    }
    // Write temp array back to image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempBlurImage[i][j];
        }
    }
    return;
}
