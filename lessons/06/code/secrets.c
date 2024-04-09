#include <stdio.h>
#include <string.h>
#define KEY '!'

void encode(char *dst, const char *message, char key);
void decode(char *dst, const char *message, char key);

int main(void)
{
    char secret[] = "This is a secret message!";
    char encoded[100] = "";
    char decoded[100] = "";

    encode(encoded, secret, KEY);
    printf("Encoded: %s\n", encoded);

    encode(decoded, encoded, KEY);
    printf("Decoded: %s\n", decoded);
}

void encode(char *dst, const char *message, char key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        dst[i] = message[i] ^ key;
    }
    dst[strlen(message)] = '\0';
}

void decode(char *dst, const char *message, char key)
{
    encode(dst, message, key);
}
