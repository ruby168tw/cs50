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
    while (n < 0 || n >= 24);

    //print out bricks
    for (int i = 0; i < n; i++) //print line
    {
        for (int j = 0; j < (n - (i + 1)); j++) //print spaces
        {
            printf(" ");
        }
        for (int k = 0; k < i + 2; k++)  //print hashes
        {
            printf("#");
        }
        printf("\n");
    }
}