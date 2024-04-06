#ifndef TYPES_H
#define TYPES_H

typedef void T;

typedef enum error
{
    MALLOC_ERROR = 1,
    REALLOC_ERROR = 2,
    INDEX_ERROR = 3,
    UNKNOWN_ERROR = 4,
    OK = 0
} Error;

#endif // TYPES_H
