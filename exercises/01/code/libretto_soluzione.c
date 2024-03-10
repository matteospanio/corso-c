#include <stdio.h>

int main(void)
{
    int voto_analisi1, voto_algebra_lineare, voto_java;
    int crediti_analisi1, crediti_algebra_lineare, crediti_java;
    int media_ponderata;

    printf("Inserisci il volto di analisi 1 e i crediti: ");
    scanf("%d %d", &voto_analisi1, &crediti_analisi1);

    printf("Inserisci il volto di algebra lineare e i crediti: ");
    scanf("%d %d", &voto_algebra_lineare, &crediti_algebra_lineare);

    printf("Inserisci il volto di introduzione alla programmazione e i crediti: ");
    scanf("%d %d", &voto_java, &crediti_java);

    int numeratore, denominatore;
    numeratore =
        voto_analisi1 * crediti_analisi1 + voto_algebra_lineare * crediti_algebra_lineare + voto_java * crediti_java;
    denominatore = crediti_analisi1 + crediti_algebra_lineare + crediti_java;
    media_ponderata = numeratore / denominatore;

    printf("La media ponderata è: %d\n", media_ponderata);
}
