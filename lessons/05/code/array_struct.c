#include <stdio.h>
#define MAX_LEN 100 // massima lunghezza dell'array

/**
 * @brief La struttura Array rappresenta un array di interi.
 *
 * Il vantaggio di utilizzare una struttura per rappresentare un array è che si può
 * passare l'intero array come parametro ad una funzione senza dover passare anche la
 * lunghezza dell'array.
 *
 * @note Questa struttura dati può contenere esclusivamente numeri interi, per contenere
 * altri tipi di dati è necessario modificare il campo data, o creare una nuova
 * struttura.
 * @note Questa struttura dati è limitata ad un massimo di MAX_LEN elementi.
 *
 * @param data L'array di interi.
 * @param length La lunghezza dell'array.
 *
 */
typedef struct array
{
    int data[MAX_LEN];
    int length;
} Array;

void print_array(Array a);
int insert(Array *a, int index, int value);
int append(Array *a, int value);

int main(void)
{
    int err; // variabile per controllare se l'aggiunta di un elemento all'array è andata a buon fine

    // inizializza un array con 5 elementi
    Array a = {
        .data = {1, 2, 3, 4, 5}, // inizializza i primi 5 elementi dell'array
        .length = 5              // imposta la lunghezza dell'array a 5
    };

    // N.B. ho inizializzato i primi 5 elementi dell'array, in realtà il membro `data`
    // dell'array `a` contiene 100 elementi, per questo gli altri elementi dell'array
    // vengono inizializzati automaticamente a 0.

    err = append(&a, 6); // aggiungi un elemento in coda all'array
    if (err != 0)
    { // se l'aggiunta dell'elemento è fallita
        printf("Errore: l'array è pieno\n");
    }

    err = append(&a, 118);
    if (err != 0)
    {
        printf("Errore: l'array è pieno\n");
    }

    // N.B. ogni volta che si aggiunge un elemento all'array può essere avvenuto un
    // errore, per questo è necessario controllare il valore di `err` dopo ogni chiamata
    // alla funzione `append`.

    print_array(a);
}

/**
 * @brief Aggiunge un elemento in coda all'array.
 *
 * Questa funzione aggiunge un elemento in coda all'array. Dato che l'array ha una
 * capienza massima, la funzione può fallire se l'array è pieno. Per questo motivo
 * la funzione restituisce un intero che vale 0 se l'elemento è stato aggiunto
 * correttamente, 1 altrimenti.
 *
 * @param a L'array a cui aggiungere l'elemento.
 * @param value L'elemento da aggiungere.
 * @return int 0 se l'elemento è stato aggiunto correttamente, 1 altrimenti.
 */
int append(Array *a, int value)
{
    // se c'è ancora spazio nell'array
    if (a->length < MAX_LEN)
    {
        // aggiungi l'elemento in coda all'array e incrementa il contatore degli
        // elementi
        a->data[a->length] = value;
        a->length++;
        return 0;
    }
    // se l'array è pieno restituisci 1
    return 1;
}

/**
 * @brief Aggiunge un elemento in una posizione specifica dell'array.
 *
 * Questa funzione aggiunge un elemento in una posizione specifica dell'array. Dato che
 * l'array ha una capienza massima, la funzione può fallire se l'array è pieno o se
 * l'indice specificato è maggiore della lunghezza dell'array. Per questo motivo la
 * funzione restituisce un intero che vale 0 se l'elemento è stato aggiunto correttamente,
 * 1 altrimenti.
 *
 * @note La complessità computazionale di questa funzione è O(n) nel caso peggiore,
 * dove n è la lunghezza dell'array. Infatti, se l'elemento viene aggiunto in una
 * posizione diversa dalla fine dell'array, tutti gli elementi successivi devono
 * essere spostati di una posizione.
 *
 * @param a L'array a cui aggiungere l'elemento.
 * @param index L'indice in cui aggiungere l'elemento.
 * @param value L'elemento da aggiungere.
 * @return int 0 se l'elemento è stato aggiunto correttamente, 1 altrimenti.
 */
int insert(Array *a, int index, int value)
{
    // se l'indice è maggiore della lunghezza dell'array o se l'array è pieno
    if (index > a->length || a->length == MAX_LEN || index < 0)
    {
        return 1;
    }

    // sposta tutti gli elementi successivi di una posizione
    for (int i = a->length; i > index; i--)
    {
        a->data[i] = a->data[i - 1];
    }

    // aggiungi l'elemento in posizione index e incrementa il contatore degli elementi
    a->data[index] = value;
    a->length++;

    return 0;
}

/**
 * @brief Stampa a monitor l'array.
 *
 * @param a L'array da stampare.
 * @note In questo caso la funzione accetta direttamente una struct array come parametro
 * e non un puntatore ad essa, questo perché la funzione non ha bisogno di modificare
 * l'array. I puntatori invece sono utili quando si vuole modificare una variabile
 * all'interno di una funzione.
 */
void print_array(Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.data[i]);
    }
    printf("\n");
}
