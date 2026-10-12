#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Path00283130 { char p[0x144]; float f144; };
struct Tread00283130 { void* f0; Path00283130* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank00283130 { char p[0x68]; Tread00283130* tread; };
union Arg00283130 { int i; float f; void* p; };
extern "C" {
void* func_002379D0(void* id);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
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
