#include <stdio.h>

// Print the least significant bit of a number
void print_lsb(int n);

int main(void)
{
    int a = 127, b = 128;

    print_lsb(a);
    print_lsb(b);
}

void print_lsb(int n)
{
    printf("The least significant bit of %d is: ", n);
    printf("%d\n", n & 1);
}
