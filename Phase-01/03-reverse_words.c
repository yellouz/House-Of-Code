#include <stdio.h>
#include <stdbool.h>

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i++]);
    return i-1;
}

bool isPair(int number)
{
    return (number % 2 == 0);
}

void reverse_string(char str [])
{
    int strlen = my_strlen(str);
    int middle_of_string = strlen/2;

    // if the length of the string was a pair number, the case will be ideal for the variable middle_of_string
    // if it was odd we should decrement middle_of_string by one

    if (isPair(strlen))
    {
        int middle_of_string = strlen/2 - 1;
    }
    
    for (int i = 0; i < middle_of_string; i++)
    {
        char temp = str[i];
        str[i] = str[strlen-1];
        str[strlen-1] = temp;

        strlen--;
    }
}

void reverse_word(char str[], int word_start, int word_end)
{
    char word[20];
    int word_index = 0;

    for (int i = word_start; i <= word_end; i++)
    {
        word[word_index] = str[i];
        word_index++;
    }
    word[word_index] = '\0';
    reverse_string(word);

    word_index = 0;
    for (int i = word_start; i <= word_end; i++)
    {
        str[i] = word[word_index];
        word_index++;
    }        
}

void reverse_words(char str [])
{
    reverse_string(str);

    //now let's reverse each word
    int strlen = my_strlen(str);
    int start_of_word = 0;
    int end_of_word = 0;

    for (int i = 0; i <= strlen; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            end_of_word = i-1;
            reverse_word(str, start_of_word, end_of_word);

            //this is the start of the next word
            start_of_word = i+1;
        }
    }
    
}

int main(void)
{
    char test1 [] = "The dragons are coming";
    char test2 [] = "code love I";
    char test3 [] = "G";

    printf("Before: %s\n", test1);
    reverse_words (test1);
    printf("After: %s\n\n", test1);

    printf("Before: %s\n", test2);
    reverse_words (test2);
    printf("After: %s\n\n", test2);

    printf("Before: %s\n", test3);
    reverse_words (test3);
    printf("After: %s\n\n", test3);

    return 0;
}
