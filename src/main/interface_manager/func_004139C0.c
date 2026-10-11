#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

typedef struct { char pad[0xC]; } Item_4139C0;
typedef struct { int pad0; int count; Item_4139C0* data; } List_4139C0;
typedef struct { char pad[0xC]; void* obj; int active; int handle; } Ent_4139C0;
typedef struct {
    Ent_4139C0 ents[20]; int h1E0; List_4139C0* p1E4; int h1E8; List_4139C0* p1EC;
} Self_4139C0;
extern "C" {
extern char D_004BEF30[];
void Mem_Free(int pool, void* p, char* file, int line);
int func_001692D0(Item_4139C0* it);
void func_003E79F0(void* p, int f);
void func_003F9530(int a, int b);
void func_004145A0(void* p, int f);
}
static inline void D3_4139C0(void* p) { if (p) func_004145A0(p, 0); }
static inline void D2_4139C0(void* p) { if (p) D3_4139C0(p); }
static inline void D1_4139C0(void* p) { if (p) D2_4139C0(p); }

#pragma opt_strength_reduction off
extern "C" void func_004139C0(Self_4139C0* self)
{
    int i;
    Ent_4139C0* e = self->ents;
    for (i = 0; i < 20; i++, e++) {
        if (e->active && e->obj) {
            func_003F9530(self->h1E0, e->handle);
            { void* o = e->obj; AllocGuard g; func_003E79F0(o, -1); Mem_Free(0, o, D_004BEF30, 0x47); }
            e->active = 0;
            e->obj = 0;
        }
    }
    if (self->p1EC) {
        int n = self->p1EC->count;
        int j;
        for (j = 0; j < n; j++) func_003F9530(self->h1E0, func_001692D0(&self->p1EC->data[j]));
        { List_4139C0* p = self->p1EC; AllocGuard g; D1_4139C0(p); Mem_Free(0, p, D_004BEF30, 0x53); }
        self->p1EC = 0;
    }
    {
        List_4139C0* p = self->p1E4;
        if (p) {
            { AllocGuard g; D1_4139C0(p); Mem_Free(0, p, D_004BEF30, 0x5A); }
            self->p1E4 = 0;
        }
    }
    if (self->h1E8) func_003F9530(self->h1E0, self->h1E8);
    self->h1E0 = 0;
    self->h1E8 = 0;
}