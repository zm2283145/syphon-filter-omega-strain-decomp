/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001D8730(void);
extern int func_001D8900(void);

/* Rec24 constructor (+0x08 is left untouched). */
Rec24* func_001D86D0(Rec24* r) {
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

int func_001D8710(void) {
    return func_001D8730();
}

int func_001D8720(void) {
    return func_001D8900();
}
