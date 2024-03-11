#include <stdio.h>

int main(void)
{
    int base, exp;
    float result;

    do
    {
        result = 1.0;

        printf("Inserisci due numeri interi: ");
        scanf("%d %d", &base, &exp);

        if (base != 0 || exp != 0)
        {
            if (exp < 0)
            {
                for (int i = 0; i > exp; i--)
                {
                    result /= base;
                }
            }
            else
            {
                for (int i = 0; i < exp; i++)
                {
                    result *= base;
                }
            }
            printf("%d^%d = %.3f\n", base, exp, result);
        }
    } while (base != 0 || exp != 0);
}
