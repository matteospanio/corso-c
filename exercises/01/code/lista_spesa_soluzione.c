#include <stdio.h>

int main(void)
{
    int prezzo1, prezzo2, prezzo3;
    char prodotto1[20], prodotto2[20], prodotto3[20];

    printf("Inserisci il nome e il prezzo del primo prodotto: ");
    scanf("%s %d", prodotto1, &prezzo1);

    printf("Inserisci il nome e il prezzo del secondo prodotto: ");
    scanf("%s %d", prodotto2, &prezzo2);

    printf("Inserisci il nome e il prezzo del terzo prodotto: ");
    scanf("%s %d", prodotto3, &prezzo3);

    printf("Lista della spesa:\n");
    printf("%s: %d euro\n", prodotto1, prezzo1);
    printf("%s: %d euro\n", prodotto2, prezzo2);
    printf("%s: %d euro\n", prodotto3, prezzo3);
}
