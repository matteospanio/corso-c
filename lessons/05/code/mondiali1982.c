#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 64
#define NUM_GIOCATORI 22

typedef struct giocatore
{
    char nome[BUFFER_SIZE];
    char cognome[BUFFER_SIZE];
    unsigned int numero_maglia;
} Giocatore;

void init_squadra(Giocatore *squadra);
void print_squadra(Giocatore *giocatori, size_t n);
void ordina_squadra(Giocatore *giocatori, size_t n);

int main(void)
{
    Giocatore squadra[NUM_GIOCATORI];
    init_squadra(squadra);

    print_squadra(squadra, NUM_GIOCATORI);
    ordina_squadra(squadra, NUM_GIOCATORI);
    print_squadra(squadra, NUM_GIOCATORI);
}

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

void print_squadra(Giocatore *giocatori, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d) %s\t%s\n", giocatori[i].numero_maglia, giocatori[i].nome, giocatori[i].cognome);
    }
    printf("\n");
}

void swap(Giocatore *a, Giocatore *b)
{
    Giocatore temp = *a;
    *a = *b;
    *b = temp;
}

void ordina_squadra(Giocatore *giocatori, size_t n)
{
    bool swapped;
    for (size_t i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (giocatori[j].numero_maglia > giocatori[j + 1].numero_maglia)
            {
                swap(&giocatori[j], &giocatori[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
