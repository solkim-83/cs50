#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    //stores the return string value as the variable "name"
    string name = get_string("What is your name? \n"); 
    printf("hello, %s\n", name);
}
