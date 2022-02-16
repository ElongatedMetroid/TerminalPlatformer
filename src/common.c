#include "../include/common.h"

void *xmalloc(size_t multiplier, size_t size){
    void *result = calloc(multiplier, size);
    if(result == NULL)
        ERROR("error: unable to allocate memory!");
    return result;
}
