#include <stdio.h>
#include <stdlib.h> // atoi si trova in stdlib.h

void print_binary(unsigned int n)
{
    // TODO
    // implementare la funzione print_binary
    // che stampa la rappresentazione binaria di n
    // usando la ricorsione e l'operatore di bitwise shift
}

// argc è il numero di argomenti passati al programma
// argv è un array di stringhe che contiene gli argomenti
// argv[0] è il nome del programma
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int c = atoi(argv[1]); // atoi converte la stringa argv[1] in un intero
    // atoi restituisce 0 se la stringa non è un numero valido (vedi man atoi)

    if (c < 0)
    {
        fprintf(stderr, "Error: Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Binary representation of %d: ", c);
    print_binary((unsigned int)c);
    printf("\n");
    return 0;
}
