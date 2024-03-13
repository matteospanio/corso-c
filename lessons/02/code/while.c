#include <math.h>
#include <stdio.h>

/**
 * Esempio di utilizzo del ciclo while
 * per calcolare la potenza di un numero
 *
 * Il calcolo della potenza di un numero
 * usa la funzione pow() della libreria math.h
 * per compilare il programma è necessario
 * dire al compilatore di includere la libreria
 * matematica con il flag -lm
 *
 * gcc -o while while.c -lm
 *
 * -l significa linkare una libreria
 * m sta per math, il nome della libreria
 */

int main(void)
{
    int a = 1, b = 1;

    while (a != 0 || b != 0)
    {
        printf("Inserisci due numeri (0, 0 per uscire)\n");
        printf("Primo fattore: ");
        scanf("%d", &a);
        printf("Secondo fattore: ");
        scanf("%d", &b);
        if (a || b)
            printf("%d elevato alla %d è uguale a %d\n\n", a, b, (int)pow(a, b));
    }
}
