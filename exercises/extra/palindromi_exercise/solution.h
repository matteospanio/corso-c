typedef struct nodo
{
    char value;
    struct nodo *next;
} Nodo;

/**
 * @brief add aggiunge un nodo alla lista.
 *
 * @param lista
 * @param c
 */
void add(Nodo **lista, char c);

/**
 * @brief compare_lists restituisce 1 se le due liste sono uguali, 0 altrimenti.
 *
 * @param list_a
 * @param list_b
 * @return 1 se le due liste sono uguali, 0 altrimenti.
 */
int compareLists(Nodo *list_a, Nodo *list_b);

/**
 * @brief copy contiene una lista di lunghezza uguale a src ma in ordine inverso.
 *
 * @param src
 * @param copy
 */
void copyReversed(Nodo *src, Nodo **copy);

/**
 * @brief is_palindrome restituisce 1 se la lista è palindroma, 0 altrimenti.
 *
 * @param lista lista da controllare.
 * @return 1 se la lista è palindroma, 0 altrimenti.
 */
int checkPalindrome(Nodo *lista);

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
