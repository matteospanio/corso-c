#include <stdio.h>
#include <string.h>

void pointers(void);
void strings(void);
void confronti(void);
int are_str_equals(const char *s, const char *t);

int main(void)
{
    // modifica il main per eseguire la funzione che si vuole testare
    pointers();
    // strings();
    // confronti();
}

/**
 * Esempio di utilizzo di puntatori e degli operatori
 * ad essi associati, per ricordarsi la priorità
 * degli operatori si consulti la tabella degli operatori
 * di C nel manuale (man 7 operator).
 */
void pointers(void)
{
    int n = 50;             // dichiarazione di una variabile intera
    int *p = &n;            // dichiarazione di un puntatore a intero
    printf("n: %d\n", n);   // stampa il valore di n
    printf("*p: %d\n", *p); // stampa il valore puntato da p
    printf("p: %p\n", p);   // stampa l'indirizzo di memoria di n
    printf("&n: %p\n", &n); // stampa l'indirizzo di memoria di n
    printf("&p: %p\n", &p); // stampa l'indirizzo di memoria di p
}

void strings(void)
{
    char *s = "Hi!";
    printf("s: %s\n", s);

    // stampa i singoli caratteri
    printf("s[0]: %c\n", s[0]);
    printf("s[1]: %c\n", s[1]);
    printf("s[2]: %c\n", s[2]);
    printf("s[3]: %c\n", s[3]);
    printf("s[4]: %c\n", s[4]); // errore, index out of bounds

    printf("s: %p\n", s);
    printf("&s[0]: %p\n", &s[0]); // s[0] = *(s + 0)
    printf("&s[1]: %p\n", &s[1]); // s[1] = *(s + 1)
    printf("&s[2]: %p\n", &s[2]);
    printf("&s[3]: %p\n", &s[3]);
}

void confronti(void)
{
    int i, j;
    printf("Inserisci due numeri interi: ");
    scanf("%d", &i);
    scanf("%d", &j);
    i == j ? printf("I numeri sono uguali\n") : printf("I numeri sono diversi\n");

    char *s = "Ciao";
    char *t = "Ciao";

    /**
     * Il confronto tra stringhe deve essere effettuato per ogni
     * carattere delle stringhe, confrontare direttamente due
     * puntatori a `char` confronta gli indirizzi dei puntatori
     * e non il loro valore, non funziona neppure
     * *s == *t -> confronta solo il primo carattere di ogni stringa
     *
     * per questo bisogna usare strcmp() della libreria string.h
     */
    s == t ? printf("Le stringhe sono uguali\n") : printf("Le stringhe sono diverse\n");
    strcmp(s, t) == 0 ? printf("Le stringhe sono uguali\n") : printf("Le stringhe sono diverse\n");
}

/**
 * Funzione ricorsiva che confronta due stringhe e restituisce 1 se sono uguali
 * e 0 altrimenti.
 */
int are_str_equals(const char *s, const char *t)
{
    if (*s == '\0' && *t == '\0')
    {
        return 1;
    }
    else if (*s == *t)
    {
        return are_str_equals(s + 1, t + 1);
    }
    else
    {
        return 0;
    }
}
