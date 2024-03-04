#include <stdio.h>

int main(void)
{
    // creo le variabili per salvare l'input
    int n1, m1, n2, m2;
    int num, den;

    // leggo da stdin
    scanf("%d/%d", &n1, &m1);
    scanf("%d/%d", &n2, &m2);

    // sommo le due frazioni
    num = n1 * m2 + n2 * m1;
    den = m1 * m2;

    // stampo a monitor il risultato
    printf("Risultato: %d/%d\n", num, den);

    int resto, a, b, mcd;
    a = num;
    b = den;
    while (b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }
    mcd = a;

    printf("Il risultato semplificato è %d/%d\n", num / mcd, den / mcd);
}
