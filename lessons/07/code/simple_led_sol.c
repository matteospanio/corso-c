#include <stdio.h>

// Implement the functions:
// - print_leds: print the leds as a sequence of 1 and .
// - accendi_led: turn on the led at the given position
// - spegni_led: turn off the led at the given position
// - inverti_tutti_led: invert all the leds
// - accendi_tutti_led: turn on all the leds
// - spegni_tutti_led: turn off all the leds

void print_leds(unsigned char leds);
unsigned char accendi_led(unsigned char leds, int posizione);
unsigned char spegni_led(unsigned char leds, int posizione);
unsigned char inverti_tutti_led(unsigned char leds);
unsigned char accendi_tutti_led(unsigned char leds);
unsigned char spegni_tutti_led(unsigned char leds);

// esempi di utilizzo
void print_c();
void print_scacchiera();

int main(void)
{
    unsigned char leds = 0;

    print_leds(leds);

    leds = accendi_led(leds, 0);
    print_leds(leds);

    leds = accendi_led(leds, 7);
    print_leds(leds);

    leds = inverti_tutti_led(leds);
    print_leds(leds);

    leds = spegni_tutti_led(leds);
    print_leds(leds);
}

void print_leds(unsigned char leds)
{
    for (int i = 0; i < 8; i++)
    {
        if (leds & (128 >> i))
        {
            printf("1 ");
        }
        else
        {
            printf(". ");
        }
    }
    printf("\n");
}

unsigned char accendi_led(unsigned char leds, int posizione)
{
    return leds | (1 << posizione);
}

unsigned char spegni_led(unsigned char leds, int posizione)
{
    return leds & ~(1 << posizione);
}

unsigned char inverti_tutti_led(unsigned char leds)
{
    return leds ^ 0b11111111;
}

unsigned char accendi_tutti_led(unsigned char leds)
{
    return leds | 0b11111111;
}

unsigned char spegni_tutti_led(unsigned char leds)
{
    return leds & 0b00000000;
}

void print_c()
{
    unsigned char leds = 0b00111100;
    print_leds(leds);

    leds = accendi_led(leds, 6);
    leds = accendi_led(leds, 1);
    print_leds(leds);

    leds = accendi_tutti_led(leds);
    print_leds(leds);

    leds = spegni_tutti_led(leds);
    leds = accendi_led(leds, 7);
    leds = accendi_led(leds, 6);
    print_leds(leds);
    print_leds(leds);

    leds = accendi_tutti_led(leds);
    print_leds(leds);

    leds = spegni_led(leds, 7);
    leds = spegni_led(leds, 0);
    print_leds(leds);

    leds = spegni_led(leds, 6);
    leds = spegni_led(leds, 1);
    print_leds(leds);
}

void print_scacchiera()
{
    unsigned char leds = 0b10101010;

    for (int i = 0; i < 8; i++)
    {
        print_leds(leds);
        leds = inverti_tutti_led(leds);
    }
}
