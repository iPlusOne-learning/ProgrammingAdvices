#include <unistd.h>
#include <stdio.h>


char *Replace(char **str)
{
    return *str = "bye";
}

// char *Replace2(char **str)
// {
//     return *str = "bye";
// }
int main()
{
    char *str1 = "hello";
    char str2[] = "bye";

    char *newstr = Replace(&str1);
    printf("%s\n", str1);
    // printf("%s\n", Replace2(&str1));

    // printf("strnig 1\n");
    // printf("%s\n", str1);
    // printf("%p\n", str1);
    // printf("%p\n", &str1);
    // printf("%p\n", &str1[0]);

    // printf("\nstring 2\n");
    // printf("%p\n", str2);
    // printf("%p\n", &str2);
    // printf("%p\n", &str2[0]);

    // printf("%s\n", Replace(&str1));
    return 0;
}