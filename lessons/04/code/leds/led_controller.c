#include "led_controller.h"

SwitchesState switch_on_at(SwitchesState switches, int position)
{
    return switches | (1 << position);
}
