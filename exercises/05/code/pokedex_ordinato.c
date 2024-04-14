#include <stdio.h>
#define DIM_SQUADRA 6

typedef enum
{
    ACQUA,
    FUOCO,
    ERBA,
    ELETTRICO,
    PSICO,
    DRAGO,
    GHIACCIO,
    TERRA,
    ROCCIA,
    VELENO,
    VOLANTE,
    NORMALE,
    LOTTA,
} TipoPokemon;

typedef struct
{
    int id;
    char nome[64];
    TipoPokemon tipo[10];
    double peso;
    double altezza;
} Pokemon;

int main(void)
{
    Pokemon bulbasaur = {
        .id = 1,
        .nome = "Bulbasaur",
        .tipo = {ERBA, VELENO},
        .peso = 6.9,
        .altezza = 0.7,
    };

    Pokemon charmander = {
        .id = 4,
        .nome = "Charmander",
        .tipo = {FUOCO},
        .peso = 8.5,
        .altezza = 0.6,
    };

    Pokemon squirtle = {
        .id = 7,
        .nome = "Squirtle",
        .tipo = {ACQUA},
        .peso = 9.0,
        .altezza = 0.5,
    };

    Pokemon evee = {
        .id = 133,
        .nome = "Evee",
        .tipo = {NORMALE},
        .peso = 6.5,
        .altezza = 0.3,
    };

    Pokemon squadra[DIM_SQUADRA] = {bulbasaur, charmander, squirtle, evee};
}

void ordina_squadra_per_id(Pokemon *squadra, size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (squadra[j].id < squadra[i].id)
            {
                Pokemon tmp = squadra[i];
                squadra[i] = squadra[j];
                squadra[j] = tmp;
            }
        }
    }
}
