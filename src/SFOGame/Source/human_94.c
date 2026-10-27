/*
 * SFOGame/Source/human: 6 files, 001AE2A0-001AE3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AE2A0 */
#pragma push /* merge_units */
#include "types.h"

void BitArray_Assign(unsigned int* bits, int idx, int set)
{
    if (set) {
        bits[idx / 32] |= 1 << (idx & 31);
    } else {
        bits[idx / 32] &= ~(1 << (idx & 31));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE2A0 */

/* merge_units: begin func_001AE320 */
#pragma push /* merge_units */
void LosProvider_SeedRegion(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 80) = a1;
    if (cond) goto L001AE338;
    v1 = a1 + 12;
    goto L001AE348;
L001AE338:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001AE348:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 84) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE320 */

/* merge_units: begin func_001AE360 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

extern int D_004EA0B8;

int func_001AE360(void) {
    return D_004EA0B8;
}

/* Set the float at +0x3C to 1.0 and clear the word at +0x4C. */
void cLosRequestMessage_MakeSureWValuesAreCorrect(char* self) {
    *(float*)(self + 60) = 1.0f;
    *(int*)(self + 76) = 0;
}
static inline void merge_flush_func_001AE360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE360 */

/* merge_units: begin func_001AE380 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Subtract(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline void merge_flush_func_001AE380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE380 */

/* merge_units: begin func_001AE3A0 */
#pragma push /* merge_units */
void* cHuman_GetFloorAnchor_void_2(Actor* actor) {
    return actor->floorRoot;
}
static inline void merge_flush_func_001AE3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE3A0 */

/* merge_units: begin func_001AE3B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_AE3B0;
struct S_AE3B0 { char pad0[0xC]; bool bC; char padD[0x187 - 0xD]; bool f187; char pad188[8]; V4_AE3B0 v190; float f1A0; float f1A4; };
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void V4Copy(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cHumanMotionParams_RequestMotion_cVectorR_float_float(S_AE3B0* s, V4_AE3B0* v, float a, float b)
{
    V4Copy(&s->v190, v);
    s->f1A0 = a;
    s->f1A4 = b;
    s->f187 = s->bC && a == 0.0f && Abs(b) > 0.0001f;
}
static inline void merge_flush_func_001AE3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE3B0 */
