/*
 * Matched functions (byte-identical with the retail executable).
 * Line-of-sight result event helpers (see research LOS_QUERY_NATIVE.md).
 */

#include "types.h"
#include "loose00_types.h"

extern char D_004D91C0[]; /* LosResultEvent vtable */
extern char D_005435A8[]; /* "LOS result ready" event descriptor */
extern int Event_Construct(void*, void*);
extern int Vec4_Assign(Vec4*, Vec4*);
extern int Vec4_Copy(Vec4*, Vec4*);
extern int func_00139B00(LosHitInfo*, LosHitInfo*);
extern int func_00139BA0(Vec4*, Vec4*);
extern int func_00139BB0(Vec4*, Vec4*);

/* Construct a "LOS result ready" event carrying a copy of the result. */
LosResultEvent* LosResultEvent_Ctor(LosResultEvent* ev, LosResult* src) {
    LosResult* dst;

    Event_Construct(ev, D_005435A8);
    dst = &ev->result;
    ev->vtable = D_004D91C0;
    dst->status = src->status;
    Vec4_Assign(&dst->point, &src->point);
    func_00139B00(&dst->hit, &src->hit);
    dst->unk90 = src->unk90;
    return ev;
}

void func_0013AA20(LosResult* self, int value) {
    self->unk90 = value;
}

/* Copy the hit detail block into a result. */
int func_0013AA30(LosResult* dst, LosHitInfo* src) {
    unsigned char tmp8;
    int tmp11;
    unsigned char tmp13;
    unsigned char tmp14;

    Vec4_Copy(&dst->hit.row0, &src->row0);
    Vec4_Copy(&dst->hit.row1, &src->row1);
    Vec4_Copy(&dst->hit.row2, &src->row2);
    Vec4_Copy(&dst->hit.row3, &src->row3);
    tmp8 = src->unk50;
    dst->hit.unk50 = tmp8;
    func_00139BB0(&dst->hit.unk40, &src->unk40);
    tmp11 = func_00139BA0(&dst->hit.unk60, &src->unk60);
    tmp13 = src->unk51;
    dst->hit.unk51 = tmp13;
    tmp14 = src->unk52;
    dst->hit.unk52 = tmp14;
    return tmp11;
}
