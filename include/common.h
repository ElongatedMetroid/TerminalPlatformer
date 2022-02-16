#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>

#define MAP_DATA_PRINT_SIZE 875 // Height: 25, Width: 35 | 25*35=875

#ifdef DEBON
/*
    if DEBON is defined you can use the
    DEBUG macro to display debug info
    from the console

    fmt = what you want to display
*/
#define DEBUG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
/*
    does nothing if DEBON is not defined
*/
#define DEBUG(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#endif // DEBON

/*
    print an error message to the console and
    the current line and file then exit.

    fmt = what you want to display to the console
*/
#define ERROR(fmt)                                                             \
  do {                                                                         \
    fprintf(stderr, fmt);                                                      \
    printf("\nFILE: %s, LINE %d\n", __FILE__, __LINE__);                       \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

/*
    xmalloc allows for cleaner code, with out
    tons of malloc fail checks making your code
    messy, for things that need helpful error
    messages, use normal malloc.

    size: amount of memory to allocate
*/
void *xmalloc(size_t multiplier, size_t size);

#endif
