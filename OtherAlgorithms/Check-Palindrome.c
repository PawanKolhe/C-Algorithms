#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX_LENGTH 256

char* strrev(char *str);
 
int main() 
{
    char *string, *string_reversed;
    string = malloc(STRING_MAX_LENGTH * sizeof(int));
    string_reversed = malloc(STRING_MAX_LENGTH * sizeof(int));

    puts("Enter a string to check if it is a palindrome.");
    scanf("%s", string);

    // Make a copy in order to compare normal and reversed string.
    strcpy(string_reversed, string);
    // Reverse it!
    strrev(string_reversed);

    // Now, compare both strings.
    if (strcmp(string, string_reversed) == 0) {
        puts("String is a palindrome!");
    } else {
        puts("String is not a palindrome.");
    }

    free(string);
    free(string_reversed);

    return 0;
}

char* strrev(char *str)
{
    char c, *start, *end;

    if (!str || !*str) return str;

    for (start = str, end = str + strlen(str) - 1; start < end; start++, end--) {
        c = *start;
        *start = *end;
        *end = c;
    }

    return str;
}