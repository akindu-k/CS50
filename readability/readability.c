#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int coleman_index(int letter_count, int word_count, int sentence_count);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    coleman_index(letters, words, sentences);
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letter_count++;
        }
    }
    // printf("letter_count: %d\n",letter_count);
    return letter_count;
}

int count_words(string text)
{
    int space_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            space_count++;
        }
    }
    //printf("word_count: %d\n", space_count + 1);
    return space_count + 1;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    printf("sentence_count: %d\n", sentence_count);
    return sentence_count;
}

int coleman_index(int letter_count, int word_count, int sentence_count)
{
    float L = (float) letter_count * 100 / (float) word_count;
    float S = (float) sentence_count * 100 / (float) word_count;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}
