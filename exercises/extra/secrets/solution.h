typedef struct nodo
{
    char value[1024];
    struct nodo *next;
} Nodo;

/**
 * @brief add aggiunge un nodo alla lista.
 *
 * @param lista
 * @param c
 */
void add(Nodo **lista, char *str);

int is_printable(char c);

void encodec(char *msg, char *key, char *dst);

void encodec_list(Nodo *list, char *key);

/**
 * @brief print_list stampa la lista.
 *
 * @param list lista da stampare.
 */
void print_list(Nodo *list);

/**
 * @brief delete_list dealloca la memoria occupata dalla lista.
 *
 * @param list lista da deallocare.
 */
void delete_list(Nodo *list);
