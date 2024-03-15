#include "soluzione.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

chat_t make_chat(void)
{
    chat_t chat;
    chat.msg_list = make_list();

    for (int i = 0; i < MAX_CHAT_MEMBERS; i++)
    {
        chat.members[i] = NULL;
    }
    return chat;
}

void chat_clear(chat_t chat)
{
    for (size_t i = 0; i < MAX_CHAT_MEMBERS; i++)
    {
        if (chat.members[i] != NULL)
        {
            free(chat.members[i]);
        }
    }

    for (size_t i = 0; i < list_size(chat.msg_list); i++)
    {
        message_t *msg = (message_t *)list_get(chat.msg_list, i);
        msg_clear(msg);
    }
    list_destroy(chat.msg_list);
}

void chat_print(const chat_t *chat)
{
    list_t *msg_list = chat->msg_list;
    node_t *node = msg_list->head;
    struct tm *timeinfo;
    char time_str[20];
    while (node != NULL)
    {
        message_t *data = (message_t *)node->data;
        timeinfo = localtime(&(data->timestamp));
        strftime(time_str, 20, "%y-%m-%d %H:%M", timeinfo);
        printf("%s - %s: %s\n", time_str, data->sender, data->text);
        node = node->next;
    }
}

bool is_person_in_chat(const chat_t *chat, const person_t person)
{
    for (size_t i = 0; i < MAX_CHAT_MEMBERS; i++)
    {
        if (chat->members[i] != NULL && strcmp(chat->members[i], person) == 0)
        {
            return true;
        }
    }
    return false;
}

int chat_add_member(chat_t *chat, const person_t member)
{
    if (is_person_in_chat(chat, member))
    {
        return 2;
    }
    for (size_t i = 0; i < MAX_CHAT_MEMBERS; i++)
    {
        if (chat->members[i] == NULL)
        {
            chat->members[i] = malloc(strlen(member) + 1);
            if (chat->members[i] == NULL)
            {
                return 3;
            }
            strcpy(chat->members[i], member);
            return 0;
        }
    }
    return 1;
}

void msg_clear(message_t *msg)
{
    if (msg == NULL)
    {
        return;
    }
    free(msg->sender);
    free(msg->text);
    free(msg);
}

message_t *make_msg(const person_t sender, const char *text)
{
    message_t *msg = malloc(sizeof(message_t));
    if (msg == NULL)
    {
        return NULL;
    }

    msg->sender = malloc(strlen(sender) + 1);
    if (msg->sender == NULL)
    {
        free(msg);
        return NULL;
    }

    msg->text = malloc(strlen(text) + 1);
    if (msg->text == NULL)
    {
        free(msg->sender);
        free(msg);
        return NULL;
    }

    strcpy(msg->sender, sender);
    strcpy(msg->text, text);
    msg->timestamp = time(NULL);
    return msg;
}

int person_send_msg(const person_t sender, const char *msg, chat_t *chat)
{
    if (!is_person_in_chat(chat, sender))
    {
        return 1;
    }

    message_t *message = make_msg(sender, msg);
    list_append(chat->msg_list, message);

    return 0;
}

void chat_remove_member(chat_t *chat, const person_t member)
{
    for (size_t i = 0; i < MAX_CHAT_MEMBERS; i++)
    {
        if (chat->members[i] != NULL && strcmp(chat->members[i], member) == 0)
        {
            free(chat->members[i]);
            chat->members[i] = NULL;
        }
    }
}
