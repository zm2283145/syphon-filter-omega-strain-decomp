/*
 * Libs/SFOLib/Source/interface_model: 5 files, 003F1A80-003F1E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F1A80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern int std_vector_pod_int_reserve(int a0, int a1);
extern OwnedVec* std_vector_imp_cAnimatorPtr_1_ctor(OwnedVec* v);

/* Clears the three vector words. */
OwnedVec* std_vector_cKeyframe_cXyz_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int cArray_cAnimatorPtr_ReserveActual(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

/* Reads one word from a stream cursor. */
int** cStreamingBuffer_opShr(int** cursor, int* out) {
    *out = **cursor;
    *cursor = *cursor + 1;
    return cursor;
}

OwnedVec* cArray_cAnimatorPtr_ctor(OwnedVec* v) {
    std_vector_imp_cAnimatorPtr_1_ctor(v);
    v->unk0C = 1;
    return v;
}
static inline void merge_flush_func_003F1A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1A80 */

/* merge_units: begin func_003F1B00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cAnimatorPtr_dtor)
static inline void merge_flush_func_003F1B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1B00 */

/* merge_units: begin func_003F1BF0 */
#pragma push /* merge_units */
extern char D_004E0800[];  /* IfModelItem vtable */
extern int std_vector_pod_AnimType_insert(RawVec* v, char* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* std_vector_imp_cAnimatorPtr_1_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* IfModelItem constructor. */
IfModelItem* cAnimator_ctor(IfModelItem* self) {
    self->vtable = D_004E0800;
    self->unk04 = 0;
    self->unk08 = -1.0f;
    self->unk0C = -1.0f;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

/* push_back on a vector of bytes. */
int std_vector_AnimType_push_back(RawVec* v, int value) {
    return std_vector_pod_AnimType_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_003F1BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1BF0 */

/* merge_units: begin func_003F1C60 */
#pragma push /* merge_units */
extern void func_003F1E10(char* self, int value);
extern int* func_003F1E20(PtrVec* v, int i);
extern int func_003F1E30(PtrVec* v);

typedef struct Elem3C60 {
    char pad[0x18];
    PtrVec items;
} Elem3C60;
typedef struct V12_3C60 { float x, y, z; } V12_3C60;
typedef struct Item3C60 { char pad[0x1C]; char* link; } Item3C60;

typedef struct Model3C60 {
    char pad0[0x70];
    V12_3C60* dst;
    char pad74[0x0C];
    void** elems;
    char pad84[0x1C];
    char fA0[0x0C];
    char fAC[4];
    char fB0[4];
    char fB4[4];
    char fB8[8];
    char fC0[4];
    char fC4[4];
    char fC8[4];
    char fCC[4];
} Model3C60;

void PatchAnimation(Model3C60* self, RawVec* types)
{
    void** p = self->elems;
    int i;
    for (i = 0; i < types->count; i++, p++) {
        switch ((unsigned char)types->data[i]) {
        case 0: {
            Elem3C60* e = (Elem3C60*)*p;
            V12_3C60* d = self->dst;
            int n = func_003F1E30(&e->items);
            int j;
            for (j = 0; j < n; j++) {
                func_003F1E10((char*)*func_003F1E20(&e->items, j), (int)d++);
            }
            break;
        }
        case 1: ((Item3C60*)*p)->link = self->fA0; break;
        case 2: ((Item3C60*)*p)->link = self->fAC; break;
        case 3: ((Item3C60*)*p)->link = self->fB0; break;
        case 4: ((Item3C60*)*p)->link = self->fB4; break;
        case 5: ((Item3C60*)*p)->link = self->fB8; break;
        case 6: ((Item3C60*)*p)->link = self->fC0; break;
        case 7: ((Item3C60*)*p)->link = self->fC4; break;
        case 8: ((Item3C60*)*p)->link = self->fC8; break;
        case 9: ((Item3C60*)*p)->link = self->fCC; break;
        }
    }
}
static inline void merge_flush_func_003F1C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1C60 */

/* merge_units: begin func_003F1E10 */
#pragma push /* merge_units */
/* Setter for field +0x1C. */
void func_003F1E10(char* self, int value) {
    *(int*)(self + 0x1C) = value;
}

int* func_003F1E20(PtrVec* v, int i) {
    return v->data + i;
}

/* Getter for field +0x04 (vector count). */
int func_003F1E30(PtrVec* v) {
    return v->count;
}
static inline void merge_flush_func_003F1E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1E10 */
