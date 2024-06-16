#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change Owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    cents -= 25 * quarters;
    int dimes = calculate_dimes(cents);
    cents -= 10 * dimes;
    int nickels = calculate_nickels(cents);
    cents -= 5 * nickels;
    int pennies = calculate_pennies(cents);

    int sum = quarters + dimes + nickels + pennies;
    printf("%d\n", sum);
}

int calculate_quarters(int cents)
{

    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}
