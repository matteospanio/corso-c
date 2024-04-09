#include <stdio.h>

void minmax(const int array[], int len, int *min, int *max);

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min, max;

    minmax(array, 10, &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);

    return 0;
}