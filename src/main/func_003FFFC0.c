#include "types.h"
typedef struct { char* data; short free; char flag; char type; char* base; } SkmPkt;
extern void Skm_ClassifyParts(SkmPkt* b, int a, int c);
static inline __int128 skmzero(int* pc) {
    __int128 z;
    int t;
    asm {
        paddub t, zero, zero
        pcpyld z, zero, t
    }
    *pc = t;
    return z;
}
static inline int skmeq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
void Skm_LoadPacket(SkmPkt* b, char* buf, int size, long a, long c, char flag) {
    int pad;
    __int128 z = skmzero(&pad);
    char* p = buf + size;
    p -= 16;
    b->type = buf[0];
    b->base = buf;
    b->data = buf + ((buf[0] * 2 + 0x11) & ~0xF);
    while (skmeq(*(__int128*)p, z)) {
        p -= 16;
        pad++;
    }
    b->free = (size >> 4) - pad - (b->data - (char*)*(char* volatile*)&b->base) / 16;
    if (buf[1] != 3) {
        b->data = 0;
        b->free = 0;
        b->type = 0;
    }
    b->flag = flag;
    Skm_ClassifyParts(b, a, c);
}
