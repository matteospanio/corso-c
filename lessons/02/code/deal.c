#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MANO 3
#define SEMI 4
#define VALORI 10

int main(void)
{
    bool is_in_hand[SEMI][VALORI] = {false};
    int num_cards, valore, seme;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', 'f', 'c', 'r', 'a'};
    const char suit_code[] = {'d', 'c', 'b', 's'};

    srand((unsigned)time(NULL));
    num_cards = MANO;

    printf("Le carte nella mano: ");
    while (num_cards > 0)
    {
        seme = rand() % SEMI;
        valore = rand() % VALORI;
        if (!is_in_hand[seme][valore])
        {
            is_in_hand[seme][valore] = true;
            num_cards--;
            printf(" %c%c", rank_code[valore], suit_code[seme]);
        }
    }
    printf("\n");
}
