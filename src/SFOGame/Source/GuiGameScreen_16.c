/*
 * SFOGame/Source/GuiGameScreen: 1 file, 0045EB70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045EB70 */
#pragma push /* merge_units */
#include "types.h"

typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_00586170[];
extern char D_004E16A0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(EventMsg* msg, void* type);
extern void ClearInteract_void(void);
extern void cMessage_dtor(EventMsg* msg, int flags);

/* Constructs a temporary event message around a call to ClearInteract_void. */
void func_0045EB70(void) {
    EventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_00586170);
    msg.vtbl = D_004E16A0;
    ClearInteract_void();
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_0045EB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045EB70 */
