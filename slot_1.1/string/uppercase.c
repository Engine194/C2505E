#include <stdio.h>
#include <string.h>
#include <ctype.h>

// void matchUpperCase(char *str) {
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if (i > 0 && (i + 1 < strlen(str) - 1 && *(ptr + i) == ' ' && *(ptr + i + 1) != ' '))
//         {
//             *(ptr + i + 1) = toupper(*(ptr + i + 1));
//         }
//         if (i == 0 && *ptr != ' ')
//         {
//             *ptr = toupper(*ptr);
//         }
//     }
// }

int main()
{

    char names[50];

    printf("Enter your name: ");
    fgets(names, sizeof(names), stdin);
    char *ptr = names;

    for (int i = 0; i < strlen(names); i++)
    {
        if (i > 0 && (i + 1 < strlen(names) - 1 && *(ptr + i) == ' ' && *(ptr + i + 1) != ' '))
        {
            *(ptr + i + 1) = toupper(*(ptr + i + 1));
        }
        if (i == 0 && *ptr != ' ')
        {
            *ptr = toupper(*ptr);
        }
    }

    return 0;
}
