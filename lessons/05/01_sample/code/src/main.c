#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "soluzione.h"

void check_add_member_err(int err, person_t member);

int main(void)
{
    chat_t chat = make_chat();
    person_t alice = "Alice";
    person_t bob = "Bob";
    person_t charlie = "Charlie";

    int err;
    err = chat_add_member(&chat, bob);
    check_add_member_err(err, bob);
    if (err == 1)
    {
        chat_clear(chat);
        exit(EXIT_FAILURE);
    }

    err = chat_add_member(&chat, alice);
    check_add_member_err(err, alice);
    if (err == 1)
    {
        chat_clear(chat);
        exit(EXIT_FAILURE);
    }

    err = person_send_msg(alice, "Ciao Bob!", &chat);
    if (err)
    {
        fprintf(stderr, "Errore: %s non è membro della chat\n", alice);
    }

    err = person_send_msg(bob, "Ciao Alice!", &chat);
    if (err)
    {
        fprintf(stderr, "Errore: %s non è membro della chat\n", bob);
    }

    err = chat_add_member(&chat, charlie);
    check_add_member_err(err, charlie);
    if (err == 1)
    {
        chat_clear(chat);
        exit(EXIT_FAILURE);
    }

    err = person_send_msg(charlie, "Ciao Alice e Bob!", &chat);
    if (err)
    {
        fprintf(stderr, "Errore: %s non è membro della chat\n", charlie);
    }

    chat_print(&chat);
    chat_clear(chat);
    exit(EXIT_SUCCESS);
}

void check_add_member_err(int err, person_t member)
{
    switch (err)
    {
    case 0:
        break;
    case 1:
        fprintf(stderr, "Errore: %s non può essere aggiunto alla chat\n", member);
        break;
    case 2:
        fprintf(stderr, "Warning: %s è già membro della chat\n", member);
        break;
    case 3:
        fprintf(stderr, "Errore malloc %s\n", member);
        break;
    default:
        fprintf(stderr, "Errore sconosciuto\n");
        break;
    }
}
