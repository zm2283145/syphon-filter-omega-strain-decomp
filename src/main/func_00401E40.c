#include "types.h"
/* pand/pnor/por/pceqw/ppach/pcpyld are MMI instructions with no C spelling. */
typedef struct {
    char pad0[0x30];
    __int128 m30;
    char pad40[0x10];
    __int128 m50;
    char pad60[0x60];
    unsigned int count;
    char padC4[0x2C10 - 0xC4];
    __int128 keys[1];
} KS00401E40;
extern char g_AgentPartCache[];
int func_00401FF0(KS00401E40* s, __int128 key, int* out, int mode, int a, int b);
static inline int ks00401E40eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks00401E40and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks00401E40or(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 ks00401E40not(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 ks00401E40from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks00401E40meq(__int128 m, __int128 a, __int128 b) {
    return ks00401E40eq(ks00401E40and(m, a), ks00401E40and(m, b));
}
/* (sub & ~mask) | (k & mask), mask at g_AgentPartCache + 0x60; in-place pands give retail registers. */
static inline __int128 Splice(__int128 sub, __int128 k) { __int128 m = *(__int128*)(g_AgentPartCache + 0x60); __int128 nm = ks00401E40not(m); asm { pand m, k, m } asm { pand k, sub, nm } return ks00401E40or(k, m); }
int func_00401E40(KS00401E40* s, __int128 key, __int128 sub, int* out, int mode, int a, int b)
{
    __int128 mask = s->m50;
    __int128 cmp;
    int n = 0;
    unsigned int i;
    if (mode == 1)
        cmp = ks00401E40from(50);
    if (mode == 0)
        cmp = ks00401E40from(49);
    for (i = 0; i < s->count; i++) {
        if (!ks00401E40meq(s->m30, s->keys[i], cmp)
            && ks00401E40meq(mask, s->keys[i], key)) {
            int r = -1;
            int got = func_00401FF0(s, Splice(sub, s->keys[i]), &r, mode, a, b);
            if (ks00401E40eq(key, s->keys[i])) {
                *out = n;
                if (r != -1)
                    *out = n + r;
            }
            if (got)
                n += got;
            else
                n++;
        }
    }
    return n;
}
