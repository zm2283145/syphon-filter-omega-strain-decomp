/*
 * main/tank: range (4 files, 00285D60-00286270)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"
#include "net_local_id.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00285D60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tank00285D60 { char p[0x6C]; void* turret; };
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285D60 */

/* merge_units: begin func_00285EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct T285EE0 { void* vt; char pad[0x5C]; int x60; void* p64; void* p68; void* p6C; };
extern "C" {
extern char cTank_vtable[];
extern char g_TargetVisMgr[];
void TargetVis_Unregister(void* mgr, int id);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void Rel285EE0(void* p, int line)
{
    if (p) {
        AllocGuard g;
        Mem_Free(0, p, D_004A93D0, line);
    }
}
extern "C" T285EE0* cTank_dtor(T285EE0* self, short del)
{
    if (self) {
        self->vt = cTank_vtable;
        Rel285EE0(self->p64, 0x1DA);
        Rel285EE0(self->p68, 0x1DD);
        Rel285EE0(self->p6C, 0x1E0);
        TargetVis_Unregister(g_TargetVisMgr, self->x60);
        cGOBJ_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285EE0 */

/* merge_units: begin func_002860F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Tank_60F0 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
void TargetVis_Register(void* list, int arg);
void Object_Register(Tank_60F0* o);
int NetMap_BindReceiver(int id, int owner, Tank_60F0* o);
void cGOBJ_ctor(Tank_60F0* o, void* id, int a, int* b);
void IdMgr_Allocate(void* out, int kind);
}
static inline int NetHostOk_60F0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" Tank_60F0* cTank_ctor(Tank_60F0* o, int arg1)
{
    char id[4];
    int z[1];
    z[0] = 0;
    IdMgr_Allocate(id, 0xF9);
    cGOBJ_ctor(o, id, 0, z);
    *(char**)o = cTank_vtable;
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    TargetVis_Register(g_TargetVisMgr, arg1);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (g_IsMultiplayer) {
        o->id10 = o->idC;
        if (!NetHostOk_60F0()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002860F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002860F0 */

/* merge_units: begin func_00286270 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Tank_6270 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
#if 0 /* merge_units */
void Object_Register(Tank_6270* o);
#endif /* merge_units */
#define Object_Register(a0) (Object_Register((Tank_60F0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int NetMap_BindReceiver(int id, int owner, Tank_6270* o);
#endif /* merge_units */
#define NetMap_BindReceiver(a0, a1, a2) (NetMap_BindReceiver((a0), (a1), (Tank_60F0 *)(a2))) /* merge_units */

#if 0 /* merge_units */
void cGOBJ_ctor(Tank_6270* o, void* id, int a, int* b);
#endif /* merge_units */
#define cGOBJ_ctor(a0, a1, a2, a3) (cGOBJ_ctor((Tank_60F0 *)(a0), (a1), (a2), (a3))) /* merge_units */

}
static inline int NetHostOk_6270(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" Tank_6270* cTank_ctor2(Tank_6270* o, int arg1, void* id)
{
    int z[1];
    z[0] = 0;
    cGOBJ_ctor(o, id, 0, z);
    *(char**)o = cTank_vtable;
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    TargetVis_Register(g_TargetVisMgr, arg1);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (g_IsMultiplayer) {
        o->id10 = o->idC;
        if (!NetHostOk_6270()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
    return o;
}
#undef Object_Register /* merge_units */
#undef NetMap_BindReceiver /* merge_units */
#undef cGOBJ_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00286270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00286270 */
