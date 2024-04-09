#include <stdio.h>

/** Scrivere una funzione che trovi il valore minimo in un array di numeri interi
 * la firma della funzione è `int array_min(int arr[], int size)`.
 */
int array_min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

/** Scrivere una funzione ricorsiva per sommare gli elementi di un array di double,
 * la firma della funzione è `double array_sum(double arr[], int size)`.
 */
double array_sum(double arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arr[size - 1] + array_sum(arr, size - 1);
}

/** Scrivere una funzione ricorsiva che, dato un array di caratteri, ne stampi il
 * contenuto su standard output. La firma della funzione è
 * `void print_string(char arr[], int size)`.
 */
void print_string(char arr[], int size)
{
    if (size == 0)
    {
        return;
    }
    print_string(arr, size - 1);
    printf("%c", arr[size - 1]);
}

/** Modificare la soluzione dell'esercizio precedente per stampare l'array in
 * ordine inverso. Implementare poi una soluzione non ricorsiva allo stesso problema.
 */
void print_string_reverse(char arr[], int size)
{
    if (size == 0)
    {
        return;
    }
    printf("%c", arr[size - 1]);
    print_string_reverse(arr, size - 1);
}

/** Scrivere una funzione ricorsiva `all` che, dato un array di interi,
 * restituisca true se **tutti** gli elementi dell'array sono diversi da 0,
 * false altrimenti.
 */
int all(int arr[], int size)
{
    if (size == 0)
    {
        return 1;
    }
    return arr[size - 1] && all(arr, size - 1);
}

int main(void)
{
    int int_arr[] = {1, 2, 3, 4, 5, 0};
    int min = array_min(int_arr, 6);
    printf("min of [1, 2, 3, 4, 5, 0] is: %d\n", min);

    double d_arr[] = {1.5, 1.5, 1.618033};
    double sum = array_sum(d_arr, 3);
    printf("1.5 + 1.5 + 1.618033 = %f\n", sum);

    char str[] = {'C', ' ', 'i', 's', ' ', 'w', 'o', 'n', 'd', 'e', 'r', 'f', 'u', 'l'};
    print_string(str, sizeof(str)/sizeof(char));
    printf("\n");

    print_string_reverse(str, sizeof(str)/sizeof(char));
    printf("\n");

    int true_arr[] = {1, 2, 3};
    printf("%d\n", all(int_arr, 6));
    printf("%d\n", all(true_arr, 3));
    // int weird_arr[0];
    // printf("%d\n", all(weird_arr, 0));
    printf("# == $ - 1 = %d\n", '#' == '$' - 1);
}
