#include <stdio.h>
#define ROWS 5
#define COLS 5

int main(void)
{
    int matrix[ROWS][COLS] = {0};
    int row_sum[ROWS] = {0};
    int col_sum[COLS] = {0};

    for (int i = 0; i < ROWS; i++)
    {
        printf("Riga %d: ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &matrix[i][j]);
            row_sum[i] += matrix[i][j];
            col_sum[j] += matrix[i][j];
        }
    }

    printf("Somma per riga: ");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ", row_sum[i]);
    }

    printf("\nSomma per colonna: ");
    for (int i = 0; i < COLS; i++)
    {
        printf("%d ", col_sum[i]);
    }
    printf("\n");
}
