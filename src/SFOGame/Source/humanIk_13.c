/*
 * SFOGame/Source/humanIk: 7 files, 001D7840-001D7AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D7840 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Copy a Rec24 (0x24-byte record, see cSkaAnimDataIterator_ctor_void for its constructor). */
Rec24* cSkaAnimDataIterator_opAssign(Rec24* d, Rec24* s) {
    d->unk00 = s->unk00;
    d->unk04 = s->unk04;
    d->unk08 = s->unk08;
    d->unk0C = s->unk0C;
    d->unk10 = s->unk10;
    d->unk14 = s->unk14;
    d->unk18 = s->unk18;
    d->unk1C = s->unk1C;
    d->unk20 = s->unk20;
    return d;
}
static inline void merge_flush_func_001D7840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7840 */

/* merge_units: begin func_001D7890 */
#pragma push /* merge_units */
typedef struct { int pad0; union { unsigned int u; int i; } frames; int pad8; float fps; } C1D7890;
typedef struct { C1D7890* clip; int owner; float rate; int w0C, w10, w14, w18, w1C; unsigned char b20; } K1D7890;
extern void cSkaAnimDataIterator_GotoAnimFrame(K1D7890* k, float t);
K1D7890* cSkaAnimDataIterator_ctor_cSkaAnimDataR_cSkeletonDataR(K1D7890* k, C1D7890* clip, int owner)
{
    k->clip = clip;
    k->owner = owner;
    k->rate = 0;
    k->w0C = 0;
    k->w10 = 0;
    k->w14 = 0;
    k->w18 = 0;
    k->w1C = 0;
    k->b20 = 0;
    {
        C1D7890* c = k->clip;
        k->rate = (float)c->frames.i / ((float)c->frames.u * c->fps);
    }
    cSkaAnimDataIterator_GotoAnimFrame(k, 0.0f);
    return k;
}
static inline void merge_flush_func_001D7890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7890 */

/* merge_units: begin func_001D7940 */
#pragma push /* merge_units */
#include "stored_event_post.h"
DEFINE_STORED_EVENT_POST(cHumanIkRoutine_SendEndOfUpperBodyAnimWithRightHandLookatMessage, 0x364)
static inline void merge_flush_func_001D7940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7940 */

/* merge_units: begin func_001D79B0 */
#pragma push /* merge_units */
DEFINE_STORED_EVENT_POST(cHumanIkRoutine_SendEndOfUpperBodyAnimMessage, 0x32C)
static inline void merge_flush_func_001D79B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D79B0 */

/* merge_units: begin func_001D7A20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct It1D7A20 { char* p; };
extern "C" {
#if 0 /* merge_units */
char* std_vector_imp_cBone_begin(void* v);
#endif /* merge_units */
Elem1D0* std_vector_imp_cBone_begin(Vec1D0Array* v); /* merge_units */
#define std_vector_imp_cBone_begin(a0) ((char *)std_vector_imp_cBone_begin((Vec1D0Array *)(a0))) /* merge_units */

#if 0 /* merge_units */
char* std_vector_imp_cBone_end(void* v);
#endif /* merge_units */
Elem1D0* std_vector_imp_cBone_end(Vec1D0Array* v); /* merge_units */
#define std_vector_imp_cBone_end(a0) ((char *)std_vector_imp_cBone_end((Vec1D0Array *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cBone_pointer2iterator(It1D7A20* out, void* v, char** p);
#endif /* merge_units */
void std_vector_cBone_pointer2iterator(Iter* out, void* self, Iter* src); /* merge_units */
#define std_vector_cBone_pointer2iterator(a0, a1, a2) (std_vector_cBone_pointer2iterator((Iter *)(a0), (a1), (Iter *)(a2))) /* merge_units */

