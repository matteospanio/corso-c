#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("size of short: %lu\n", sizeof(short));
    printf("size of int: %lu\n", sizeof(int));
    printf("size of double: %lu\n", sizeof(double));
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);
    printf("SHRT_MAX = %d\n", SHRT_MAX);
    printf("SHRT_MIN = %d\n", SHRT_MIN);
    printf("USHRT_MAX = %u\n", USHRT_MAX);
}
