#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 64   // dimensione del buffer per le stringhe
#define NUM_GIOCATORI 22 // numero di giocatori in una squadra di calcio

/**
 * @brief La struttura Giocatore rappresenta un giocatore di calcio.
 *
 * @param nome Il nome del giocatore.
 * @param cognome Il cognome del giocatore.
 * @param numero_maglia Il numero di maglia del giocatore.
 *
 * @note La struttura Giocatore è definita con la keyword typedef per poter essere utilizzata come tipo di dato.
 */
typedef struct giocatore
{
    char nome[BUFFER_SIZE];
    char cognome[BUFFER_SIZE];
    unsigned int numero_maglia;
} Giocatore;

void init_squadra(Giocatore *squadra);
void print_squadra(const Giocatore *giocatori, size_t n);
void ordina_squadra(Giocatore *giocatori, size_t n);

int main(void)
{
    Giocatore squadra[NUM_GIOCATORI];
    init_squadra(squadra);

    print_squadra(squadra, NUM_GIOCATORI);
    ordina_squadra(squadra, NUM_GIOCATORI);
    print_squadra(squadra, NUM_GIOCATORI);
}

/**
 * @brief Inizializza la squadra con i giocatori della finale dei mondiali 1982.
 *
 * In C spesso si utilizzano funzioni per inizializzare le strutture dati, in questo
 * caso, la funzione init_squadra inizializza l'array di giocatori con i giocatori della
 * finale dei mondiali 1982.
 *
 * @param squadra L'array di giocatori da inizializzare.
 */
void init_squadra(Giocatore *squadra)
{
    // formazione della finale dei mondiali 1982
    // titolari
    squadra[0] = (Giocatore){"Dino", "Zoff", 1};
    squadra[1] = (Giocatore){"Giuseppe", "Bergomi", 3};
    squadra[2] = (Giocatore){"Antonio", "Cabrini", 4};
    squadra[3] = (Giocatore){"Fulvio", "Collovati", 5};
    squadra[4] = (Giocatore){"Claudio", "Gentile", 6};
    squadra[5] = (Giocatore){"Gaetano", "Scirea", 7};
    squadra[6] = (Giocatore){"Gabriele", "Oriali", 13};
    squadra[7] = (Giocatore){"Marco", "Tardelli", 14};
    squadra[8] = (Giocatore){"Bruno", "Conti", 16};
    squadra[9] = (Giocatore){"Francesco", "Graziani", 19};
    squadra[10] = (Giocatore){"Paolo", "Rossi", 20};
    // panchina
    squadra[11] = (Giocatore){"Ivano", "Bordon", 12};
    squadra[12] = (Giocatore){"Giuseppe", "Dossena", 10};
    squadra[13] = (Giocatore){"Giampiero", "Marini", 11};
    squadra[14] = (Giocatore){"Franco", "Causio", 15};
    squadra[15] = (Giocatore){"Alessandro", "Altobelli", 18};
    // riserve
    squadra[16] = (Giocatore){"Franco", "Baresi", 2};
    squadra[17] = (Giocatore){"Pietro", "Vierchowod", 8};
    squadra[18] = (Giocatore){"Giancarlo", "Antognoni", 9};
    squadra[19] = (Giocatore){"Daniele", "Massaro", 17};
    squadra[20] = (Giocatore){"France", "Selvaggi", 21};
    squadra[21] = (Giocatore){"Giovanni", "Galli", 22};
}

/**
 * @brief Stampa la squadra.
 *
 * La funzione print_squadra stampa a monitor i giocatori della squadra. Nel formato:
 * %02d) %s\t%s\n
 * ossia il numero di maglia, il nome e il cognome del giocatore.
 * Il numero di maglia è stampato con due cifre, mentre il carattere speciale '\t' è un
 * carattere di tabulazione.
 *
 * @param giocatori L'array di giocatori da stampare.
 * @param n Il numero di giocatori da stampare.
 */
void print_squadra(const Giocatore *giocatori, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d) %s\t%s\n", giocatori[i].numero_maglia, giocatori[i].nome, giocatori[i].cognome);
    }
    printf("\n");
}

/**
 * @brief Scambia due giocatori.
 *
 * La funzione swap scambia due giocatori a e b.
 *
 * @param a Il primo giocatore.
 * @param b Il secondo giocatore.
 */
void swap(Giocatore *a, Giocatore *b)
{
    Giocatore temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Ordina la squadra in base al numero di maglia.
 *
 * La funzione ordina_squadra ordina la squadra in base al numero di maglia dei
 * giocatori in ordine crescente.
 *
 * L'ordinamento è effettuato con l'algoritmo Bubble Sort, la complessità computazionale
 * è O(n^2) nel caso peggiore.
 *
 * @param giocatori L'array di giocatori da ordinare.
 * @param n La dimensione dell'array di giocatori.
 */
void ordina_squadra(Giocatore *giocatori, size_t n)
{
    // flag per controllare se ci sono stati scambi durante l'n-esima iterazione
    bool swapped;
    for (size_t i = 0; i < n - 1; i++)
    {
        // la flag è inizializzata a false all'inizio di ogni iterazione
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            // se, presa una coppia di giocatori, il numero di maglia del primo
            // giocatore è maggiore del secondo, allora scambia i giocatori
            if (giocatori[j].numero_maglia > giocatori[j + 1].numero_maglia)
            {
                swap(&giocatori[j], &giocatori[j + 1]); // scambia i giocatori
                swapped = true;                         // se ci sono stati scambi, la flag è settata a true
            }
        }
        // se non ci sono stati scambi durante l'n-esima iterazione, l'array è ordinato
        if (!swapped)
        {
            // l'istruzione break interrompe il ciclo for più esterno
            break;
        }
    }
}
