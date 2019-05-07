//greedy algorithm

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = 0;
    int n;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int count = 0;

    //prompt users give positive change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //transfer change from float to int
    n = round(change * 100);

    //dispense by quarter
    if (n / quarter > 0)
    {
        count = count + (n / quarter);
        n = n - (n / quarter) * 25;
    }

    //dispense by dime
    if (n / dime > 0)
    {
        count = count + (n / dime);
        n = n - (n / dime) * 10;
    }

    //dispense by nickel
    if (n / nickel > 0)
    {
        count = count + (n / nickel);
        n = n - (n / nickel) * 5;
    }

    //dispense by penny
    if (n / penny > 0)
    {
        count = count + (n / penny);
        n = n - (n / penny) * 1;
    }

    printf("n = %i\n", n);
    printf("count = %i\n", count);
    printf("change = %.2f\n", (float)n / 100);
}