/*
 * main/game: range (2 files, 00132400-00132510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00132400 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* func_00132510(V4* a, V4* b); /* gsynth: defined below */typedef struct { Vec4 q; Vec4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { char pad0[0xA0]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* Root_Identity(void* self);
extern int Root_GetParent(F8Root* r);
extern void Root_RefreshWorldCache(F8Root* r);
extern Vec4* Quat_Assign(Vec4* d, Vec4* s);
extern Vec4* Vec4_Copy(Vec4* d, Vec4* s);
extern void* Placement_GetQuat(F8Plc* p);
extern void* Placement_GetPosition(F8Plc* p);
extern void func_00132530(F8RootW* w, void* q);
#if 0 /* merge_units */
extern void func_00132510(F8RootW* w, void* pos);
#endif /* merge_units */
#define func_00132510(a0, a1) ((void)func_00132510((void *)(a0), (void *)(a1))) /* merge_units */

static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    Quat_Assign(&d->q, &s->q);
    Vec4_Copy(&d->pos, &s->pos);
}
F8RootW* Root_GetWorldPlacement(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp;
            F8Plc* local;
            F8RootW* world;
            F8RootW* w;
            if (Root_GetParent(p)) {
                Root_RefreshWorldCache(p);
                pp = &Root_Identity(p)->world;
            } else {
                pp = &Root_Identity(p)->local;
            }
            F8PlcCopy(&Root_Identity(r)->world, &Root_Identity(r)->local);
            w = Root_Identity(r);
            func_00132530(w, Placement_GetQuat(pp));
            func_00132510(w, Placement_GetPosition(pp));
            r->dirty = 0;
        }
        return (F8RootW*)r;
    }
    return (F8RootW*)&((F8RootW*)r)->local;
}
#undef func_00132510 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132400 */

/* merge_units: begin func_00132510 */
#pragma push /* merge_units */
V4* func_00132510(V4* a, V4* b) {
    char* pv0 = (char*)a + 0x10;
    asm {
        lqc2 vf1, 0x0(pv0)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(pv0)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132510 */
