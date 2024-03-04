#include <stdio.h>

int main(void)
{
    int a, b;

    while (a != 0 && b != 0)
    {
        printf("Inserisci due numeri (0, 0 per uscire)\n\n");
        printf("Primo fattore:\n");
        scanf("%d", &a);
        printf("Secondo fattore:\n");
        scanf("%d", &b);
        printf("%d\n", a ^ b);
    }
}
