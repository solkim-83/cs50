#include <stdio.h>
#include <cs50.h>
#include <math.h>

int countDigits(long cardNumber) 
{
    // count the number of digits of the cardNumber 
    int counter = 0;
    do 
    {
        counter ++;
        cardNumber /= 10;
    } 
    while (cardNumber != 0);
    return counter;
}

int main(void) 
{
    long cardNumber;
    do 
    {
        cardNumber = get_long("Number: "); 
    }
    while (cardNumber < 0);
    
    int maxDigits = countDigits(cardNumber);
    if ((maxDigits != 13) && (maxDigits != 15) && (maxDigits != 16)) 
    {
        printf("INVALID\n");
    }
    
    int number[maxDigits];
    
    //with the number of digits, proceed with Luhn's algorithm
    
    for (int i = 0; i < maxDigits; i++) 
    {
        number[i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }
    
    int originalNumber[maxDigits];
    
    for (int i = 1; i < maxDigits; i++) 
    {
        originalNumber[i] = number[i];
    }
    
    for (int i = 1; i < maxDigits; i += 2) 
    {
        number[i] = number [i] * 2;
    }
    
    int sum = 0;
    int temp;
    
    if (maxDigits == 13) 
    {
        // possibility for Visa based on the first two digits of the card number 
        for (int i = 0; i < maxDigits; i++) 
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp;
        }
        if (originalNumber[12] == 4 && sum % 10 == 0) 
        {
            //checks if the card is VISA
            printf("VISA\n");
        } 
        else 
        {
            //if the card is not VISA, it is an invalid card.
            printf("INVALID\n");
        }
    }
    
    if (maxDigits == 15) 
    {
        //possibility for American Express based on the first two digits of the card number 
        for (int i = 0; i < maxDigits; i++) 
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp;
        }
        //checks if the card is AMEX
        if (originalNumber[14] == 3 && sum % 10 == 0 &&
            (originalNumber[13] == 4 || originalNumber[13] == 7)) 
        {
            printf("AMEX\n");
        } 
        else 
            //if the card is not American Express, it is an invalid card.
        {
            printf("INVALID\n"); 
        }
    }
    
    if (maxDigits == 16) 
    {
        //possibility of MasterCard and Visa
        for (int i = 0; i < maxDigits; i++) 
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp;
        }
        //checks if MasterCard based on the first two digits of the card number
        if (originalNumber[15] == 5 && sum % 10 == 0 &&
            (originalNumber[14] == 1 || originalNumber[14] == 2 || originalNumber[14] == 3
             || originalNumber[14] == 4 || originalNumber[14] == 5)) 
        {
            printf("MASTERCARD\n");
        } 
        // checks if VISA based on the first two digits of the card number
        else if (originalNumber[15] == 4 && sum % 10 == 0) 
        {
            printf("VISA\n");
        } 
        else 
            //if neither VISA or MasterCard, it is an invalid card.
        {
            printf("INVALID\n"); 
        }
    }
    return 0;
}
    