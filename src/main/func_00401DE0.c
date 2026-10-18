#include "types.h"
typedef struct { char pad0[0xCC]; unsigned int count; char pad1[0xBC10 - 0xD0]; __int128 keys[1]; } KS00401DE0;
static inline int ks00401DE0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int AgentPartCache_FindTexture(KS00401DE0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (ks00401DE0eq(key, s->keys[i]))
            return i;
    }
    return 0;
}