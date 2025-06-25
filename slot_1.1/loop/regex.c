// C program for illustration of regcomp()
#include <regex.h>
#include <stdio.h>

// Driver Code
int main()
{

    // Variable to create regex
    regex_t reegex;

    // Variable to store the return
    // value after creation of regex
    int value;

    // Function call to create regex
    value = regcomp(&reegex, "[:word:]", 0);

    // If compilation is successful
    if (value == 0)
    {
        printf("RegEx compiled successfully.");

        char names[50];
        fgets(names, sizeof(names), stdin);

        int matchResult = regexec(&reegex, names, 0, NULL, REG_EXTENDED);
        printf("matchResult %d\n", matchResult);
    }

    // Else for Compilation error
    else
    {
        printf("Compilation error.");
    }
    return 0;
}