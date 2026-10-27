#include "types.h"
typedef struct { char pad0[0xCC]; unsigned int count; char pad1[0xBC10 - 0xD0]; __int128 keys[1]; } KS004027E0;
static inline int ks004027E0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int FindTex__7MonsterF1(KS004027E0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (ks004027E0eq(key, s->keys[i]))
            return i;
    }
    return -1;
}