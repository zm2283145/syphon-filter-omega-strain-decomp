/*
 * SFOGame/Source/gameGobjController: 2 files, 0022EF40-0022EF70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022EF40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cCheckpoint_Init(void) {
}

void cCheckpoint_Load(void) {
}

int cCheckpoint_HandleMessage(void) {
    return 0;
}
static inline void merge_flush_func_0022EF40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EF40 */

/* merge_units: begin func_0022EF70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void cTimerExpiredMsg_v01();
extern "C" void cTimerExpiredMsg_v03();
extern "C" void cTimerExpiredMsg_v04();
extern "C" void cTimerExpiredMsg_v05();
extern "C" void cNetMsg_Pack();
extern void * const D_004DBA00[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cTimerExpiredMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DBA00);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DBA00[8] = { (void*)0x0, (void*)0x0, (void*)cTimerExpiredMsg_dtor, (void*)cTimerExpiredMsg_v01, (void*)cNetMsg_Pack, (void*)cTimerExpiredMsg_v03, (void*)cTimerExpiredMsg_v04, (void*)cTimerExpiredMsg_v05 };
static inline void merge_flush_func_0022EF70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EF70 */
