/*
 * SFOGame/Source/path: 5 files, 0015FF90-0015FFD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015FF90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Calls two helpers with the same arguments.
 */

#include "types.h"
#include "path_types.h"

#if 0 /* merge_units */
extern int cPathNavigator_ResolvePathAfterTeleport(void* a0, int a1);
#endif /* merge_units */
void cPathNavigator_ResolvePathAfterTeleport(); /* merge_units */

extern void cPathNavigator_SetNodeIndex(void* a0, int a1);

void cPathNavigator_AdjustPathForTeleport(void* a0, int a1) {
    cPathNavigator_ResolvePathAfterTeleport(a0, a1);
    cPathNavigator_SetNodeIndex(a0, a1);
}
static inline void merge_flush_func_0015FF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FF90 */

/* merge_units: begin func_0015FFD0 */
#pragma push /* merge_units */
#include "vc_copy.h"

typedef struct { char pad[0x20]; int* ids; int pad24; int n; } T_FFD0;
typedef struct {
    char pad[0x48];
    int idx;
    int other;
    int cur;
    char pad54[0xC];
    unsigned char b0 : 3;
    unsigned char flag : 1;
    unsigned char b4 : 4;
    char pad61[0x13];
    T_FFD0* t;
} S_FFD0;
int cPathNavigator_NextPathSegment(S_FFD0* self, int i);
#if 0 /* merge_units */
void cPathNavigator_SetNodeIndex(S_FFD0* self, int id);
#endif /* merge_units */
#define cPathNavigator_SetNodeIndex(a0, a1) (cPathNavigator_SetNodeIndex((void *)(a0), (a1))) /* merge_units */

void cPathNavigator_ResolvePathAfterTeleport(S_FFD0* self, int id)
{
    if (!self->flag && id != self->cur && id != self->other) {
        T_FFD0* t = self->t;
        int n = t->n;
        int i;
        for (i = 0; i < n; i++) {
            if (id == t->ids[i]) {
                self->idx = i;
                self->cur = id;
                self->flag = !cPathNavigator_NextPathSegment(self, i);
                break;
            }
        }
    }
    cPathNavigator_SetNodeIndex(self, id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FFD0(void) {}
#undef cPathNavigator_SetNodeIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FFD0 */

/* merge_units: begin func_001600A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; int* ids; int pad24; int count; } Path_00A0;
typedef struct { char pad[0x48]; int cur; char pad2[0x74 - 0x4C]; Path_00A0* path; } S_00A0;
int cPathNavigator_GetRelativePathPosition(S_00A0* self, int id)
{
    Path_00A0* p = self->path;
    int r = 0;
    int found = -1;
    int i;
    int n = p->count;
    for (i = 0; i < n; i++) {
        if (id == p->ids[i]) {
            found = i;
            break;
        }
    }
    if (found >= 0) {
        int next = self->cur + 1;
        if (found == next)
            r = 1;
        else if (next < found)
            r = 3;
        else
            r = 2;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001600A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001600A0 */

/* merge_units: begin func_00160130 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
struct V4 { __int128 q; V4() {} };
struct Mat { V4 r[4]; Mat() {} };
class Actor {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual Mat GetMatrix();
    char pad4[0xC];
    int f10;
    unsigned char f14;
    char pad15[0x43];
    Actor* owner;
};
struct NR { char pad[0x70]; Actor* actor; V4* target; };
#define Path NR
static inline void GetPos(V4* out, Path* p)
{
    Mat m = p->actor->GetMatrix(); V4* dp = out; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } VStoreN(dp, x);
}
static inline void VSub(V4* r, V4* a, V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
/* vector length idiom (VU0 vsqrt + qmfc2/mtc1), same as src\main\cVector_GetLength.c */
static inline float Length(V4* a)
{
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory");
    return r;
}

#undef Path
extern "C" float cPathNavigator_DistanceToDestination(NR* self)
{
    float r = 0.0f;
    if (self->target) {
        V4 pos;
        V4 d;
        { Mat m = self->actor->GetMatrix();
          V4* dp; V4* dd; __int128 x; V4* t2; __int128 t; V4* pr; V4* pa; V4* pb; V4* s; Mat* pm;
          pm = &m; dp = &pos; s = &pm->r[3];
          asm { .set reorder; lq x, 0(s) }
          dd = &d; pa = &d; pr = &d;
          VStoreN(dp, x);
          pb = &pos; t2 = self->target;
          __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(t2)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(dd) : "memory"); __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory"); }
        r = Length(&d);
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160130 */

/* merge_units: begin func_001601E0 */
#pragma push /* merge_units */
typedef struct { int pad[2]; void** items; } Reg_01E0;
typedef struct { char pad[0x4C]; int a; int pad50; int b; } S_01E0;
extern Reg_01E0* D_004FFBE0;
void* cPathNavigator_GetLastNodeReached(S_01E0* self)
{
    int id = self->a;
    void* r = 0;
    id = id >= 0 ? id : self->b;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001601E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001601E0 */
