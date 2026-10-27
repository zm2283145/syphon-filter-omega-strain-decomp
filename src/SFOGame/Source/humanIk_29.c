/*
 * SFOGame/Source/humanIk: 2 files, 001D7AD0-001D7B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D7AD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

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
extern R_7B20 UpperBodyNodeTable[];
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
static inline void merge_flush_func_001D7B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7B20 */
