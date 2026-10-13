#include "types.h"
extern void String_Copy(char* dst, const char* src);
extern int strcmp(const char* a, const char* b);
extern __int128* D_005712F8[];
extern unsigned int D_005712F0[];
extern char D_004BC318[];
typedef struct {
    char pad0[0x50];
    __int128 name;
    char pad60[0x23F0 - 0x60];
    float f23F0;
    char pad23F4[0x2BC0 - 0x23F4];
    unsigned char b2BC0;
    char pad2BC1;
    unsigned char idx;
} Df00Obj;
static inline __int128 df00mask(__int128 m) {
    __int128 r;
    asm { pcpyld r, zero, m }
    return r;
}
static inline int df00eqm(__int128 m, __int128 a, __int128 b) {
    __int128 y; long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
unsigned int func_0038DF00(Df00Obj* self, int step, unsigned int idx, int type)
{
    __int128 mask = df00mask(0xFFFFFFFFFFFFLL);
    __int128* tbl;
    char buf[16] __attribute__((aligned(16)));
    __int128 key;
    String_Copy(buf, "SHAPE_");
    tbl = D_005712F8[type];
    key = *(__int128*)buf;
    do {
        idx += step;
        if ((int)idx < 0) idx = D_005712F0[type] - 1;
        if (idx >= D_005712F0[type]) idx = 0;
    } while (!df00eqm(mask, key, tbl[idx]));
    self->idx = idx;
    self->name = tbl[idx];
    if (strcmp((char*)&self->name, D_004BC318) == 0) {
        self->b2BC0 = 0;
    } else {
        self->b2BC0 = 1;
        self->f23F0 = 1.0f;
    }
    return idx;
}




