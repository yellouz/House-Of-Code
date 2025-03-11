#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** add_word_to_vector(const char* str, char **vector, int start_of_word, int end_of_word, int number_of_words)
{
    // Calculate word length
    int word_length = end_of_word - start_of_word + 1;
    
    // Allocate memory for the word (+1 for null terminator)
    char* new_word = malloc(word_length + 1);

    int word_index = 0;
    for (int i = start_of_word; i <= end_of_word; i++)
    {
        new_word[word_index] = str[i];
        word_index++;
    }
    new_word[word_index] = '\0';


    // Handle first word case
    if (vector == NULL)
    {
        vector = malloc(sizeof(char*));
    } 
    else 
    {
        // Resize the vector
        char** new_vector = realloc(vector, sizeof(char*) * (number_of_words + 1));
        vector = new_vector;
    }
    
    // Store the word pointer
    vector[number_of_words] = new_word;

    return vector;
}

char** split_str(const char* str , char delimiter)
{
    char **vector = NULL;

    int strlength = strlen(str);
    int start_of_word = 0;
    int end_of_word = 0;
    int number_of_words = 0;

    for (int i = 0; i <= strlength; i++)
    {
        if (str[i] == delimiter || str[i] == '\0')
        {
            end_of_word = i-1;
            vector = add_word_to_vector(str, vector, start_of_word, end_of_word, number_of_words);

            number_of_words++;

            //this is the start of the next word
            start_of_word = i+1;
        }
    }
    return vector;
}

int main(void)
{
    char * str = "IAE ,CLUB ,CHALLANGE";
    char ** vector = split_str(str , ',');
    int i;

    i = 0;
    while (vector[i] != NULL)
    {
        printf("Substring %d : %s\n",i + 1 ,vector[i]);
        i++;
    }

    while (vector[i] != NULL)
    {
        free(vector[i]);
        i++;
    }

    free(vector);
    return (0);
}