#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //for each pixel of the image, convert the pixel colour into the grey colour.
    //in order to convert the image into a grayscaled-image.
    float rgbtGrey;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rgbtGrey = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);
            image[i][j].rgbtBlue = rgbtGrey;
            image[i][j].rgbtGreen = rgbtGrey;
            image[i][j].rgbtRed = rgbtGrey;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //after getting the RGB values from the pixels of the image, 
    //convert the values into the sepia values based on the sepia formula 
    //set each RBG values into their new respective sepia values 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //create an integer array that contains the temporary values (acts as a container)
    //temporary store the value of the pixels of the image on the left half
    //assign the pixels on the left half with those on the right half
    //assign the pixels on the right half with the values stored in the temp array.

    int temp[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

            image[i][width - 1 - j].rgbtBlue = temp[0];
            image[i][width - 1 - j].rgbtGreen = temp[1];
            image[i][width - 1 - j].rgbtRed = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //for each pixel of the image, convert it to become 'blur'
    int totalBlue;
    int totalGreen;
    int totalRed;
    float counter;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            totalBlue = 0;
            totalGreen = 0;
            totalRed = 0;
            counter = 0.000;

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    totalBlue += image[j + k][i + h].rgbtBlue;
                    totalGreen += image[j + k][i + h].rgbtGreen;
                    totalRed += image[j + k][i + h].rgbtRed;
                    counter ++;

                }
            }

            temp[j][i].rgbtBlue = round(totalBlue / counter);
            temp[j][i].rgbtGreen = round(totalGreen / counter);
            temp[j][i].rgbtRed = round(totalRed / counter);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