extern char* UpperBodyNodeTable[];
}
struct O1D7A20 { int pad; char* list; };
static inline bool It1D7A20_eq(char* a, char* b) { return a == b; }
static inline bool It1D7A20_ne(char* a, char* b) { return !It1D7A20_eq(a, b); }
extern "C" void cHumanIkRoutine_InitializeWorkspaceAtStartOfNextFrame(O1D7A20* o)
{
    void* v = o->list + 0x18;
    It1D7A20 it;
    It1D7A20 end;
    char* p;
    {
        char* t = std_vector_imp_cBone_begin(v);
        std_vector_cBone_pointer2iterator(&it, v, &t);
    }
    p = it.p;
    {
        char* t = std_vector_imp_cBone_end(v);
        std_vector_cBone_pointer2iterator(&end, v, &t);
    }
    char** out = UpperBodyNodeTable;
    char* e = end.p;
    for (; It1D7A20_ne(p, e); p += 0x1D0) {
        *out = p;
        out += 0x40;
    }
}
#undef std_vector_imp_cBone_begin /* merge_units */
#undef std_vector_imp_cBone_end /* merge_units */
#undef std_vector_cBone_pointer2iterator /* merge_units */
static inline void merge_flush_func_001D7A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7A20 */

/* merge_units: begin func_001D7AD0 */
#pragma push /* merge_units */
/* End pointer of an array of 0x1D0-byte records. */
Elem1D0* std_vector_imp_cBone_end(Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void std_vector_cBone_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem1D0* std_vector_imp_cBone_begin(Vec1D0Array* v) {
    return v->data;
}
static inline void merge_flush_func_001D7AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7AD0 */

/* merge_units: begin func_001D7B20 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7B20;
typedef struct { float x, y, z; float pad; V4_7B20 q10; V4_7B20 q20; } T_7B20;
typedef struct { char pad[0xC0]; unsigned char* pC0; char padC4[0x1D0 - 0xC4]; } E_7B20;
typedef struct { int pad; unsigned int count; E_7B20* data; } V_7B20;
typedef struct R_7B20 { char pad[0x10]; char xf[0x60]; unsigned char b70; char pad71[0x47]; unsigned char bB8; char padB9[7]; struct R_7B20* pC0; char padC4[0x3C]; } R_7B20;
#if 0 /* merge_units */
extern R_7B20 UpperBodyNodeTable[];
#endif /* merge_units */
#define UpperBodyNodeTable ((R_7B20*)&UpperBodyNodeTable) /* merge_units */

extern unsigned char D_004F47B0;
extern V4_7B20 D_004F3030[];
extern V4_7B20 D_004F2D90[];
extern unsigned char D_0048A6A0[];
extern unsigned char D_0048A6C0[];
extern void InitializeStaticDataIfNotInitialized(V_7B20* v);
extern T_7B20* cJointInfo_ctor(T_7B20* d, V4_7B20* s, V4_7B20* q);
extern void cJointInfo_opAssign(void* d, T_7B20* s);
extern void cJointInfo_dtor(T_7B20* t, int f);
void cHumanIkRoutine_InitializeStaticDataAndWorkspaceIfNotInitialized(V_7B20* v)
{
    InitializeStaticDataIfNotInitialized(v);
    if (!D_004F47B0) {
        int i;
        R_7B20* r;
        V4_7B20* q;
        V4_7B20* p;
        unsigned char* a;
        unsigned char* b;
        unsigned int n;
        unsigned int j;
        D_004F47B0 = 1;
        for (i = 0, q = D_004F2D90, p = D_004F3030, a = D_0048A6A0, b = D_0048A6C0; i < 21; i++, q++, p++, a++, b++) {
            T_7B20 t;
            r = &UpperBodyNodeTable[i];
            cJointInfo_ctor(&t, p, q);
            cJointInfo_opAssign(r->xf, &t);
            cJointInfo_dtor(&t, -1);
            r->b70 = *a;
            r->bB8 = *b;
        }
        n = v->count;
        for (j = 0; j < n; j++) {
            unsigned char k = *v->data[j].pC0;
            if (k != 0xFF)
                UpperBodyNodeTable[j].pC0 = &UpperBodyNodeTable[k];
            else
                UpperBodyNodeTable[j].pC0 = 0;
        }
    }
}
#undef UpperBodyNodeTable /* merge_units */
static inline void merge_flush_func_001D7B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7B20 */
