/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char D_00504040;
extern int D_00504058;
extern void ScalarCollection_Init(ScalarCollection*);
extern int* func_00241B70(int, int);
extern int func_003EEBE0(int, int, int);

/* Constructor: init embedded collection, acquire a handle and clear all fields. */
Unk27B900* func_0027B900(Unk27B900* self, int a1, int a2) {
    ScalarCollection_Init(&self->list);
    self->unk50 = 3658;
    self->handle = func_00241B70(a2, a1);
    func_003EEBE0(*self->handle, 0, 1);
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk04 = 0;
    self->unk0C = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk14 = 0;
    self->unk28 = 0;
    self->unk54 = 0;
    self->unk55 = 0;
    self->unk56 = 0;
    D_00504040 = 0;
    return self;
}

int cNetTaserMsg_v05(void) {
    return D_00504058;
}
