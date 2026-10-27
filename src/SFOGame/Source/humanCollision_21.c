/*
 * SFOGame/Source/humanCollision: 5 files, 001E9600-001E98F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E9600 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { char pad[0x10]; __int128 q10; __int128 q20; __int128 q30; __int128 q40; __int128 q50; } P_9600;
void cPointMass_ClearPhysics(P_9600* p) {
    __int128* d; __int128* s; __int128 t; __int128* z;
    V4StoreZero(&p->q50);
    V4StoreZero(&p->q40);
    d = &p->q20; s = &p->q10; z = &p->q30;
    t = V4Load(s); V4Store(d, t);
    VZeroF(z);
}
static inline void merge_flush_func_001E9600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9600 */

/* merge_units: begin func_001E9630 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x10]; V4 pos; V4 p2; } PS;
static inline void Sub2_(V4* q, V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q)
    }
}
static inline void QCopy_(V4* pd, V4* ps) {
    /* lq into the dead source-pointer register (retail reuses it) */
    asm volatile {
        lq ps, 0(ps)
        sq ps, 0(pd)
    }
}
static inline void AddEq_(V4* x, V4* y) {
    V4* d = x; V4* e = x; V4* p = y;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cPointMass_Teleport(PS* s, V4* t) {
    V4 u;
    V4 tmp;
    Sub2_(&tmp, t, &s->pos);
    QCopy_(&u, &tmp);
    AddEq_(&s->pos, &u);
    AddEq_(&s->p2, &u);
}
#pragma pop
static inline void merge_flush_func_001E9630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9630 */

/* merge_units: begin func_001E96A0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB0]; int coll; } B5aOwner;
typedef struct { char pad[0xC]; B5aOwner* owner; char pad2[0xE4 - 0x10]; float z; } B5aObj;
extern float g_NegFltMax;
extern int D_004A03C8;
extern void* RootCollection_FindByKey(void* coll, void* key);
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
extern float* cQuatVec_Translation(void* p);
float cHumanCollisionRoutine_GetWaterDepth(B5aObj* o) {
    float r;
    if (o->z != g_NegFltMax) {
        float* p = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(&o->owner->coll, &D_004A03C8)));
        r = o->z - p[2];
    } else {
        r = 0.0f;
    }
    return r;
}
static inline void merge_flush_func_001E96A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E96A0 */

/* merge_units: begin func_001E9710 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct VC;
extern "C" VC* cVector_ctor_cVectorR(VC* d, const VC* s);
struct VC {
    float x, y, z, w;
    VC(const VC& o) { cVector_ctor_cVectorR(this, &o); }
} __attribute__((aligned(16)));
struct Mtx;
struct Node;
struct Obj8 { char pad[0x14]; unsigned char m14; char pad2[3]; char skel[0x10]; Node* m28; };
struct Self { char pad[8]; Obj8* m8; char pad2[0xE8 - 0xC]; unsigned char mE8; char pad3[7]; char plane[0x10]; };
extern "C" {
void* cArray_cBone_opIndex_int(void*, long);
void* cBone_Xform(void*);
VC* cXform_GetTranslation(void*);
Mtx* cXform_GetMatrix(Node*);
VC cVector_GetTransformed(VC* v, Mtx* m);
float cPlane_C(void*);
float Plane_HeightAt(void*, V*);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
}
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
static inline long NodeId(int m) { signed char n; if (m == 1) n = 7; else n = 11; return n; }
static inline float H2(void* pl, float x, float y) { V t; return Plane_HeightAt(pl, cVector_ctor_float_float_float_float(&t, x, y, 0.0f, 1.0f)); }
static inline float H1(void* pl, float x, float y) { return -H2(pl, x, y); }
static inline VC GetPos(Obj8* o, long n)
{
    if (o->m14) return cVector_GetTransformed(cXform_GetTranslation(cBone_Xform(cArray_cBone_opIndex_int(o->skel, n))), cXform_GetMatrix(o->m28));
    return *cXform_GetTranslation(o->m28);
}
extern "C" V cHumanCollisionRoutine_GetFloorContactPoint(Self* self, bool* hit, int mode, float thresh)
{
    V r = Unit();
    int m;
    *hit = 0;
    if (self->mE8 && (m = (unsigned char)mode)) {
        long n = NodeId(m);
        Obj8* o = self->m8;
        VC pos = GetPos(o, n);
        float px;
        float py;
        py = pos.y;
        px = pos.x;
        float z = cPlane_C(self->plane) != 0.0f ? H1(self->plane, px, py) / cPlane_C(self->plane) : 0.0f;
        r = V(px, py, z, 1.0f);
        if (pos.z - r.z < thresh) *hit = 1;
    }
    return r;
}
static inline void merge_flush_func_001E9710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9710 */

/* merge_units: begin func_001E98F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x38]; float level; } W_98F0;
typedef struct { int pad0; int id; char pad8[0xE4 - 8]; float depth; char padE8[0x170 - 0xE8]; W_98F0 water; } A_98F0;
int cWaterFx_RemoveBody(int, int);
extern int D_004FFC34;
/* drop the water effect when the actor is in water deeper than 0.974 */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cHumanCollisionRoutine_HandleHumanDeactivation(A_98F0* a)
{
    unsigned char r = 0;
    {
        float k = g_NegFltMax;
        float d = a->depth;
        if (d != g_NegFltMax) {
            W_98F0* w = (d != k) ? &a->water : 0;
            if (!(w->level <= 0.974f)) r = 1;
        }
    }
    if (r) cWaterFx_RemoveBody(D_004FFC34, a->id);
}
#pragma pop
static inline void merge_flush_func_001E98F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E98F0 */
