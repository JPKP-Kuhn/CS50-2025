#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

string checksum(long n);
string checkcard(string card, long credit);
int count_digits(long n);
int get_prefix(long num, int digits);

int main(void)
{
    long credit = get_long("Number: ");
    string card = checksum(credit);
    printf("%s\n", checkcard(card, credit));
}

string checksum(long n)
{
    int sum = 0;
    int is_second = 0; // Controla dígitos pares/ímpares

    while (n > 0)
    {
        int digit = n % 10;
        if (is_second)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        sum += digit;
        n /= 10;
        is_second = !is_second; // Alterna a cada dígito
    }

    return (sum % 10 == 0) ? "VALID" : "INVALID";
}

string checkcard(string card, long credit)
{
    if (strcmp(card, "INVALID") == 0)
    {
        return "INVALID";
    }

    int length = count_digits(credit);
    int prefix2 = get_prefix(credit, 2); // Dois primeiros dígitos
    int prefix1 = get_prefix(credit, 1); // Primeiro dígito

    // AMEX: 15 dígitos, prefixo 34 ou 37
    if (length == 15 && (prefix2 == 34 || prefix2 == 37))
    {
        return "AMERICAN EXPRESS";
    }
    // MASTERCARD: 16 dígitos, prefixo 51-55
    else if (length == 16 && (prefix2 >= 51 && prefix2 <= 55))
    {
        return "MASTERCARD";
    }
    // VISA: 13 ou 16 dígitos, prefixo 4
    else if ((length == 13 || length == 16) && prefix1 == 4)
    {
        return "VISA";
    }

    return "INVALID";
}

int count_digits(long n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int get_prefix(long num, int digits)
{
    return num / pow(10, count_digits(num) - digits);
}

