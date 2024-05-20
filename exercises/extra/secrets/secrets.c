#include "solution.h"
#include <stdio.h>
#include <string.h>
#define KEY_SIZE 8
#define SECRET "La vita è un biscotto, ma se piove si scioglie!"

const char *RESET = "\033[0m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";

void encodec(char *msg, char *key, char *dst)
{
    for (size_t i = 0; i < strlen(msg); i++)
    {
        dst[i] = msg[i] ^ key[i % KEY_SIZE];
        if (dst[i] < 32 || dst[i] > 126)
        {
            dst[i] = msg[i];
        }
    }
    dst[strlen(msg)] = '\0';
}

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
        char dst[sizeof(token)];
        encodec(token, "s3gr3t0", dst);
        add(&enc_msg, dst);

        token = strtok(NULL, " ");
    }

    return enc_msg;
}

void encodec_list(Nodo *list, char *key)
{
    if (list == NULL)
        return;

    char tmp[sizeof(list->value)] = {0};
    encodec(list->value, key, tmp);
    strcpy(list->value, tmp);

    encodec_list(list->next, key);
}

int main(void)
{
#ifdef ENCODE
    Nodo *enc_msg = setup();
#else
    Nodo *enc_msg = NULL;
#endif
    encodec_list(enc_msg, "s3gr3t0");
    print_list(enc_msg);

    delete_list(enc_msg);
}
