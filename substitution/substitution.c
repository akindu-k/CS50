#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int validate(int argc, string key);
int validate_key(string key);
void out(string key);
string encrypt(string key, string plaintext);

int main(int argc, string argv[])
{

    return validate(argc, argv[1]);
}

int validate(int argc, string key)
{
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {

        return validate_key(key);
    }
}

int validate_key(string key)
{

    int length = 0;
    int chars[26] = {0};
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("key should contain only alphabetic characters\n");
            return 1;
        }
        int index = tolower(key[i]) - 'a';
        if (chars[index] == 1)
        {
            printf("each letter should appear only once in key\n");
            return 1;
        }
        chars[index] = 1;

        length++;
    }
    if (length != 26)
    {
        printf("key must contain 26 characters\n");
        return 1;
    }
    out(key);
    return 0;
}

void out(string key)
{
    string plaintext = get_string("plaintext: ");
    encrypt(key, plaintext);
}

string encrypt(string key, string plaintext)
{
    char ciphertext[50];

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (islower(plaintext[i]))
        {
            int index = (int) plaintext[i] - 'a';

            ciphertext[i] = ' ';
            ciphertext[i] = tolower(key[index]);
        }
        else if (isupper(plaintext[i]))
        {
            int index = (int) plaintext[i] - 'A';

            ciphertext[i] = ' ';
            ciphertext[i] = toupper(key[index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
