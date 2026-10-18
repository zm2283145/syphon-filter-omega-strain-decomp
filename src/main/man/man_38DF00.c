/*
 * main/man: range (2 files, 0038DF00-0038E030)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);

/* merge_units: begin func_0038DF00 */
#pragma push /* merge_units */
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
unsigned int ActorModel_StepMorph(Df00Obj* self, int step, unsigned int idx, int type)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DF00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038DF00 */

/* merge_units: begin func_0038E030 */
#pragma push /* merge_units */
typedef union Name8E030 {
    __int128 q;
    char c[16];
} Name8E030;

typedef struct Part8E030 {
    Name8E030 name;
    char pad10[0x10];
} Part8E030;

typedef struct Obj8E030 {
    char pad0000[0x90];
    Part8E030 parts[0x111];
    char pad22B0[0x10];
    short texA[0x20];           /* 0x22C0 */
    short texB[0x20];           /* 0x2300 */
} Obj8E030;

extern int D_00539248;
extern short Tex_FindInList(int lib, __int128 name);
extern short TexCache_LoadErrorTexture(int lib);

void func_0038E030(Obj8E030* o)
{
    int lib = D_00539248;
    int i;
    for (i = 0; (long)o->parts[i].name.q != 0; i++) {
        Name8E030 n;
        n.q = o->parts[i].name.q;
        o->texA[i] = Tex_FindInList(lib, n.q);
        if (o->texA[i] == -1)
            o->texA[i] = TexCache_LoadErrorTexture(lib);
        n.c[14] = '1';
        o->texB[i] = Tex_FindInList(lib, n.q);
        if (o->texB[i] == -1)
            o->texB[i] = o->texA[i];
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038E030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038E030 */
