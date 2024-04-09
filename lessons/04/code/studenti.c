#include <stdio.h>
#define N 8

typedef struct squadra_classificata {
    char nome[32];
    int punti;
} SquadraClassificata;

void init_classifica(SquadraClassificata classifica[], int n);

int main(void)
{
    SquadraClassificata classifica[N];
    init_classifica(classifica, N);
}

void init_classifica(SquadraClassificata classifica[], int n)
{
    classifica[0] = (SquadraClassificata){"Napoli", 90};
    classifica[1] = (SquadraClassificata){"Lazio", 74};
    classifica[2] = (SquadraClassificata){"Inter", 72};
    classifica[3] = (SquadraClassificata){"Milan", 70};
    classifica[4] = (SquadraClassificata){"Atalanta", 64};
    classifica[5] = (SquadraClassificata){"Roma", 63};
    classifica[6] = (SquadraClassificata){"Juventus", 62};
    classifica[7] = (SquadraClassificata){"Fiorentina", 56};
    classifica[8] = (SquadraClassificata){"Bologna", 54};
}