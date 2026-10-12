#include "types.h"
#include "q4r.h"

typedef struct {
    Vec4 r[4];
} Mtx2324A0;

typedef struct {
    signed char flag;
    unsigned char active;
    char pad2[2];
    void* vt;
    int id;
    int count;
    Mtx2324A0 m;
} FxObj2324A0;

typedef struct {
    int id;
    Mtx2324A0* m;
} FxDesc2324A0;

typedef struct {
    char pad[0x14];
    void* vt;
} Fx2324A0;

extern char D_004DBB00[];
extern char D_004D9280[];
extern char D_004DBE90[];
extern signed char D_0048AD80;
extern void SpecFx_Construct(Fx2324A0* self);
extern FxObj2324A0* func_003EC9F0(int size);
extern void func_00232050(Fx2324A0* self, FxObj2324A0* obj, float x, float y);

Fx2324A0* func_002324A0(Fx2324A0* self, FxDesc2324A0* d) {
    SpecFx_Construct(self);
    self->vt = D_004DBB00;
    if (d->id >= 0) {
        FxObj2324A0* o = func_003EC9F0(0x50);
        if (o != 0) {
            Mtx2324A0* src = d->m;
            Mtx2324A0* dst;
            __int128 qa;
            __int128 qb;
            o->vt = D_004D9280;
            o->flag = D_0048AD80;
            o->active = 0;
            o->vt = D_004DBE90;
            o->id = d->id;
            o->count = 0;
            dst = &o->m;
            /* retail two-register quad matrix copy idiom */
            Q4COPY_N(dst, src, qa, qb);
        }
        func_00232050(self, o, 0.0f, 0.0f);
    }
    return self;
}

