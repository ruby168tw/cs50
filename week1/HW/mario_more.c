#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    //prompt user for a positive number

    printf("give a height which is not more than 23 or less than 0\n");
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    //print lines
    for (int i = 0; i < n; i++)
    {
        //print spaces
        for (int j = 0; j < (n - (i + 1)); j++)
        {
            printf(" ");
        }

        //print hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");

        //print hashes again
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}