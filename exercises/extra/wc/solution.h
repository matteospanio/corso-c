typedef struct
{
    int lines;
    int words;
    int chars;
} Stats;

void wc(const char *str, Stats *counter);

void print_stats(Stats counter);
