#include <stdio.h>
#include <string.h>

/**
 * Esercizio:
 * Ordina la tua squadra pokemon per nome in ordine alfabetico.
 */

// Tipo di pokemon
typedef enum
{
    ERBA,
    FUOCO,
    ACQUA,
    DRAGO,
    PSICO,
    LOTTA,
    NORMALE,
    OSCURITA
} TipoPokemon;

typedef struct
{
    int hp;
    int attacco;
    int difesa;
    int velocita;
    int attacco_speciale;
    int difesa_speciale;
} PokeStats;

// Struttura per rappresentare un pokemon
typedef struct
{
    char nome[20];
    TipoPokemon tipo;
    PokeStats stats;
} Pokemon;

// Struttura per rappresentare una squadra di pokemon
typedef struct
{
    Pokemon pokemon[6];
    int numero_pokemon;
} SquadraPokemon;

SquadraPokemon crea_squadra(void);
void ordina_squadra(SquadraPokemon *squadra);
void stampa_squadra(SquadraPokemon *squadra);

int main(void)
{
    SquadraPokemon team = crea_squadra();
    printf("Squadra Pokemon prima dell'ordinamento:\n");
    stampa_squadra(&team);
    ordina_squadra(&team);
    printf("Squadra Pokemon dopo l'ordinamento:\n");
    stampa_squadra(&team);
}

// Funzione per creare un pokemon
Pokemon crea_pokemon(char nome[], TipoPokemon tipo)
{
    Pokemon p;
    strcpy(p.nome, nome);
    p.tipo = tipo;
    p.stats = (PokeStats){10, 5, 5, 5, 5, 5};
    return p;
}

// Crea la squadra di pokemon
SquadraPokemon crea_squadra(void)
{
    SquadraPokemon squadra;
    squadra.numero_pokemon = 0;

    // Aggiungi i pokemon alla squadra
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Psyduck", PSICO);
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Zubat", NORMALE);
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Charmander", FUOCO);
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Squirtle", ACQUA);
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Machop", LOTTA);
    squadra.pokemon[squadra.numero_pokemon++] = crea_pokemon("Bulbasaur", ERBA);

    return squadra;
}

// Funzione per ordinare la squadra di pokemon per nome
void ordina_squadra(SquadraPokemon *squadra)
{
    // TODO: Implementa l'algoritmo di ordinamento
    // Puoi usare l'algoritmo di ordinamento che preferisci
    // Puoi aggiungere funzioni e/o struct di supporto se necessario
}

void stampa_squadra(SquadraPokemon *squadra)
{
    printf("Squadra Pokemon:\n");
    for (int i = 0; i < squadra->numero_pokemon; i++)
    {
        printf("%s\n", squadra->pokemon[i].nome);
    }
}
