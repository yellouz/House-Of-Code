#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_str(const char* str , char delimiter)
{
    char **vector = NULL;
    int length = strlen(str);
    char word[20];

    for (int i = 0; i < length; i++)
    {
        
    }
    
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