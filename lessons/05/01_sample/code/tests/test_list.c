#include "../src/list.h"
#include <assert.h>
#include <stdio.h>

static void empty_list(list_t *list)
{
    node_t *node = list->head;
    while (node != NULL)
    {
        node_t *tmp = node;
        node = node->next;
        free(tmp);
    }
    list->head = NULL;
}

void test_make_list(void)
{
    list_t *list = make_list();
    assert(list != NULL);
    assert(list->head == NULL);
    list_destroy(list);
}

void test_list_append(list_t *list)
{
    int data = 42;
    list_append(list, &data);
    list_append(list, &data);
    list_append(list, &data);

    node_t *current = list->head;
    while (current->next != NULL)
    {
        assert(*(int *)current->data == 42);
        current = current->next;
    }
    empty_list(list);
}

void test_list_prepend(list_t *list)
{
    int data[] = {0, 1, 2};

    for (int i = 0; i < 3; i++)
    {
        list_prepend(list, &data[i]);
    }

    node_t *current = list->head;
    for (int i = 0; i < 3; i++)
    {
        assert(*(int *)(current->data) == (2 - i));
        current = current->next;
    }
    empty_list(list);
}

void test_list_size(list_t *list)
{
    assert(list_size(list) == 0);
    int data[] = {0, 1, 2};

    for (int i = 0; i < 3; i++)
    {
        list_append(list, &data[i]);
    }

    assert(list_size(list) == 3);
    empty_list(list);
}

void test_list_get(list_t *list)
{
    int data[] = {0, 1, 2};
    for (int i = 0; i < 3; i++)
    {
        list_append(list, &data[i]);
    }

    int test = *(int *)list_get(list, 2);
    assert(test == 2);
    empty_list(list);
}

int main(void)
{
    list_t *list = make_list();

    test_make_list();
    test_list_append(list);
    test_list_prepend(list);
    test_list_size(list);
    test_list_get(list);

    list_destroy(list);
}
