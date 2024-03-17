#include <stdio.h>

int main(void)
{
    int x = 10;

    if (x > 7)
    {
        printf("x è maggiore di 7\n");
    }
    else if (x > 5)
    {
        printf("x è maggiore di 5\n");
    }
    else
    {
        printf("x è minore o uguale a 5\n");
    }

    return 0;
}
