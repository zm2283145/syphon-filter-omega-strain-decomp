#include "types.h"
typedef struct { int a; int b; int c; int pad[5]; } KFD0Rec;
typedef struct { char pad0[0x80]; __int128 mask; char pad1[0xC0 - 0x90]; unsigned int count; char pad2[0x2C10 - 0xC4]; __int128 keys[0x301]; KFD0Rec recs[1]; } KFD0;
static inline __int128 kfd0and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int kfd0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int func_00403FD0(KFD0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (kfd0eq(kfd0and(s->mask, s->keys[i]), kfd0and(s->mask, key)))
            return i;
    }
    s->keys[s->count] = key;
    s->recs[s->count].c = 0;
    s->count++;
    return s->count - 1;
}