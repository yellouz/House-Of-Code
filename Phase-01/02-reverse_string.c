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

int main(void)
{
    char test1 [] = "edoc fo esuoH oT emocleW";
    char test2 [] = "uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU";
    char test3 [] = "Hello World";
    char test4 [] = "G";

    printf("Before: %s\n", test1);
    reverse_string(test1);
    printf("After: %s\n\n", test1);

    printf("Before: %s\n", test2);
    reverse_string(test2);
    printf("After: %s\n\n", test2);

    printf("Before: %s\n", test3);
    reverse_string(test3);
    printf("After: %s\n\n", test3);

    printf("Before: %s\n", test4);
    reverse_string(test4);
    printf("After: %s\n\n", test4);

    return 0;
}