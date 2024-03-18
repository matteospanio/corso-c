#include <stdio.h>

int main(void)
{
    char c;
    int chars_count = 0;
    int words_count = 1;
    printf("Scrivi una frase: ");
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            chars_count++;
        }
        else
        {
            words_count++;
        }
    }
    printf("Lunghezza media: %.1f\n", (float)chars_count / (words_count));
}
