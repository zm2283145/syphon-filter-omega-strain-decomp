/*
 * Matched functions (byte-identical with the retail executable).
 * Line-of-sight result event helpers (see research LOS_QUERY_NATIVE.md).
 */

#include "types.h"
#include "loose00_types.h"

extern char D_004D91C0[]; /* LosResultEvent vtable */
extern char g_LosResultMsgClass[]; /* "LOS result ready" event descriptor */
extern int cMessage_ctor_cMessageNameR(void*, void*);
extern int cVector_ctor_cVectorR(Vec4*, Vec4*);
extern int cVector_opAssign(Vec4*, Vec4*);
extern int cCollisionFace_ctor_cCollisionFaceR(LosHitInfo*, LosHitInfo*);
extern int cCollisionModel_FaceLocator_opAssign(Vec4*, Vec4*);
extern int cCollisionModel_FaceProperties_opAssign(Vec4*, Vec4*);

/* Construct a "LOS result ready" event carrying a copy of the result. */
LosResultEvent* cLosResultReadyMessage_ctor(LosResultEvent* ev, LosResult* src) {
    LosResult* dst;

    cMessage_ctor_cMessageNameR(ev, g_LosResultMsgClass);
    dst = &ev->result;
    ev->vtable = D_004D91C0;
    dst->status = src->status;
    cVector_ctor_cVectorR(&dst->point, &src->point);
    cCollisionFace_ctor_cCollisionFaceR(&dst->hit, &src->hit);
    dst->unk90 = src->unk90;
    return ev;
}

void cLosResult_SetHandle(LosResult* self, int value) {
    self->unk90 = value;
}

/* Copy the hit detail block into a result. */
int cLosResult_SetBlockingFace(LosResult* dst, LosHitInfo* src) {
    unsigned char tmp8;
    int tmp11;
    unsigned char tmp13;
    unsigned char tmp14;

    cVector_opAssign(&dst->hit.row0, &src->row0);
    cVector_opAssign(&dst->hit.row1, &src->row1);
    cVector_opAssign(&dst->hit.row2, &src->row2);
    cVector_opAssign(&dst->hit.row3, &src->row3);
    tmp8 = src->unk50;
    dst->hit.unk50 = tmp8;
    cCollisionModel_FaceProperties_opAssign(&dst->hit.unk40, &src->unk40);
    tmp11 = cCollisionModel_FaceLocator_opAssign(&dst->hit.unk60, &src->unk60);
    tmp13 = src->unk51;
    dst->hit.unk51 = tmp13;
    tmp14 = src->unk52;
    dst->hit.unk52 = tmp14;
    return tmp11;
}
