#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { void* vt; int f[7]; char b20; char pad21[3]; char b24; char pad25[3]; int w28; } CEv_f4;
extern "C" {
extern char D_004A0590[];
extern char D_004DFD80[];
extern char D_004DAD20[];
void* Mem_Alloc(int, int, char*, int);
}
static inline void* AllocL_f4(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
extern "C" CEv_f4* ContactEvent_Clone(CEv_f4* src)
{
    CEv_f4* e = (CEv_f4*)AllocL_f4(sizeof(CEv_f4), D_004A0590, 0x2C);
    if (e) {
        e->vt = D_004DFD80;
        e->f[0] = src->f[0];
        e->f[1] = src->f[1];
        e->f[2] = src->f[2];
        e->f[3] = src->f[3];
        e->f[4] = src->f[4];
        e->f[5] = src->f[5];
        e->f[6] = src->f[6];
        e->b20 = src->b20;
        e->vt = D_004DAD20;
        e->b24 = src->b24;
        e->w28 = src->w28;
    }
    return e;
}
