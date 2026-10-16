/*
 * main/particle: range (2 files, 003A38F0-003A3910)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003A38F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */


Word* func_003A38F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003A3900(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A38F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A38F0 */

/* merge_units: begin func_003A3910 */
#pragma push /* merge_units */
typedef struct Obj3A39 {
    char pad00[0x10];
    int target;            /* 0x10 */
    int unk14;             /* 0x14 */
    char pad18[4];
    unsigned char unk1C;   /* 0x1C */
} Obj3A39;

extern int D_0053B560;
extern int D_0053B564;
extern int D_0053B570;
extern int D_0053B574;
extern int D_0053B580;
extern int D_0053B584;
extern int D_0053B590;
extern int D_0053B594;
extern unsigned long long D_0053B680;
extern unsigned long long D_0053B688;
extern unsigned long long D_0053B690;
extern unsigned long long D_0053B698;

/* Resets the object and the four global register slots (GS register tags 0x44/0x68/0x48/0x46). */
void ParticleSystem_Construct(Obj3A39* obj, int target) {
    obj->target = target;
    obj->unk14 = 0;
    obj->unk1C = 0;
    D_0053B564 = 0;
    D_0053B560 = 0;
    D_0053B680 = 0x44 | ((unsigned long long)0x80 << 32);
    D_0053B574 = 0;
    D_0053B688 = 0x68 | ((unsigned long long)0x80 << 32);
    D_0053B570 = 0;
    D_0053B690 = 0x48 | ((unsigned long long)0x80 << 32);
    D_0053B584 = 0;
    D_0053B698 = 0x46 | ((unsigned long long)0x80 << 32);
    D_0053B580 = 0;
    D_0053B594 = 0;
    D_0053B590 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3910 */
