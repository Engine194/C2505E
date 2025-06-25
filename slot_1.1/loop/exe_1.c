#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char names[50] = "nguyen dac ngoc";
    char *ptr = names;
    for (int i = 0; i < strlen(names); i++)
    {
        *(ptr + i) = toupper(*(ptr + i));
    }

    printf("%s\n", names);

    return 0;
}
