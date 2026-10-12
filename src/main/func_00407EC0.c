#include "types.h"
/* Copies the stem of a file name (up to '.') into a zero-padded key. */
void Appearance_RegistryKey(char* dst, int n, char* src) {
    int i = 0;
    char c;
    while (!!(c = *src) && i < n) {
        if (c == '.')
            break;
        *dst++ = c;
        src++;
        i++;
    }
    while (i < n) {
        *dst++ = 0;
        i++;
    }
    *dst = 0;
}