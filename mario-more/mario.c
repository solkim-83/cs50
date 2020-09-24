#include <stdio.h>
#include <cs50.h>
void buildPyramid(int n);

int main(void) 
{
    //keep prompting the user for the correct height input 
    //until it meets the condition
    int height;
    do 
    {
        height = get_int("Height: "); 
    }
    while (height < 1 || height > 8);
    //when the height is between 1 and 8, proceed to build the pyramid
    buildPyramid(height);
}

void buildPyramid(int height)
{
    //this method builds the pyramid given that the condition meets
    for (int i = 0; i < height; i++) 
    {
        printf("%.*s", height - i - 1, "              ");
        printf("%.*s", i + 1, "#########");
        printf("  ");
        printf("%.*s", i + 1, "#########");
        printf("\n");
    }
}

