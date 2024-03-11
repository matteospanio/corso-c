#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Inserisci due numeri: ");
    scanf("%d %d", &a, &b);

    printf("La somma di %d e %d è %d\n", a, b, a + b);
}
