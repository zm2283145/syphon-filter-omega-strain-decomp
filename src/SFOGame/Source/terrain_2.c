/*
 * SFOGame/Source/terrain: 5 files, 00173D00-00174000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00173D00 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Add(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline void merge_flush_func_00173D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D00 */

/* merge_units: begin func_00173D20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern int std_vector_pod_int_init_uint_uintR(PtrVec*, int, ValFlag*);

/* Empty vector, then fill through std_vector_pod_int_init_uint_uintR with a {value, 0} argument. */
PtrVec* std_vector_int_ctor_int_int(PtrVec* v, int a1, int value) {
    ValFlag arg;

    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    arg.value = value;
    arg.flag = 0;
    std_vector_pod_int_init_uint_uintR(v, a1, &arg);
    return v;
}
static inline void merge_flush_func_00173D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D20 */

/* merge_units: begin func_00173D60 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct { int* p; } It_173D60;
typedef struct { int pad; int size; int* data; } Vec_173D60;
typedef struct { char pad[0x204]; Vec_173D60 zones; } Zm_173D60;
typedef struct { char pad[0x4C]; int type; } Obj_173D60;

extern int D_004EE780;
#if 0 /* merge_units */
extern void cArray_cObjectId_Begin(It_173D60* out, Vec_173D60* v);
#endif /* merge_units */
void cArray_cObjectId_Begin(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cObjectId_End_void(It_173D60* out, Vec_173D60* v);
#endif /* merge_units */
void cArray_cObjectId_End_void(); /* merge_units */

#if 0 /* merge_units */
extern int cArray_cObjectId_Iterator_opNe(It_173D60* a, It_173D60* b);
#endif /* merge_units */
int cArray_cObjectId_Iterator_opNe(); /* merge_units */

#if 0 /* merge_units */
extern int* cArray_cObjectId_Iterator_opMul(It_173D60* it);
#endif /* merge_units */
int * cArray_cObjectId_Iterator_opMul(); /* merge_units */

#if 0 /* merge_units */
extern int opEq(int* a, int* b);
#endif /* merge_units */
int opEq(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cObjectId_Iterator_ctor(It_173D60* out, It_173D60* src);
#endif /* merge_units */
Word * cArray_cObjectId_Iterator_ctor(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cObjectId_Iterator_opInc(It_173D60* it);
#endif /* merge_units */
Iter * cArray_cObjectId_Iterator_opInc(); /* merge_units */

#if 0 /* merge_units */
extern int* std_vector_imp_cObjectId_end(Vec_173D60* v);
#endif /* merge_units */
int * std_vector_imp_cObjectId_end(); /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cObjectId_pointer2iterator(It_173D60* out, Vec_173D60* v, int** p);
#endif /* merge_units */
void std_vector_cObjectId_pointer2iterator(); /* merge_units */

extern void std_vector_imp_cObjectId_reserve(Vec_173D60* v, int n);
extern void std_vector_imp_cObjectId_insert(Vec_173D60* v, int* pos, int n, int* key);
extern Obj_173D60* nGobjManager_LookupGOBJ_cObjectIdR(int* id);

void cTerrain_AddActivation(Zm_173D60* self, char* zone, int recurse, char* other)
{
    int* key = (int*)(zone + 0xC);
    It_173D60 r1;
    It_173D60 r2;
    It_173D60 e;
    unsigned char ok;
    {
        It_173D60 it;
        It_173D60 end;
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (opEq(cArray_cObjectId_Iterator_opMul(&it), key)) {
                cArray_cObjectId_Iterator_ctor(&r1, &it);
                goto found1;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r1, &end);
    found1:;
    }
    ok = 1;
    if (other && self != (Zm_173D60*)other) {
        It_173D60 it;
        It_173D60 end;
        int* key2 = (int*)(other + 0xC);
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (opEq(cArray_cObjectId_Iterator_opMul(&it), key2)) {
                cArray_cObjectId_Iterator_ctor(&r2, &it);
                goto found2;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r2, &end);
    found2:
        ok = !(r2.p == self->zones.data + self->zones.size);
    }
    if (ok) {
        int* p = std_vector_imp_cObjectId_end(&self->zones);
        std_vector_cObjectId_pointer2iterator(&e, &self->zones, &p);
        if (r1.p == e.p) {
            std_vector_imp_cObjectId_reserve(&self->zones, self->zones.size + 1);
            std_vector_imp_cObjectId_insert(&self->zones, self->zones.data + self->zones.size, 1, key);
        }
    }
    if (recurse) {
        int i;
        for (i = 0; i < self->zones.size; i++) {
            Obj_173D60* o = nGobjManager_LookupGOBJ_cObjectIdR(&self->zones.data[i]);
            if (o && o != (Obj_173D60*)self && o->type == D_004EE780)
                cTerrain_AddActivation((Zm_173D60*)o, zone, 0, other);
        }
    }
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_00173D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D60 */

/* merge_units: begin func_00174000 */
#pragma push /* merge_units */
void std_vector_cObjectId_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cObjectId_end(PtrVec* v) {
    return v->data + v->count;
}

int cArray_cObjectId_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cObjectId_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}

Word* cArray_cObjectId_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word equality. */
int opEq(Word* a, Word* b) {
    return a->value == b->value;
}

int* cArray_cObjectId_Iterator_opMul(Iter* it) {
    return it->p;
}

void cArray_cObjectId_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cObjectId_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_00174000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174000 */

/* merge_units: begin func_001740E0 */
#pragma push /* merge_units */
#pragma bool off
#pragma cplusplus on
struct IdVec_40E0;
extern "C" int** std_vector_deleter_cObjectId_data_void(IdVec_40E0* v);
extern "C" 
struct IdVec_40E0 { int cap; int count; int* data; int size() const { return count; } int* begin() { return *std_vector_deleter_cObjectId_data_void(this); } int* end() { return *std_vector_deleter_cObjectId_data_void(this) + count; } };
struct It_40E0 {
    int* p;
};
static inline int NotEq(int* a, int* b) { return !(a == b); }
extern "C" {

void std_vector_pod_int_reserve(void* list, int n);
#if 0 /* merge_units */
int nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((int)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

void std_vector_cGOBJPtr_push_back(void* list, int* obj);
void std_vector_deleter_cObjectId_clear(IdVec_40E0* v);
}
typedef struct { char pad[0x1F4]; int list[4]; IdVec_40E0 ids; char pad2[0x250 - 0x210]; unsigned char resolved; } T_40E0;
extern "C" void cTerrain_FinalizeActivation(T_40E0* self)
{
    int* it = self->ids.begin();
    int* end = self->ids.end();
    std_vector_pod_int_reserve(self->list, self->ids.size());
    while (NotEq(it, end)) {
        int id = *it;
        int obj;
        it++;
        obj = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        std_vector_cGOBJPtr_push_back(self->list, &obj);
    }
    std_vector_deleter_cObjectId_clear(&self->ids);
    self->resolved = 1;
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
static inline void merge_flush_func_001740E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001740E0 */
