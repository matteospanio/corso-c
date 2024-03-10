#include <stdio.h>

int main(void)
{
    int analisi1, analisi2, algebra_lineare, dati_e_algoritmi, crediti_analisi1, crediti_analisi2,
        crediti_algebra_lineare, crediti_dati_e_algoritmi;

    printf("Inserisci il volto di analisi 1 e i crediti: ");
    scanf("%d %d", &analisi1, &crediti_analisi1);

    printf("Inserisci il volto di analisi 2 e i crediti: ");
    scanf("%d %d", &analisi2, &crediti_analisi2);

    printf("Inserisci il volto di algebra lineare e i crediti: ");
    scanf("%d %d", &algebra_lineare, &crediti_algebra_lineare);

    printf("Inserisci il volto di dati e algoritmi e i crediti: ");
    scanf("%d %d", &dati_e_algoritmi, &crediti_dati_e_algoritmi);

    // calcola la media ponderata
    float media_ponderata;
    int num, den;

    num = analisi1 * crediti_analisi1 + analisi2 * crediti_analisi2 + algebra_lineare * crediti_algebra_lineare +
          dati_e_algoritmi * crediti_dati_e_algoritmi;
    den = crediti_analisi1 + crediti_analisi2 + crediti_algebra_lineare + crediti_dati_e_algoritmi;

    media_ponderata = 1.0 * num / den;

    printf("La media ponderata è: %.2f\n", media_ponderata);
}
