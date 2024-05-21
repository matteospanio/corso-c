#include "solution.h"
#include <stdio.h>
#include <string.h>
#define SECRET "?R vZta è u] bZsc\\tDo, mR sV pZovV sZ sPioTlYe!"

/**
 * Due spie si scambiano messaggi crittografati per comunicare tra loro.
 * Una spia di un'altra organizzazione ha intercettato diversi messaggi e ha scoperto
 * che si tratta di messaggi crittografati con un algoritmo molto semplice:
 * ogni carattere del messaggio è stato trasformato in un altro carattere tramite
 * XOR con una chiave segreta. La chiave è una stringa di lunghezza pari a 8 caratteri.
 * Dopo molti mesi di lavoro la spia è riuscita a scoprire che la parola "Arrivederci"
 * quando crittografata con la chiave "s3gr3t0" diventa "2AriEeTerPi".
 * Aiuta la spia implementando l'algoritmo di decodifica in C.
 */

Nodo *setup()
{
    Nodo *enc_msg = NULL;
    char str[sizeof(SECRET)];
    strcpy(str, SECRET);

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        // char dst[sizeof(token)];
        // encodec(token, "s3gr3t0", dst);
        add(&enc_msg, token);

        token = strtok(NULL, " ");
    }

    return enc_msg;
}

int main(void)
{
    Nodo *enc_msg = setup();

    printf("Encoded message:\n");
    print_list(enc_msg);
    printf("\n");

    encodec_list(enc_msg, "s3gr3t0");

    printf("Decoded message:\n");
    print_list(enc_msg);
    printf("\n");
    delete_list(enc_msg);
}
