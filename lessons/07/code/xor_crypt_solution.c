#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY '$'

typedef char *String;

// Scrivere l'implementazione delle funzioni string_encodec, new_string e string_delete
// Hint1: new_string deve allocare la memoria per la stringa text
// Hint2: string_encodec deve cifrare la stringa message con la chiave key tramite XOR
// Hint3: la funzione strlen restituisce la lunghezza della stringa
// Hint4: la funzione strcpy copia una stringa in un puntatore a char (vedi man strcpy)
//
// Optional: rendere la chiave KEY un argomento della riga di comando
// L'uso del programma deve essere:
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
    *str = NULL;
}
