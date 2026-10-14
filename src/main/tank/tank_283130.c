/*
 * main/tank: range (4 files, 00283130-002835A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00283130 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Path00283130 { char p[0x144]; float f144; };
struct Tread00283130 { void* f0; Path00283130* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank00283130 { char p[0x68]; Tread00283130* tread; };
union Arg00283130 { int i; float f; void* p; };
extern "C" {
void* func_002379D0(void* id);
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004A93D0[];
}
extern "C" int Script_cTank_SetRightTread(Arg00283130* args) {
    void* obj;
    Path00283130* path;
    Tread00283130* t;
Tank00283130* self;
Tread00283130* old;
    path = (Path00283130*)func_002379D0(args[2].p);
    obj = func_002379D0(args[1].p);
    self = (Tank00283130*)args[0].p;
    old = self->tread;
    if (old) { AllocGuard g; Mem_Free(0, old, D_004A93D0, 0x1F9); }
    { AllocGuard g; t = (Tread00283130*)Mem_Alloc(0, 0x2C, D_004A93D0, 0x1FB); }
    if (t) {
        t->f4 = path;
        t->f0 = obj;
        t->f24 = t->f4->f144;
        t->b28 = 0;
    }
    self->tread = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283130 */

/* merge_units: begin func_002832A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Path002832A0 { char p[0x144]; float f144; };
struct Tread002832A0 { void* f0; Path002832A0* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank002832A0 { char p[0x64]; Tread002832A0* tread; };
union Arg002832A0 { int i; float f; void* p; };
extern "C" {
}
extern "C" int Script_cTank_SetLeftTread(Arg002832A0* args) {
    void* obj;
    Path002832A0* path;
    Tread002832A0* t;
Tank002832A0* self;
Tread002832A0* old;
    path = (Path002832A0*)func_002379D0(args[2].p);
    obj = func_002379D0(args[1].p);
    self = (Tank002832A0*)args[0].p;
    old = self->tread;
    if (old) { AllocGuard g; Mem_Free(0, old, D_004A93D0, 0x1F1); }
    { AllocGuard g; t = (Tread002832A0*)Mem_Alloc(0, 0x2C, D_004A93D0, 0x1F3); }
    if (t) {
        t->f4 = path;
        t->f0 = obj;
        t->f24 = t->f4->f144;
        t->b28 = 0;
    }
    self->tread = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002832A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002832A0 */

/* merge_units: begin func_00283410 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tank00283410;
struct Tur00283410 { char p[0x70]; };
struct Tank00283410 { char p[0x6C]; Tur00283410* turret; };
union Arg00283410 { int i; float f; void* p; };
extern "C" {
Tur00283410* cTank_SetTurret(Tur00283410* t, void* a, void* b, void* c, void* d, Tank00283410* owner);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283410 */

/* merge_units: begin func_002835A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tank002835A0;
struct Tur002835A0 { char p[0x70]; };
struct Tank002835A0 { char p[0x6C]; Tur002835A0* turret; };
union Arg002835A0 { int i; float f; void* p; };
extern "C" {
#if 0 /* merge_units */
Tur002835A0* cTank_SetTurret(Tur002835A0* t, void* a, void* b, void* c, void* d, Tank002835A0* owner);
#endif /* merge_units */
#define cTank_SetTurret(a0, a1, a2, a3, a4, a5) ((Tur002835A0 *)cTank_SetTurret((Tur00283410 *)(a0), (a1), (a2), (a3), (a4), (Tank00283410 *)(a5))) /* merge_units */

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
#undef cTank_SetTurret /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002835A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002835A0 */
