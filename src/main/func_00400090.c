#include "types.h"
typedef struct { char* data; short free; char used; char type; char* base; int pos; } B090;
static inline __int128 b090zero(void) {
    __int128 z;
    long long t;
    asm {
        paddub t, zero, zero
        pcpyld z, zero, t
    }
    return z;
}
static inline int b090eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
/* Initialises a block reader over buf, skipping zero padding at its end. */
void func_00400090(B090* b, char* buf, int size) {
    __int128 z = b090zero();
    int pad = 0;
    char* p = buf + size;
    p -= 16;
    b->type = buf[0];
    b->base = buf;
    b->data = buf + ((buf[0] * 2 + 0x11) & ~0xF);
    while (b090eq(*(__int128*)p, z)) {
        p -= 16;
        pad++;
    }
    b->free = (size >> 4) - pad - (b->data - (char*)*(char* volatile*)&b->base) / 16;
    b->used = 0;
    b->pos = 0;
}


