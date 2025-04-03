#include <stdio.h>
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);  // stampa l'indirizzo di n
    printf("%d\n", *p); // stampa il valore di n
}
