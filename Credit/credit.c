/**************************************************
* credit.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Alsalkini
* graded by: Alex Hartveld
* pset design by Harvard CS50
*
* This program determines whether a provided credit card number is valid according to Luhn’s algorithm.
* It ask for input for card number and prints a text message.
***************************************************/

#include <stdio.h>
#include <cs50.h>

//to check the validity of the number
bool check(long long credit);

//to check the type of the card
int type(long long credit);

//to print out the type of the card if it is valid
void print_cardtype(int type);

int main(void)
{
    //the user input
    long long credit = get_long_long ("Number: ");
    bool valid = check(credit);
    int credit_type = 0;
    credit_type = type(credit);

    if (!valid)
    {
        credit_type = 0;
    }

    print_cardtype(credit_type);
    return 0;
}


bool check(long long credit)
{
    int number[16], rest, length = 0, sum = 0;

    //put the number in an arrey
    for (int i = 1 ; i <= 16 ; i++)
    {
        if (credit / 10 >= 0)
        {
            // length: is the length of the number
            length += 1;
            rest = credit % 10 ;
            number [16 - i] = rest;
            credit = (credit - rest) / 10;
        }
        else
        {
            number[16 - i] = 0;
        }
    }

    //check if the number valid or not
    int x = 16 - length;
    for ( int m = length - 1; m >= x; m -= 2)
    {
        if (number [m - 1] * 2 > 9)
        {
            sum = sum + (number[m - 1] * 2) % 10 + 1;

        }
        else
        {
            sum = sum + number [m - 1] * 2;

        }
        sum = sum + number[m];

    }
    if (sum % 10 == 0)
    {
        return true;

    }
    return false;
}


int type(long long credit)
{
    //AMEX
    if ((credit >= 340000000000000 && credit < 350000000000000) || (credit >= 370000000000000
            && credit < 380000000000000))
    {
        return 1;
    }

    //MASTERCARD
    if (credit >= 5100000000000000 && credit < 5600000000000000)
    {
        return 2;
    }

    //VISA
    if ((credit >= 4000000000000000 && credit < 5000000000000000) || (credit >= 4000000000000
            && credit < 5000000000000))
    {
        return 3;
    }
    return 0;
}

void print_cardtype(int type)
{
    switch (type)
    {
        case 1:
            printf("AMEX\n");
            break;
        case 2:
            printf("MASTERCARD\n");
            break;
        case 3:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }
}