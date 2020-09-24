#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string string);
int count_words(string string);
int count_sentences(string string);

int main(void)
{
    float L;
    float S;
    float index;
    string text = get_string("Text: ");
    printf("%i letter(s)\n", count_letters(text));
    printf("%i word(s)\n", count_words(text));
    printf("%i sentence(s)\n", count_sentences(text));
    
    //calculating the variables L and S values as float 

    L = (float) count_letters(text) / (float) count_words(text) * 100;
    S = (float) count_sentences(text) / (float) count_words(text) * 100;


    // calculating the index (i.e. grade)
    index = 0.0588 * L - 0.296 * S - 15.8;

    //printing out the grade statement based on the number/ index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        //round up the index in a case where the index is decimal number
        printf("Grade %i\n", (int) round(index));
    }
}

//method to count the number of letters in the given text
//the criteria is to check whether the character belongs to the group of 
//alphabets of upper case and lower case. 
//only alphabets allowed. if not no incrementation of letter count.
int count_letters(string string)
{
    int counter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            counter++;
        }
    }
    return counter;
}

//method to count the number of words in the given text
//the criteria is to check whether the character is a blank space
//only blank space allowed. if not no incrementation of word count
int count_words(string string)
{
    int counter = 1;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

//method to count the number of sentences in the given text
//the criteria is to check whether the character belongs to the group of 
//punctuation marks, '.', '?', '!' in specific. 
//only punctuation marks allowed, if not no incrementation of sentence count.
int count_sentences(string string)
{
    int counter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '.' || string[i] == '?' || string[i] == '!')
        {
            counter++;
        }
    }
    return counter;
}