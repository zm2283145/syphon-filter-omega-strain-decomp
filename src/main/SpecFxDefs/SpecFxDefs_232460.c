/*
 * main/SpecFxDefs: range (2 files, 00232460-002324A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "q4r.h"

/* merge_units: begin func_00232460 */
#pragma push /* merge_units */
typedef struct {
    Vec4 r[4];
} Mtx2324A0;
typedef struct {
    int id;
    Mtx2324A0* m;
} FxDesc2324A0;
typedef struct {
    char pad[0x14];
    void* vt;
} Fx2324A0;
Fx2324A0* SpawnerEffect_Ctor(Fx2324A0* self, FxDesc2324A0* d); /* gsynth: defined below */
#if 0 /* merge_units */
extern int SpawnerEffect_Ctor(int, int);
#endif /* merge_units */
#define SpawnerEffect_Ctor(a0, a1) ((int)SpawnerEffect_Ctor((void *)(a0), (void *)(a1))) /* merge_units */

extern int func_003EBFB0(int);

void Effect_CreateInstance(int a0, int a1) {
    int loc[2];
    int v0;
    int cond;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 24;
    v0 = func_003EBFB0(a0);
    a0 = v0;
    cond = a0 == 0;
    a1 = (int)loc;
    if (cond) goto L00232490;
    v0 = SpawnerEffect_Ctor(a0, a1);
L00232490:;
    goto ret;
ret:;
}
#undef SpawnerEffect_Ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232460 */

/* merge_units: begin func_002324A0 */
#pragma push /* merge_units */
typedef struct {
    signed char flag;
    unsigned char active;
    char pad2[2];
    void* vt;
    int id;
    int count;
    Mtx2324A0 m;
} FxObj2324A0;





extern char D_004DBB00[];
extern char D_004D9280[];
extern char D_004DBE90[];
extern signed char D_0048AD80;
extern void SpecFx_Construct(Fx2324A0* self);
extern FxObj2324A0* EffectComponent_Alloc(int size);
extern void EffectService_Schedule(Fx2324A0* self, FxObj2324A0* obj, float x, float y);

Fx2324A0* SpawnerEffect_Ctor(Fx2324A0* self, FxDesc2324A0* d) {
    SpecFx_Construct(self);
    self->vt = D_004DBB00;
    if (d->id >= 0) {
        FxObj2324A0* o = EffectComponent_Alloc(0x50);
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
        EffectService_Schedule(self, o, 0.0f, 0.0f);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002324A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002324A0 */
