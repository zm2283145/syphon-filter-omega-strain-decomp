#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Rec413C70 { int a; int b; int c; unsigned char owned; };
struct Ent413C70 { char pad[0xC]; void* obj; int active; int handle; };
struct Self413C70 { Ent413C70 ents[20]; int h1E0; Rec413C70* p1E4; int h1E8; Rec413C70* p1EC; };

extern "C" {
extern char D_004BEF30[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Rec413C70* func_00413E10(Rec413C70* r);
}

static inline Rec413C70* New413C70(int line)
{
    Rec413C70* p;
    {
        AllocGuard g;
        p = (Rec413C70*)Mem_Alloc(0, 0x10, D_004BEF30, line);
    }
    if (p) {
        func_00413E10(p);
        p->owned = 1;
    }
    return p;
}

extern "C" void func_00413C70(Self413C70* self)
{
    int i;
    self->h1E0 = 0;
    if (!self->p1E4) self->p1E4 = New413C70(0x31);
    if (!self->p1EC) self->p1EC = New413C70(0x35);
    for (i = 0; i < 20; i++) {
        self->ents[i].obj = 0;
        self->ents[i].active = 0;
    }
}
