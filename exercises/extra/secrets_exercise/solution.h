typedef struct node
{
    char value;
    struct node *next;
} Node;

void printMessage(const Node *list);
char charEncodec(const char c, const char key);
void listEncodec(Node *list, const char *key, const int seed);

/**
 * Calcola la lunghezza di una stringa.
 *
 * @param str la stringa di cui calcolare la lunghezza
 * @return unsigned int la lunghezza della stringa
 */
unsigned int len(const char *str);

/**
 * Verifica se un carattere è stampabile.
 *
 * Un carattere è stampabile se il suo codice ASCII è compreso tra 32 e 126.
 *
 * @param c il carattere da controllare
 * @return int 1 se il carattere è stampabile, 0 altrimenti
 */
int isPrintable(const char c);
