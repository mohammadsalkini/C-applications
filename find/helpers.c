/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0)
    {
        return false;
    }
    int first = 0;
    int last = n - 1;
   // int middle = last / 2;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (values[middle] == value)
        {
            return true;

        }
        else
        {
            if (value < values[middle])
            {
                last = middle - 1;

            }
            else
            {
                if (value > values[middle])
                {
                    first = middle + 1;

                }
            }

        }

    }
    return false;


}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
        for (int i = 0; i < n - 1; i++)
    {

        int min = i;

        for (int j = i; j < n; j++)
        {
            if (values[min] > values[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = values[min];
            values[min] = values[i];
            values[i] = temp;
        }
    }

    return ;
}
