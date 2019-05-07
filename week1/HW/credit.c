#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    long long int num;
    char buffer[20];
    int len;
    int sum = 0;

    //ensure user’s input will be entirely numeric, devoid of hyphens, or negative
    do
    {
        num = get_long_long("Number: ");
    }
    while (num <= 0);

    //transfer num`s type from int to string
    sprintf(buffer, "%lld", num);

    //count string length
    len = strlen(buffer);

    // enter number into array - using s[i]-'0' for ASCII conversion
    int number[len];
    for (int i = 0; i < len; i++)
    {
        number[i] = buffer[i] - '0';
    }

    // multiply every other digit starting with 2nd-to-last by 2, add digits together
    // add not multiplied numbers to sum
    int j = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (j % 2 == 0)
        {
            sum += number[i] * 2 % 10;
            if (number[i] * 2 >= 10)
            {
                sum += 1;
            }
        }
        else
        {
            sum += number[i];
        }

        j++;
    }


    //American Express //start with 34 or 37 //15-digit numbers
    if (len == 15 && number[0] == 3 && (number[1] == 4 || number[1] == 7) && sum % 10 == 0)
    {
        printf("AMEX\n");


    }  // MASTERCARD // start with 51,52,53,54,or 55 // 16-digit numbers
    else if (len == 16 && number[0] == 5 && number[1] > 0 && number[1] < 6 && sum % 10 == 0)
    {
        printf("MASTERCARD\n");


    }  // VISA // start with 4 // 13- and 16-digit numbers
    else if ((len == 13 || len == 16) && number[0] == 4 && sum % 10 == 0)
    {
        printf("VISA\n");

    }
    else
    {
        printf("INVALID\n");
    }

}