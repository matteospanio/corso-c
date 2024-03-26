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
