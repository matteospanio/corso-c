#include <stdio.h>

const char KEY = 3;

char encode(char c, char key)
{
    return c ^ key;
}

char decode(char c, char key)
{
    return c ^ key;
}

int main(void)
{
#ifdef DECODE
    FILE *f = fopen("critto_telegrafo.txt", "r");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    char c;
    while (EOF != (c = fgetc(f)))
    {
        printf("%c", decode(c, KEY));
    }
#else
    FILE *f = fopen("critto_telegrafo.txt", "w");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    char c;
    while (EOF != (c = getchar()))
    {
        fputc(encode(c, KEY), f);
    }
#endif
    fclose(f);
}
