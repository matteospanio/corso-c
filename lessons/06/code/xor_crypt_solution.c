#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY '$'

typedef char *String;

// Write the implementation of xor_encodec and new_string
// Optional: make the KEY a command line argument to be parsed
// The usage of the program should be:
// ./xor_encodec key message
String new_string(String text);
void string_encodec(String message, char key);
void string_delete(String str);

int main(void)
{
    String s = new_string("Hello world!");
    if (s == NULL)
    {
        exit(EXIT_FAILURE);
    }

    printf("%s\n", s);

    string_encodec(s, KEY);
    printf("%s\n", s);

    string_encodec(s, KEY);
    printf("%s\n", s);

    string_delete(s);
}

void xor_encodec(String message, char key)
{
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = message[i] ^ key;
    }
}

String new_string(String text)
{
    String res = calloc(strlen(text), sizeof(char));
    if (res == NULL)
    {
        return NULL;
    }
    strcpy(res, text);
    return res;
}

void string_delete(String str)
{
    free(str);
}
