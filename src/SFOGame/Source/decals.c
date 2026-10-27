/*
 * SFOGame/Source/decals: 2 files, 002783A0-00278430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002783A0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Sub78 {
    char pad[0xC];
    unsigned char unkC;
    char pad2[3];
} Sub78;

typedef struct Obj116 {
    char pad[0x60];
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Sub78 sub;
    char pad2[0xD0 - 0x88];
    unsigned char unkD0;
    char pad3;
    unsigned char unkD2;
    char pad4[0xF0 - 0xD3];
    int unkF0;
    int unkF4;
    char pad5[0x115 - 0xF8];
    unsigned char unk115;
} Obj116;

#if 0 /* merge_units */
extern void func_00278440(Sub78*);
#endif /* merge_units */
Rel * func_00278440(); /* merge_units */

extern int cArrayCapacity_Int(int*);
#if 0 /* merge_units */
extern void PtrVec_Reserve_Thunk_278430(Sub78*, int);
#endif /* merge_units */
int PtrVec_Reserve_Thunk_278430(); /* merge_units */


/* Constructor body: resets three (0, -2) pairs, sets up the sub-object and clears flags. */
Obj116* cBullet_ctor(Obj116* o) {
    int kind;
    Sub78* sub;
    o->unk64 = -2;
    sub = &o->sub;
    o->unk60 = 0;
    o->unk6C = -2;
    o->unk68 = 0;
    o->unk74 = -2;
    o->unk70 = 0;
    kind = 5;
    func_00278440(sub);
    PtrVec_Reserve_Thunk_278430(sub, cArrayCapacity_Int(&kind));
    sub->unkC = 0;
    o->unkD0 = 0;
    o->unkD2 = 0;
    o->unkF0 = 0;
    o->unkF4 = 0;
    o->unk115 = 0;
    return o;
}
static inline void merge_flush_func_002783A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002783A0 */

/* merge_units: begin func_00278430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_reserve(int, int);

int PtrVec_Reserve_Thunk_278430(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* func_00278440(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00278430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278430 */
