#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int length = strlen(key);

    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    printf("Key: %s\n", argv[1]);
    string plaintext = get_string("Plaintext: ");
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

string encrypt(string plaintext, string key)
{
    int lenplain = strlen(plaintext);
    string cypher = malloc((lenplain + 1) * sizeof(char));
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        key[i] = tolower(key[i]);
    }

    for (int i = 0; i < lenplain; i++)
    {
        if (isupper(plaintext[i]))
        {
            cypher[i] = toupper(key[(plaintext[i] - 'A')]);
        }
        else if (islower(plaintext[i]))
        {
            cypher[i] = tolower(key[(plaintext[i] - 'a')]);
        }
        else
        {
            cypher[i] = plaintext[i];
        }
        cypher[lenplain] = '\0';
    }
    return cypher;
}

