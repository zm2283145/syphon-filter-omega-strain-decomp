/*
 * main/playerControls: range (6 files, 0024FC30-0024FD50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_0024FC30 */
#pragma push /* merge_units */
typedef struct { int a; int b; char c; char pad[7]; __int128 q; float f; } XFC30;
#pragma opt_propagation off
XFC30* cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(XFC30* d, int* pa, int b, char c, __int128* q, float f) {
    d->a = *pa;
    d->b = b;
    d->c = c;
    { typedef char uf_chk_[sizeof(d->q) == 16 ? 1 : -1]; VCopyF(&(d->q), &(*q)); }
    d->f = f;
    return d;
}
#pragma opt_propagation reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC30 */

/* merge_units: begin func_0024FC60 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0PostMultiply(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC60 */

/* merge_units: begin func_0024FC90 */
#pragma push /* merge_units */
void cSafePtr_cGOBJ_Set(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L0024FCA8;
    v1 = a1 + 12;
    goto L0024FCB8;
L0024FCA8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L0024FCB8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC90 */

/* merge_units: begin func_0024FCD0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern char SecondaryStateTable;

int cHumanIkRoutine_IsWeaponAimed(char * arg0) {
    int var_v0;

    var_v0 = F_((&SecondaryStateTable + (F_(arg0, 0x310, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    if (var_v0 != 0) {
        var_v0 = F_((&SecondaryStateTable + (F_(arg0, 0x311, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    }
    return var_v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FCD0 */

/* merge_units: begin func_0024FD20 */
#pragma push /* merge_units */
void cVector_VU0PostRotate(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FD20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FD20 */

/* merge_units: begin func_0024FD50 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; int bits[1]; } F24FD50;
int func_0024FD50(F24FD50* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FD50 */
