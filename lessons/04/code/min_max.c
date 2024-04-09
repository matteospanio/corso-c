#include <stdio.h>
#define ARRAY_SIZE 10

void minmax(const int *a, int n, int *min, int *max);

int main(void)
{
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min, max;

    minmax(array, ARRAY_SIZE, &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);

    return 0;
}

void minmax(const int *a, int n, int *min, int *max)
{
    *min = a[0];
    *max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}
