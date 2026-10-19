#include "types.h"
/* pand/pceqw/ppach are MMI instructions with no C spelling. */
typedef struct { __int128 a; __int128 b; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[1]; } H2Pack;
extern char g_AgentPartCache[];
static inline __int128 PAndI(__int128 a, __int128 b) {
    asm { pand b, a, b }
    return b;
}
static inline int PEq(__int128 a, __int128 b) {
    long long r;
    asm {
        pceqw a, a, b
        ppach r, a, a
    }
    return r == -1;
}
static inline __int128 PAnd(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
/* A name is blank when its masked bytes equal the masked blank name (mask at +0x60). */
static inline int IsBlank(__int128 v) {
    __int128 m = *(__int128*)(g_AgentPartCache + 0x60);
    __int128 x = PAndI(m, v);
    __int128 k = PAnd(m, *(__int128*)g_AgentPartCache);
    return PEq(x, k);
}
/* Removes every pair with a blank name, shifting the rest down. */
void Appearance_RemoveBlankPairs(H2Pack* p) {
    int i = 0;
    while ((long long)p->pairs[i].a != 0) {
        if (IsBlank(p->pairs[i].a) || IsBlank(p->pairs[i].b)) {
            int j = i;
            while ((long long)p->pairs[j].b != 0) {
                p->pairs[j].a = p->pairs[j + 1].a;
                p->pairs[j].b = p->pairs[j + 1].b;
                j++;
            }
        } else {
            i++;
        }
    }
}
