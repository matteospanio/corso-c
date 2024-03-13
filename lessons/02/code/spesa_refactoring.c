#include <stdio.h>
// prezzo al kg dei prodotti disponibili

void print_menu(void);
float calcola_totale(int prodotto, float peso);

int main(void)
{
    int prodotto = 0; // creo la variabile per selezionare il prodotto
    float totale = 0; // creo la variabile che contiene il costo totale
    float peso;       // creo la variabile per la quantità e una variabile temp

    while (-1 != prodotto)
    {
        print_menu();

        printf("Selezionare id prodotto: ");
        scanf("%d", &prodotto);
        printf("Specificare quantità (in kg): ");
        scanf("%f", &peso);

        totale += calcola_prezzo(prodotto, peso);
    }
    printf("Totale: %.2f\n", totale);
}

void print_menu(void)
{
    printf("Inserisci il prodotto (-1 per terminare):\n");
    printf("1) Pomodoro\n");
    printf("2) Pasta\n");
    printf("3) Biscotti\n");
    printf("4) Banane\n");
    printf("5) Pane\n\n");
}

float calcola_totale(int prodotto, float peso)
{
    float prezzo_pomodoro = 2.5f;
    float prezzo_pasta = 1.5f;
    float prezzo_biscotti = 3.0f;
    float prezzo_banane = 1.0f;
    float prezzo_pane = 2.0f;

    float parziale;
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
    return (parziale * peso);
}
