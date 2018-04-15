#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define LOWER_LETTER 97
#define UPPER_LETTER 65
#define NUMBER_OF_LETTERS 26

//accepting a non-negative integer
int get_positive_int(int number);

//applying caesar's cipher
void cipher_caesar(string plaintext, int key);




int main (int argc, string argv[])
{
    //accepting a single command-line argument
    if (argc == 2)
    {
        int key = atoi (argv[1]);
        key = get_positive_int(key);
        //asking for an input
        string plaintext = get_string("plaintext: ");
        cipher_caesar(plaintext, key);

    }
    //wrong input
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}




int get_positive_int(int number)
{
    while (number < 0)
    {
        number = get_int("a positive number please: ");
    }
    return number;
}


void cipher_caesar(string plaintext, int key1)
{
    int shift = 0;
    int length = strlen(plaintext);
    printf("ciphertext: ");
    for (int counter = 0; counter < length ; counter++)
    {
        int cipherletter = 0;
        //checking if the input is an alphapet
        if (isalpha(plaintext[counter]))
        {
            //checking if the input is small letter
            if (islower(plaintext[counter]))
            {
                shift = (int)plaintext[counter] - LOWER_LETTER;
                cipherletter = (shift + key1) % NUMBER_OF_LETTERS;
                cipherletter += LOWER_LETTER;
            }
            //checking if the input is capital letter
            else
            {
                shift = (int)plaintext[counter] - UPPER_LETTER;
                cipherletter = (shift + key1) % NUMBER_OF_LETTERS;
                cipherletter += UPPER_LETTER;
            }
            printf("%c", (char)cipherletter);

        }
        //The input is not an alphapet
        else
        {
            printf("%c", plaintext[counter]);
        }


    }
    printf("\n");

}

