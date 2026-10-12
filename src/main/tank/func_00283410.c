#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Tank00283410;
struct Tur00283410 { char p[0x70]; };
struct Tank00283410 { char p[0x6C]; Tur00283410* turret; };
union Arg00283410 { int i; float f; void* p; };
extern "C" {
void* func_002379D0(void* id);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
Tur00283410* cTank_SetTurret(Tur00283410* t, void* a, void* b, void* c, void* d, Tank00283410* owner);
extern char D_004A93D0[];
}
extern "C" int Script_cTank_SetTurret_2(Arg00283410* args) {
    void* a;
    void* b;
    void* c;
    Tur00283410* t;
Tank00283410* self;
Tur00283410* old;
    c = func_002379D0(args[3].p);
    b = func_002379D0(args[2].p);
    a = func_002379D0(args[1].p);
    self = (Tank00283410*)args[0].p;
    old = self->turret;
    if (old) { AllocGuard g; Mem_Free(0, old, D_004A93D0, 0x1E8); }
    { AllocGuard g; t = (Tur00283410*)Mem_Alloc(0, 0x70, D_004A93D0, 0x1EA); }
    if (t) t = cTank_SetTurret(t, a, b, c, 0, self);
    self->turret = t;
    return 0;
}
