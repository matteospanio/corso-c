#ifndef TYPES_H
#define TYPES_H

typedef void T;
typedef char *string;

typedef enum error
{
    OK = 0,
    MALLOC_ERROR = 1,
    REALLOC_ERROR = 2,
    INDEX_ERROR = 3,
    UNKNOWN_ERROR = 4,
} Error;

#endif // TYPES_H
