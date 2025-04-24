#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int change = get_positive_int();
    int coins = 0;

    // Calcula o número de moedas de cada tipo
    coins += change / 25;
    change %= 25; 

    coins += change / 10;
    change %= 10;

    coins += change / 5;
    change %= 5;

    coins += change / 1;
    change %= 1;

    printf("Coins: %i\n", coins);
}

int get_positive_int(void)
{
    int n;
    do {
        n = get_int("Change owed: ");
    } while (n < 0);
    return n;
}

