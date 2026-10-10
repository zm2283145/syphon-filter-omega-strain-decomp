#include "types.h"
char* func_00129C80(const char* searchee, const char* lookfor)
{
    if (*searchee == 0) {
        if (*lookfor) return (char*)0;
        return (char*)searchee;
    }
    while (*searchee) {
        unsigned int i;
        i = 0;
        while (1) {
            if (lookfor[i] == 0) return (char*)searchee;
            if (lookfor[i] != searchee[i]) break;
            i++;
        }
        searchee++;
    }
    return (char*)0;
}