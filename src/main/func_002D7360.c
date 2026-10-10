#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { float f[9]; } Blk9G5;
typedef struct { void* vt; int a[7]; signed char b; char pad21[3]; Blk9G5 d; } ObjEvG5;
extern "C" {
extern char D_004AD700[];
extern char D_004DFD80[];
extern char D_004DE4F0[];
void* Mem_Alloc(int, int, char*, int);
}
static inline void* AllocL_G5(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
extern "C" ObjEvG5* ObjectiveEvent_Clone(ObjEvG5* self)
{
    ObjEvG5* p = (ObjEvG5*)AllocL_G5(0x48, D_004AD700, 0x28);
    if (p) {
        p->vt = D_004DFD80;
        p->a[0] = self->a[0];
        p->a[1] = self->a[1];
        p->a[2] = self->a[2];
        p->a[3] = self->a[3];
        p->a[4] = self->a[4];
        p->a[5] = self->a[5];
        p->a[6] = self->a[6];
        p->b = self->b;
        p->vt = D_004DE4F0;
        p->d = self->d;
    }
    return p;
}