/*
 * SFOGame/Source/terrain: 3 files, 00174770-001748B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00174770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_init_uint_uintR(PtrVec*, int, int);
extern int std_vector_imp_cObjectId_init(PtrVec*, int, int);

/* Empty vector, then fill through std_vector_imp_cObjectId_init. */
PtrVec* std_vector_cObjectId_ctor_uint_cObjectIdR(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    std_vector_imp_cObjectId_init(v, a1, a2);
    return v;
}

/* Empty vector, then fill through std_vector_pod_int_init_uint_uintR. */
PtrVec* std_vector_cGOBJPtr_ctor_uint_cGOBJPR(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    std_vector_pod_int_init_uint_uintR(v, a1, a2);
    return v;
}
static inline void merge_flush_func_00174770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174770 */

/* merge_units: begin func_001747F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_47F0 { void* vt; char pad[0x1F0]; char m1F4[0x10]; char m204[0x10]; char m214[4]; };
extern "C" { extern char D_004D9BE0[]; void std_vector_deleter_cObjectId_dtor(void* m, short f); void std_vector_cGOBJPtr_dtor(void* m, short f); void cVUM_GOBJ_dtor(void* p, short f); void operator_delete(void* p); }
extern "C" O_47F0* cTerrain_dtor(O_47F0* self, short del)
{
    if (self) {
        self->vt = D_004D9BE0;
        if (self->m214) std_vector_cGOBJPtr_dtor(self->m214, -1);
        if (self->m204) { if (self->m204) { if (self->m204) std_vector_deleter_cObjectId_dtor(self->m204, 0); } }
        if (self->m1F4) std_vector_cGOBJPtr_dtor(self->m1F4, -1);
        cVUM_GOBJ_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_001747F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001747F0 */

/* merge_units: begin func_001748B0 */
#pragma push /* merge_units */
typedef struct { int pad; unsigned char alive; } T_48B0;
typedef struct { char pad[0x6C]; int x6C; T_48B0* t; } S_48B0;
#pragma opt_propagation off
int* cVUM_GOBJ_GetCollisionModel(S_48B0* self)
{
    unsigned char dead = 1;
    T_48B0* t = self->t;
    int z = (t != 0) ^ 1;
    if (!z && !t->alive) dead = 0;
    return dead ? 0 : &self->x6C;
}
static inline void merge_flush_func_001748B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001748B0 */
