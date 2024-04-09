#include <stdio.h>
#define N 5
#define KEY '|'

void encode_string(char message[], int n);
void decode_string(char message[], int n);
void print_message(char message[], int n);

int main(void)
{
    char message[N] = "Hello";

    print_message(message, N);
    encode_string(message, N);
    print_message(message, N);
    decode_string(message, N);
    print_message(message, N);

}

void print_message(char message[], int n)
{
    for (int i = 0; i < n; i++) {
        if (message[i] < 32 || message[i] > 126) {
            char safe_char = (message[i] % 96) + 32;
            printf("%c", safe_char);
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}