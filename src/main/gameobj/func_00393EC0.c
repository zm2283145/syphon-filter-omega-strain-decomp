/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Quad4* func_00393EF0(Quad4* q);
extern RelFlag* func_00393F60(RelFlag* r);

Quad4* func_00393EC0(Quad4* q) {
    func_00393EF0(q);
    return q;
}

Quad4* func_00393EF0(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 0.0f;
    q->unkC = 0.0f;
    return q;
}

/* Clears the first two words and sets the two floats to FLT_MAX. */
Quad4* func_00393F10(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 3.4028234663852886e38f;
    q->unkC = 3.4028234663852886e38f;
    return q;
}

RelFlag* func_00393F30(RelFlag* r) {
    func_00393F60(r);
    r->flag = 1;
    return r;
}
