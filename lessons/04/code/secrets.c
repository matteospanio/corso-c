#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROGRAM_NAME "secrets"

typedef enum command
{
    ENCODE,
    DECODE,
} Command;

typedef struct
{
    char *message;
    Command command;
    int key;
} Args;

int validate_args(int argc, const char **argv, Args *args);
void print_usage();
void encode(char *dst, const char *message, int key);
void decode(char *dst, const char *message, int key);

int main(int argc, const char **argv)
{
    Args args = {NULL, -1, -1};
    int index = validate_args(argc, argv, &args);

    if (index != 0)
    {
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (args.message == NULL)
    {
        printf("Error: no message\n");
        exit(EXIT_FAILURE);
    }

    char dst[strlen(args.message) + 1];
    switch (args.command)
    {
    case ENCODE:
        encode(dst, args.message, args.key);
        break;
    case DECODE:
        decode(dst, args.message, args.key);
        break;
    default:
        printf("Error: no command\n");
        print_usage();
        exit(EXIT_FAILURE);
        break;
    }

    printf("%s\n", dst);
    exit(EXIT_SUCCESS);
}

int validate_args(int argc, const char **argv, Args *args)
{
    int i;
    if (argc < 2)
        return 1;

    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            print_usage();
            exit(EXIT_SUCCESS);
        }
        if ((strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--key") == 0) && (i + 1 < argc))
        {
            args->key = argv[i + 1][0];
        }

        if (strcmp(argv[i], "encode") == 0)
        {
            args->command = ENCODE;
            break;
        }
        if (strcmp(argv[i], "decode") == 0)
        {
            args->command = DECODE;
            break;
        }
    }
    const int index = i + 1;
    int msglen = argc;
    for (i = index; i < argc; i++)
    {
        msglen += strlen(argv[i]);
    }

    char *msg = malloc(sizeof(char) * msglen + 1);
    strcpy(msg, "");

    for (i = index; i < argc; i++)
    {
        strcat(msg, argv[i]);
        strcat(msg, " ");
    }

    args->message = msg;
    printf("%s", args->message);

    return 0;
}

void print_usage()
{
    printf("Usage: %s [options] [command] message\n", PROGRAM_NAME);
    printf("\tDecode or encode a message\n\n");
    printf("Options:\n");
    printf("\t-h, --help\t Show this help message and exit\n");
    printf("\t-k, --key KEY\t Key to encode or decode the message\n\n");
    printf("Commands:\n");
    printf("\tencode\t Encode the message\n");
    printf("\tdecode\t Decode the message\n");
}

void encode(char *dst, const char *message, int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        char c = message[i] ^ key;
        if (c < 32 || c > 126)
        {
            dst[i] = message[i];
        }
        else
        {
            dst[i] = c;
        }
    }
}

void decode(char *dst, const char *message, int key)
{
    decode(dst, message, key);
}
