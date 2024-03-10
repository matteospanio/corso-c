#include <stdio.h>

int main(void)
{
    // prezzo al kg dei prodotti disponibili
    float prezzo_pomodoro = 2.5f;
    float prezzo_pasta = 1.5f;
    float prezzo_biscotti = 3.0f;
    float prezzo_banane = 1.0f;
    float prezzo_pane = 2.0f;

    int prodotto = 0;     // creo la variabile per selezionare il prodotto
    float totale = 0;     // creo la variabile che contiene il costo totale
    float peso, parziale; // creo la variabile per la quantità e una variabile temp

    /*
    Osservazioni:
    1. Prodotto va inizializzato perché si fa subito un controllo, nel caso si fosse
    usato un do while non sarebbe stato necessario.
    2. peso e parziale non serve che vengano inizializzati perché gli viene assegnato
    un valore prima di qualsiasi lettura.
    */

    while (-1 != prodotto)
    {
        printf("Inserisci il prodotto (-1 per terminare):\n");
        printf("1) Pomodoro\n");
        printf("2) Pasta\n");
        printf("3) Biscotti\n");
        printf("4) Banane\n");
        printf("5) Pane\n\n");
        printf("Selezionare id prodotto: ");
        scanf("%d", &prodotto);
        printf("Specificare quantità (in kg): ");
        scanf("%f", &peso);

        // se il peso è 0 o negativo seleziono il prodotto nullo
        if (0 >= peso)
            prodotto = 0;

        switch (prodotto)
        {
        case 1:
            parziale = prezzo_pomodoro;
            break;
        case 2:
            parziale = prezzo_pasta;
            break;
        case 3:
            parziale = prezzo_biscotti;
            break;
        case 4:
            parziale = prezzo_banane;
            break;
        case 5:
            parziale = prezzo_pane;
            break;
        default:
            // il prodotto nullo ha id 0, così, se è stato impostato un peso valido,
            // il costo aggiunto nell'operazione successiva è comunque 0.
            parziale = 0;
            break;
        }
        totale += (parziale * peso);
    }
    printf("Totale: %.2f\n", totale);
}
