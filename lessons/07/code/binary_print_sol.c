#include <stdio.h>
#include <stdlib.h> // atoi si trova in stdlib.h

void aux_print_bin(unsigned int n, int bit)
{
    if (bit == 0)
    {
        return;
    }
    aux_print_bin(n >> 1, bit - 1);
    printf("%c", (n & 1) ? '1' : '0');
}

void print_binary(unsigned int n)
{
    // Calcola il numero di bit necessari per rappresentare n
    int bits = sizeof(n) * 8; // sizeof(n) restituisce la dimensione in byte di n
    aux_print_bin(n, bits);
}

// oppure
/*
void print_binary(unsigned int n) {
    for (int i = 31; i >= 0; --i) {
        printf("%c", (n & (1u << i)) ? '1' : '0');
    }
}
*/

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
    int c = atoi(argv[1]);

    printf("Binary representation of %d: ", c);
    print_binary((unsigned int)c);
    printf("\n");
    return 0;
}
