#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char c[16]; } N2C4;
typedef struct { void* vt; int f4, f8, fc, f10, f14, f18, f1c; signed char b20; char p21[3]; signed char b24; char p25[3]; int f28; float f2c; float f30; N2C4 name; int f44; unsigned char b48; unsigned char b49; char p4a[2]; } M2C4;
extern "C" {
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004DFD80[];
extern char D_004DE0F0[];
}
extern "C" M2C4* func_002C4F80(M2C4* src) {
    M2C4* m;
    {
        AllocGuard g;
        m = (M2C4*)Mem_Alloc(0, 0x4C, "NetCalloutMsg.hh", 0x26);
    }
    if (m) {
        m->vt = D_004DFD80;
        m->f4 = src->f4;
        m->f8 = src->f8;
        m->fc = src->fc;
        m->f10 = src->f10;
        m->f14 = src->f14;
        m->f18 = src->f18;
        m->f1c = src->f1c;
        m->b20 = src->b20;
        m->vt = D_004DE0F0;
        m->b24 = src->b24;
        m->f28 = src->f28;
        m->f2c = src->f2c;
        m->f30 = src->f30;
        m->name = src->name;
        m->f44 = src->f44;
        m->b48 = src->b48;
        m->b49 = src->b49;
    }
    return m;
}
