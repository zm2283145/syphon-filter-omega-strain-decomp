#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

struct VBig_412320 { char pad[0x8A74]; virtual void dtor(int f); };
typedef struct { void* buf; int n; int cap; } Buf_412320;
typedef struct { char pad[0x60]; void* p60; } Sub_412320;
typedef struct { char pad[0x110]; } Slot_412320;
typedef struct { char pad[0x2F6]; char f2F6; } Row_412320;
typedef struct {
    Buf_412320 bufs[2]; char pad18[0x1C - 0x18]; int f1C; int f20; char pad24[0x34 - 0x24];
    unsigned char f34; char pad35[0x50 - 0x35]; Sub_412320* p50; VBig_412320* p54;
} Self_412320;
extern "C" {
extern char D_004BEE90[];
extern Slot_412320 D_005381F0[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
void Mem_Free(int pool, void* p, char* file, int line);
void sceGsSyncPath(int a, int b, int c, int d);
}
static inline void Free_412320(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BEE90, line); }
static inline void SubDtor_412320(Sub_412320* s) { if (s) { if (s->p60) Free_412320(s->p60, 0x29A); } }

extern "C" void func_00412320(Self_412320* self)
{
    int i;
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    {
        int idx = D_00538C60;
        ((Row_412320*)&D_005381F0[idx])->f2F6 = 1;
        sceGsSyncPath(0, 0, idx, 1);
    }
    for (i = 0; i < 2; i++) {
        Free_412320(self->bufs[i].buf, 0x94);
        self->bufs[i].buf = 0;
        self->bufs[i].n = 0;
        self->bufs[i].cap = 0;
    }
    {
        Sub_412320* p = self->p50;
        if (p) {
            { AllocGuard g; SubDtor_412320(p); Mem_Free(0, p, D_004BEE90, 0x9C); }
            self->p50 = 0;
        }
    }
    {
        VBig_412320* q = self->p54;
        if (q) {
            { AllocGuard g; q->dtor(-1); Mem_Free(0, q, D_004BEE90, 0xA2); }
            self->p54 = 0;
        }
    }
    self->f1C = 0;
    self->f20 = 0;
    self->f34 = 0;
}