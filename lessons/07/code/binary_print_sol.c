#include <stdio.h>
#include <stdlib.h> // atoi si trova in stdlib.h

void print_binary(unsigned int n)
{
    if (n > 0)
    {
        print_binary(n >> 1);
    }
    printf("%c", (n & 1) ? '1' : '0');
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int c = atoi(argv[1]);

    printf("Binary representation of %d: ", c);
    print_binary((unsigned int)c);
    printf("\n");
    return 0;
}
