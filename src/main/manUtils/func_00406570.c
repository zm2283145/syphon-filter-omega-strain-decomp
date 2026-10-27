#include "types.h"
typedef struct { __int128 a; __int128 b; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[1]; } H2Pack;
static inline int h2count(H2Pack* p) {
    int n = 0;
    while ((long long)p->pairs[n].a != 0) n++;
    return n;
}
/* Upper-cases text into a manifest buffer, dropping separators and padding lines to 16 bytes. */
void SKL_ConvertSKL(H2Pack* dst, char* src, int len) {
    int c;
    char* w = (char*)dst;
    char* lim = (char*)dst + 0x440;
    char* end = src + len;
    int n;
    while (src < end) {
        c = *src++;
        if (c >= 'a' && c <= 'z')
            c -= 0x20;
        *w++ = c;
        if (w >= lim)
            break;
        if (c == 0) w--;
        if (c == ' ') w--;
        if (c == '#') w--;
        if (c == '$') w--;
        if (c == '*') w--;
        if (c == '\t') w--;
        if (c == '\n') w--;
        if (c == '\r') {
            w[-1] = 0;
            while ((int)w & 0xF)
                *w++ = 0;
        }
    }
    *w = 0;
    while ((int)w & 0xF)
        *w++ = 0;
    n = h2count(dst);
    dst->pairs[n + 1].a = dst->pairs[n].a;
    dst->pairs[n + 1].b = dst->pairs[n].a;
}