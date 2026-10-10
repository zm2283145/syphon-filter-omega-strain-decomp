#include "types.h"
typedef struct { float x, y, z, w; } V4_f4;
typedef struct { float pos[4]; float dir[4]; float a; float b; float c; } LDesc_f4;
typedef struct { char pad[0x14]; void* vt; } LFx_f4;
typedef struct { int pad0; void* vt; } LObj_f4;
extern char D_004DBB20[];
extern char D_00535D20[];
extern char D_004D9200[];
extern void SpecFx_Construct(LFx_f4*);
extern LObj_f4* func_00373E70(void*, int);
extern V4_f4* Vec4_SetFromVec3W(V4_f4*, LDesc_f4*, float);
extern void func_00179540(LObj_f4*, int, V4_f4*, float*, int);
extern void func_00179530(LObj_f4*, float);
extern void func_00179520(LObj_f4*, float);
extern void func_00232050(LFx_f4*, LObj_f4*, float, float);
LFx_f4* func_00231F60(LFx_f4* self, LDesc_f4* d)
{
    LObj_f4* o;
    SpecFx_Construct(self);
    self->vt = D_004DBB20;
    o = func_00373E70(D_00535D20, 4);
    if (o) {
        float a, b;
        V4_f4 v;
        b = d->b;
        a = d->a;
        func_00179540(o, 4, Vec4_SetFromVec3W(&v, d, 0.0f), d->dir, 3);
        o->vt = D_004D9200;
        func_00179530(o, a);
        func_00179520(o, b);
    }
    if (o) {
        func_00232050(self, o, 0.0f, d->c);
    }
    return self;
}