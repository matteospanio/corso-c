#include "list.h"
#include <stdbool.h>
#include <time.h>

#ifndef SOLUZIONE_H
#define SOLUZIONE_H
#define MAX_CHAT_MEMBERS 256

typedef char *person_t;

typedef struct message
{
    person_t sender;
    char *text;
    time_t timestamp;
} message_t;

/**
 * @brief A chat is a list of messages.
 */
typedef struct chat
{
    person_t members[MAX_CHAT_MEMBERS];
    list_t *msg_list;
} chat_t;

/**
 * @brief Create a new chat instance.
 *
 * It allocates memory for the chat and initializes the list of messages.
 * All the members are set to NULL.
 *
 * @return chat_t the new chat instance
 * @note The chat instance must be released with chat_clear
 * @example chat_t chat = make_chat();
 */
chat_t make_chat(void);
/**
 * @brief Release the memory allocated for the chat.
 *
 * It also releases the memory allocated for the list of messages.
 *
 * @param chat the chat to clear
 */
void chat_clear(chat_t chat);
/**
 * @brief Print the chat members and the messages.
 *
 * It prints the chat members and the messages in the chat, if any.
 * The message format is:
 *
 * [timestamp] sender: text
 *
 * @param chat
 */
void chat_print(const chat_t *chat);
/**
 * @brief Add a member to the chat.
 *
 * @param chat The chat to add the member to
 * @param member The person to add to the chat
 * @return int 0 if the member was added, 1 if the chat is full, 2 if the member is already in the chat, 3 if there is
 * not enough memory
 */
int chat_add_member(chat_t *chat, const person_t member);
/**
 * @brief Remove a member from the chat.
 *
 * @param chat The chat to remove the member from
 * @param member The person to remove from the chat
 */
void chat_remove_member(chat_t *chat, const person_t member);

/**
 * @brief Create a new message instance.
 *
 * @param sender The person sending the message
 * @param text The message text
 * @return message_t* the new message instance
 */
message_t *make_msg(const person_t sender, const char *text);
/**
 * @brief Release the memory allocated for the message.
 *
 * @param msg The message to clear
 */
void msg_clear(message_t *msg);

/**
 * @brief Send a message to the chat.
 *
 * @param sender The person sending the message
 * @param msg The message to send
 * @param chat The chat to send the message to
 * @return int 0 if the message was sent, 1 if the sender is not in the chat
 */
int person_send_msg(const person_t sender, const char *msg, chat_t *chat);
/**
 * @brief Test if a person is in the given chat.
 *
 * @param chat The chat to look into
 * @param person The person to search
 * @return true If the person is in the chat
 * @return false If the person is not in the chat
 */
bool is_person_in_chat(const chat_t *chat, const person_t person);

#endif // SOLUZIONE_H
