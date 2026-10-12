#include "types.h"
typedef struct { char pad0[0x80]; __int128 mask; char pad1[0xC0 - 0x90]; unsigned int count; char pad2[0x2C10 - 0xC4]; __int128 keys[1]; } K6F0;
static inline __int128 k6f0and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int k6f0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int MeshCache_FindSlot(K6F0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (k6f0eq(k6f0and(s->mask, s->keys[i]), k6f0and(s->mask, key)))
            return i;
    }
    return -1;
}
