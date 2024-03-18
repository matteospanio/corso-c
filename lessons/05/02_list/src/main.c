#include "list.h"

int main(void)
{
    arraylist_t *arraylist;
    arraylist = arraylist_create(5);
    list_t list = {.list.arraylist = *arraylist, .type = ARRAYLIST};

    list_append(&list, "Hello");
}
