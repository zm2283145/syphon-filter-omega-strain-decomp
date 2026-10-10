#include "types.h"
char* strrchr(const char* s, int i)
{
    const char* last = 0;
    char c = i;
    while (*s) {
        if (*s == c)
            last = s;
        s++;
    }
    if (*s == c)
        return (char*)s;
    return (char*)last;
}