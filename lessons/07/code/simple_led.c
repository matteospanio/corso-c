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
