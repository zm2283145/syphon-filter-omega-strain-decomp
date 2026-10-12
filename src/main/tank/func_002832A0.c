#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Path002832A0 { char p[0x144]; float f144; };
struct Tread002832A0 { void* f0; Path002832A0* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank002832A0 { char p[0x64]; Tread002832A0* tread; };
union Arg002832A0 { int i; float f; void* p; };
extern "C" {
void* func_002379D0(void* id);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004A93D0[];
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
