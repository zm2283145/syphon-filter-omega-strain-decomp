#include "types.h"
void* func_00121C30(const void* key, const void* base, unsigned int nmemb, unsigned int size, int (*compar)(const void*, const void*))
{
    void* current;
    unsigned int lower = 0;
    unsigned int upper = nmemb;
    unsigned int index;
    int result;
    if (nmemb == 0 || size == 0)
        return 0;
    while (lower < upper) {
        index = (lower + upper) / 2;
        current = (void*)(((char*)base) + (index * size));
        result = compar(key, current);
        if (result < 0)
            upper = index;
        else if (result > 0)
            lower = index + 1;
        else
            return current;
    }
    return 0;
}