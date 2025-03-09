 #include <stdio.h>

 int my_strlen(const char *str)
 {
   int i = 0;
   while (str[i++]);
   return i-1;

   // no need for comments :)
 }

 int main(void)
 {
    const char *test1 = "IAE CLUB";
    const char *test2 = "House Of Code";
    const char *test3 = "G";
    const char *test4 = "";

    printf("Test 1: %s\n", test1);
    printf("Length: %d\n", my_strlen(test1));

    printf("Test 2: %s\n", test2);
    printf("Length: %d\n", my_strlen(test2));

    printf("Test 3: %s\n", test3);
    printf("Length: %d\n", my_strlen(test3));

    printf("Test 4: %s\n", test4);
    printf("Length: %d\n", my_strlen(test4));

    return 0;
 }
