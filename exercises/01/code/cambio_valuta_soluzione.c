#include <stdio.h>

const float TASSO_CAMBIO = 1936.27f;

int main(void)
{
    float euro, lit;

    printf("Inserisci l'importo in lire da cambiare: ");
    scanf("%f", &lit);

    euro = lit / TASSO_CAMBIO;

    printf("%.2f lire corrispondono a %.2f euro\n", lit, euro);
}
