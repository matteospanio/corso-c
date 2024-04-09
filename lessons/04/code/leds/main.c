#include "led_controller.h"
#include <stdio.h>
#include <unistd.h>

void print_switches(SwitchesState switches)
{
    char leds[8] = "OOOOOOOO";
    printf("\r");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", (switches >> i) & 1);
    }
    fflush(stdout);
}

int main(void)
{
    SwitchesState leds = 0b00000000;
    print_switches(leds);
    sleep(1);

    for (int i = 0; i < 8; i++)
    {
        leds = switch_on_at(leds, i);
        print_switches(leds);
        sleep(1);
    }

    printf("\n");
}
