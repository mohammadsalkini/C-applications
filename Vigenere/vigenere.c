#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

#define FIRST_LOWER_LETTER 97
#define LAST_LOWER_LETTER 122
#define FIRST_UPPER_LETTER 65
#define LAST_UPPER_LETTER 90



int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        int keylength = strlen(key);
        for (int counter = 0; counter < keylength; counter++)
        {
            //checking if the salt an alphapet
            if (!isalpha(key[counter]))
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }

        string plaintext = get_string("plaintext: ");
        printf("ciphertext:");
        for (int plaintext_counter = 0, key_counter = 0; plaintext_counter < strlen(plaintext);
             plaintext_counter++, key_counter++)
        {
            int shift = 0;
            if (key_counter == keylength)
            {
                key_counter = 0;
            }
            //checking if the salt small letter
            if (islower(key [key_counter]))
            {
                //putting the number of steps in shift
                shift = (int)key[key_counter] - FIRST_LOWER_LETTER;

            }
            else
            {
                //checking if the salt capital letter
                if (isupper(key [key_counter]))
                {
                    //putting the number of steps in shift
                    shift = (int)key[key_counter] - FIRST_UPPER_LETTER;

                }
            }
            int cipherletter = 0;

            //checking if the input small letter or not
            if (islower(plaintext[plaintext_counter]))
            {
                cipherletter = shift + (int)plaintext[plaintext_counter];

                if (cipherletter <= LAST_LOWER_LETTER)
                {
                    printf("%c", (char)cipherletter);

                }

                //going back to the first letter and following up the count
                else
                {
                    cipherletter = cipherletter - LAST_LOWER_LETTER + FIRST_LOWER_LETTER - 1;
                    printf("%c", (char)cipherletter);

                }

            }
            else
            {
                //checking if the input capital letter or not
                if (isupper(plaintext[plaintext_counter]))
                {
                    cipherletter = shift + (int)plaintext[plaintext_counter];
                    if (cipherletter <= LAST_UPPER_LETTER)
                    {
                        printf("%c", (char)cipherletter);

                    }
                    //going back to the first letter and following up the count
                    else
                    {
                        cipherletter = cipherletter - LAST_UPPER_LETTER + FIRST_UPPER_LETTER - 1;
                        printf("%c", (char)cipherletter);
                    }

                }
                //not an alphapet
                else
                {
                    printf("%c", plaintext[plaintext_counter]);
                    key_counter = key_counter - 1;
                }
            }
        }
        printf("\n");
        return 0;

    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}