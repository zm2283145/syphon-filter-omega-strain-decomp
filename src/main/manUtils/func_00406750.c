#include "types.h"
typedef struct { char first[16]; char second[16]; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[32]; } H2Pack;
/* Returns the first tone digit found in the manifest pairs, '_' when none. */
int Appearance_GetToneDigit(H2Pack* p) {
    char* s;
    int i;
    for (i = 0; i < 32; i++) {
        char c = p->pairs[i].first[9];
        if (c >= '0' && c <= '9')
            return c;
        s = p->pairs[i].second;
        c = s[9];
        if (c >= '0' && c <= '9')
            return c;
        if (s[0] == 0)
            return '_';
    }
    return '_';
}