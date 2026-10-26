/*
 * main/weapon: 6 files, 0013ED60-0013EEE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013ED60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* Mtx_TransformByTranspose(V4* a, V4* b) {
    asm {
        lqc2 vf8, 0x0(a)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(a)
    }
    return a;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013ED60 */

/* merge_units: begin func_0013ED90 */
#pragma push /* merge_units */
V4* Vec3_Negate(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(a)
    }
    return a;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013ED90 */

/* merge_units: begin func_0013EDB0 */
#pragma push /* merge_units */
int Mtx_IsTranslationZero(float* m) { return m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f; }
#pragma pop /* merge_units */
/* merge_units: end func_0013EDB0 */

/* merge_units: begin func_0013EE20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern int TerrainList_GetFirst(void);

/* Transpose the upper 3x3 of a 4x4 matrix in place. */
Mtx44* Mtx_Transpose3x3(Mtx44* m) {
    float m01;
    float m10;
    float m02;
    float m20;
    float m12;
    float m21;

    m01 = m->m[0][1];
    m10 = m->m[1][0];
    m->m[0][1] = m10;
    m->m[1][0] = m01;
    m02 = m->m[0][2];
    m20 = m->m[2][0];
    m->m[0][2] = m20;
    m->m[2][0] = m02;
    m12 = m->m[1][2];
    m21 = m->m[2][1];
    m->m[1][2] = m21;
    m->m[2][1] = m12;
    return m;
}

int cGOBJ_GetBBox(void) {
    return 0;
}

/* Init: owner, a value from TerrainList_GetFirst and a set flag. */
Unk0013EE70* ZoneTracker_Ctor(Unk0013EE70* self, int owner) {
    int value;

    self->owner = owner;
    value = TerrainList_GetFirst();
    self->value = value;
    self->valid = 1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013EE20 */

/* merge_units: begin func_0013EEB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma push
#pragma optimization_level 3
int SceneDraw_ComparePtr(char * arg0, char * arg1) {
    unsigned int b = F_(arg1, 0x68, int);
    unsigned int a = F_(arg0, 0x68, int);
    if (a < b) return -1; asm { .set reorder } /* barrier: keeps retail label padding */ return b < a;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0013EEB0 */

/* merge_units: begin func_0013EEE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct DbObj { VPAD16(a) VPAD4(b) virtual void Draw(); char pad[0x38]; float depth; };
typedef struct { int count; DbObj* items[1]; } DbWorld;
typedef struct { int a, b, c, d; } DbMap;
typedef struct { float f; DbObj* o; } DbPair;
typedef struct { char* p; } DbIt;
extern "C" {
extern void std_tree_pair_float_value_compare_ctor(DbMap* m, void* cmp, void* alloc);
extern void std_pair_float_cGOBJPtr_ctor(DbPair* p, float* f, DbObj** o);
extern void SceneDrawMap_Insert(DbIt* out, DbMap* m, DbPair* kv);
extern void cAssocMultiArray_float_cGOBJPtr_Begin(DbIt* out, DbMap* m);
extern void cAssocMultiArray_float_cGOBJPtr_End(DbIt* out, DbMap* m);
extern int cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(DbIt* a, DbIt* b);
extern DbObj** cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(DbIt* it);
extern void TreeIter_Increment(DbIt* it);
extern void cAssocMultiArray_float_cGOBJPtr_dtor(DbMap* m, short del);
}

extern "C" void World_DrawBuckets(DbWorld* w, int sorted)
{
    if (!sorted) {
        DbObj** p;
        for (p = w->items; p != w->items + w->count; p++)
            (*p)->Draw();
    } else {
        DbMap m;
        DbPair kv;
        DbPair tmp;
        DbIt res;
        char cmp[4];
        char alloc[4];
        float f;
        DbObj* o;
        DbIt it;
        DbIt e;
        DbObj** p;
        std_tree_pair_float_value_compare_ctor(&m, cmp, alloc);
        for (p = w->items; p != w->items + w->count; p++) {
            DbObj* q = *p;
            float d = q->depth;
            o = q;
            f = d;
            std_pair_float_cGOBJPtr_ctor(&tmp, &f, &o);
            kv.f = tmp.f;
            kv.o = tmp.o;
            SceneDrawMap_Insert(&res, &m, &kv);
        }
        cAssocMultiArray_float_cGOBJPtr_Begin(&it, &m);
        cAssocMultiArray_float_cGOBJPtr_End(&e, &m);
        while (cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(&it, &e)) {
            DbObj* d = *cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(&it);
            d->Draw();
            TreeIter_Increment(&it);
            cAssocMultiArray_float_cGOBJPtr_End(&e, &m);
        }
        cAssocMultiArray_float_cGOBJPtr_dtor(&m, -1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0013EEE0 */
