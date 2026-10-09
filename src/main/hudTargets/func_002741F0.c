/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern unsigned char D_0048B308;
extern MarkerList* ScalarCollection_Init(MarkerList* list);
extern void* func_00222B60(void* p);

/* Objective marker manager constructor. */
ObjMarkerMgr* ObjMarkerMgr_ctor(ObjMarkerMgr* self) {
    ScalarCollection_Init(&self->unk00);
    ScalarCollection_Init(&self->records);
    func_00222B60(self->unk18);
    ScalarCollection_Init(&self->secondary);
    self->unk30 = 1.0f;
    self->unk38 = -2;
    self->unk34 = 0;
    self->selected = 0;
    D_0048B308 = 1;
    return self;
}
