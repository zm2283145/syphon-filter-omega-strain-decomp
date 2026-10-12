#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Tank002835A0;
struct Tur002835A0 { char p[0x70]; };
struct Tank002835A0 { char p[0x6C]; Tur002835A0* turret; };
union Arg002835A0 { int i; float f; void* p; };
extern "C" {
void* func_002379D0(void* id);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
Tur002835A0* cTank_SetTurret(Tur002835A0* t, void* a, void* b, void* c, void* d, Tank002835A0* owner);
extern char D_004A93D0[];
}
extern "C" int Script_cTank_SetTurret(Arg002835A0* args) {
    void* a;
    void* b;
    void* c;
    void* d;
    Tur002835A0* t;
Tank002835A0* self;
Tur002835A0* old;
    d = func_002379D0(args[4].p);
    c = func_002379D0(args[3].p);
    b = func_002379D0(args[2].p);
    a = func_002379D0(args[1].p);
    self = (Tank002835A0*)args[0].p;
    old = self->turret;
    if (old) { AllocGuard g; Mem_Free(0, old, D_004A93D0, 0x1E8); }
    { AllocGuard g; t = (Tur002835A0*)Mem_Alloc(0, 0x70, D_004A93D0, 0x1EA); }
    if (t) t = cTank_SetTurret(t, a, b, c, d, self);
    self->turret = t;
    return 0;
}
