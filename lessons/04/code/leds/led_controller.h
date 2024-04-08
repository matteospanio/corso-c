typedef unsigned char SwitchesState;

SwitchesState switch_on_at(SwitchesState leds, int index);
SwitchesState switch_off_at(SwitchesState switches, int position);
SwitchesState switch_toggle_at(SwitchesState switches, int position);
