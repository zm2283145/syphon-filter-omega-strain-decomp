#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Tank00285D60 { char p[0x6C]; void* turret; };
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void* cTank_SetTurret(void* t, void* a, void* b, void* c, void* d, void* owner);
extern char D_004A93D0[];
}
extern "C" void func_00285D60(Tank00285D60* self, void* a, void* b, void* c, void* d) {
    void* old;
    void* t;
    old = self->turret;
    if (old) { AllocGuard g; Mem_Free(0, old, D_004A93D0, 0x1E8); }
    { AllocGuard g; t = Mem_Alloc(0, 0x70, D_004A93D0, 0x1EA); }
    if (t) t = cTank_SetTurret(t, a, b, c, d, self);
    self->turret = t;
}

