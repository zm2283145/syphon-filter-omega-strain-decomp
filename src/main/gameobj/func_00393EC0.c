/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Quad4* _cdeque_deleter_int_1_ctor(Quad4* q);
extern RelFlag* std_vector_imp_cBone_ctor(RelFlag* r);

Quad4* cdeque_cSkaSystem_RequestPtr_ctor(Quad4* q) {
    _cdeque_deleter_int_1_ctor(q);
    return q;
}

Quad4* _cdeque_deleter_int_1_ctor(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 0.0f;
    q->unkC = 0.0f;
    return q;
}

/* Clears the first two words and sets the two floats to FLT_MAX. */
Quad4* cSkaCrossFadeDuration_ctor_void(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 3.4028234663852886e38f;
    q->unkC = 3.4028234663852886e38f;
    return q;
}

RelFlag* cArray_cBone_ctor(RelFlag* r) {
    std_vector_imp_cBone_ctor(r);
    r->flag = 1;
    return r;
}
