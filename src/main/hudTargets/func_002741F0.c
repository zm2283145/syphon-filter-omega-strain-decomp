/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern unsigned char D_0048B308;
extern MarkerList* std_list_deleter_voidPtr_ctor_void(MarkerList* list);
extern void* std_list_deleter_cSafePtr_cGOBJ_ctor(void* p);

/* Objective marker manager constructor. */
ObjMarkerMgr* cHudTargetManager_ctor(ObjMarkerMgr* self) {
    std_list_deleter_voidPtr_ctor_void(&self->unk00);
    std_list_deleter_voidPtr_ctor_void(&self->records);
    std_list_deleter_cSafePtr_cGOBJ_ctor(self->unk18);
    std_list_deleter_voidPtr_ctor_void(&self->secondary);
    self->unk30 = 1.0f;
    self->unk38 = -2;
    self->unk34 = 0;
    self->selected = 0;
    D_0048B308 = 1;
    return self;
}
