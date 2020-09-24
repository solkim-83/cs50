#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    { 
        //given there is only one key (only one element keyed in after ./caesar)
        int numOfDigits = strlen(argv[1]);
        for (int i = 0; i < numOfDigits - 1; i++)
        {
            //if the element is not a number (i.e. alphabet letters or other symbols) reject the entire string element
            //print error message and break out from the loop 
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
                break;
            }
            else
                //if the first element is a number, accepted 
                //move onto the next element of the string element to check
            {
                i++;
            }
        }
        if (isdigit(argv[1][numOfDigits - 1]) != 0)
        {
            //given that the entire string element consists of numbers (i.e. acceptable key)
            string phrase = get_string("plaintext: ");
            int numOfChar = strlen(phrase);
            char modified[numOfChar + 1];
            modified[numOfChar] = '\0';
            int rotateby = atoi(argv[1]) % 26;
            
            //create a new array to contain the ciphertext characters from the plaintext array
            for (int i = 0; i < numOfChar; i++)
            {
                int newChar = (int) phrase[i] + rotateby; 
                if (isalpha(phrase[i]) && ((newChar >= 65 && newChar <= 90) || (newChar >= 97 && newChar <= 122)))
                {
                    //if the new character (ciphertext) lies in the range of ascii number of lower case and upper case
                    modified[i] = (char)((int) phrase[i] + rotateby);
                }
                else if (isalpha(phrase[i]) && ((newChar > 90 && newChar < 97) || (newChar > 122)))
                {
                    //if the new character (ciphertext) lies outside the range of ascii number of lower case and upper case
                    modified[i] = (char)((int) phrase[i] + rotateby - 26);
                }
                else
                {
                    //if neither case above, it means it is a symbol (neither an upper case or lower case alphabet)
                    //the character remains untouched (not modified)
                    modified[i] = phrase[i];
                }
            }
            printf("ciphertext: %s\n", modified);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}