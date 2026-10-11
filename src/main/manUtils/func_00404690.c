#include "types.h"
typedef struct { char pad0[0xC0]; unsigned int count; char pad1[0x2C10 - 0xC4]; __int128 keys[1]; } K690;
static inline int k690eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int func_00404690(K690* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (k690eq(key, s->keys[i]))
            return i;
    }
    return 0;
}