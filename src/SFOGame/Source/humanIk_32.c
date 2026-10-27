/*
 * SFOGame/Source/humanIk: 2 files, 001D8610-001D86D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D8610 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Q_1D8610;
typedef struct {
    signed char b0, b1, b2, b3;
    unsigned char b4, b5;
    char pad6[0xA];
    Q_1D8610 v10;
    Q_1D8610 q20;
    Q_1D8610 q30;
    Q_1D8610 q40;
    Q_1D8610 q50;
    int w60;
    char pad64[0xC];
} E_1D8610;
extern void* cVector_GetZero(void);
extern void cVector_ctor_cVectorR(void* d, void* s);
extern void cQuaternion_GetIdentity(Q_1D8610* q);
extern void cQuaternion_ctor_cQuaternionR(Q_1D8610* d, Q_1D8610* s);
E_1D8610* cArray_FixedSize_cAimComponent_2_ctor(E_1D8610* arr)
{
    E_1D8610* e = arr;
    do {
        Q_1D8610 qa;
        Q_1D8610 qb;
        Q_1D8610 qc;
        Q_1D8610 qd;
        e->b0 = -1;
        e->b1 = -1;
        e->b2 = -1;
        e->b3 = -1;
        e->b4 = 0;
        e->b5 = 0;
        cVector_ctor_cVectorR(&e->v10, cVector_GetZero());
        cQuaternion_GetIdentity(&qa);
        cQuaternion_ctor_cQuaternionR(&e->q20, &qa);
        cQuaternion_GetIdentity(&qb);
        cQuaternion_ctor_cQuaternionR(&e->q30, &qb);
        cQuaternion_GetIdentity(&qc);
        cQuaternion_ctor_cQuaternionR(&e->q40, &qc);
        cQuaternion_GetIdentity(&qd);
        cQuaternion_ctor_cQuaternionR(&e->q50, &qd);
        e->w60 = 0;
        e++;
    } while (e != arr + 2);
    return arr;
}
static inline void merge_flush_func_001D8610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D8610 */

/* merge_units: begin humanIk_1D86D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern int cDrawAndHolsterWeapon_ActionManager_UnInitStatics(void);
extern int cDrawAndHolsterWeapon_ActionManager_InitStatics(void);

/* Rec24 constructor (+0x08 is left untouched). */
Rec24* cSkaAnimDataIterator_ctor_void(Rec24* r) {
    r->unk00 = 0;
    r->unk04 = 0;
    r->unk0C = 0.0f;
    r->unk10 = 0;
    r->unk14 = 0.0f;
    r->unk18 = 0;
    r->unk1C = 0;
    r->unk20 = 0;
    return r;
}

IntPair* func_001D8700(IntPair* p) {
    p->a = 0;
    p->b = 0;
    return p;
}

int cHumanIkRoutine_UnInitStatics(void) {
    return cDrawAndHolsterWeapon_ActionManager_UnInitStatics();
}

int cHumanIkRoutine_InitStatics(void) {
    return cDrawAndHolsterWeapon_ActionManager_InitStatics();
}
static inline void merge_flush_humanIk_1D86D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end humanIk_1D86D0 */
