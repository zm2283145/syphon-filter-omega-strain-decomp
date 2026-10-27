#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct {
    void* vt;
    int a[7];
    char b;
    char pad21[3];
    int c[4];
} Hotbox16F;
extern "C" {
extern char D_004DFD80[];
extern char D_004D9940[];
void* cMemMan_Allocate(int, int, char*, int);
}
static inline void* AllocL_16F(int size, char* file, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, file, line);
}
extern "C" Hotbox16F* cHotboxMsg_Clone(Hotbox16F* self)
{
    Hotbox16F* p = (Hotbox16F*)AllocL_16F(0x34, "hotbox.hh", 0x4D);
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
        p->vt = D_004D9940;
        p->c[0] = self->c[0];
        p->c[1] = self->c[1];
        p->c[2] = self->c[2];
        p->c[3] = self->c[3];
    }
    return p;
}
