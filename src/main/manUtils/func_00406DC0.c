#include "types.h"
typedef struct { __int128 a; __int128 b; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[1]; } H2Pack;
int Appearance_GetPairCount(H2Pack* p) {
    int n = 0;
    while ((long long)p->pairs[n].a != 0) n++;
    return n;
}