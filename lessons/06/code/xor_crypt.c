#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY '$'

typedef char *String;

// Scrivere l'implementazione delle funzioni string_encodec e new_string
// Hint1: new_string deve allocare la memoria per la stringa text
// Hint2: string_encodec deve cifrare la stringa message con la chiave key tramite XOR
//
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

void string_encodec(String message, char key)
{
    // TODO
}

String new_string(String text)
{
    // TODO
}

void string_delete(String str)
{
    free(str);
}
