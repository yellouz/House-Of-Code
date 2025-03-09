#include <stdio.h>
#include <stdbool.h>

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i++]);
    return i-1;
}

bool isBracketClosed(const char *s, char bracket, int start_from, int strlen)
{
    char close_bracket = ' ';
    
    if (bracket == '(')
        close_bracket = ')';

    else if (bracket == '[')
        close_bracket = ']';

    else if (bracket == '{')
        close_bracket = '}';
    
    for (int i = start_from; i < strlen; i++)
    {
        if (s[i] == close_bracket)
            return true;
    }

    return false;
}

bool isValid(const char *s)
{
    int strlen = my_strlen(s);

    for (int i = 0; i < strlen; i++)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
            if (!isBracketClosed(s, s[i], i+1, strlen))
                return false;
        }
    }

    return true;
}

int main(void)
{
    const char *test1 = "()";
    const char *test2 = "[{()}]";
    const char *test3 = "{[(a+b) * x}";
    const char *test4 = "{[a+b]*(x/y)}";

    printf("Test 1: %s\n", test1);
    printf("Is valid: %d\n", isValid(test1));

    printf("Test 2: %s\n", test2);
    printf("Is valid: %d\n", isValid(test2));

    printf("Test 3: %s\n", test3);
    printf("Is valid: %d\n", isValid(test3));

    printf("Test 4: %s\n", test4);
    printf("Is valid: %d\n", isValid(test4));

    return 0;
}