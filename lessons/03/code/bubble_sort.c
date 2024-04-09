#include <stdio.h>

void swap(int *a, int *b);
void bubble_sort(int *arr, int dim);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int dim = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, dim);

    printf("Array ordinato: ");
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int dim)
{
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = 0; j < dim - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
