#include <stdio.h>

int main(void)
{
    int base, exp, result;

    do
    {
        // inizializza result a 1
        result = 1;

        // ricevi l'input dall'utente
        printf("Inserisci due numeri interi: ");
        scanf("%d %d", &base, &exp);

        // se l'input non è 0 0
        if (base != 0 || exp != 0)
        {
            // calcola base^exp = base * base * ...
            for (int i = 0; i < exp; i++)
            {
                result *= base;
            }
            printf("%d^%d = %d\n", base, exp, result);
        }
    } while (base != 0 || exp != 0);
}
