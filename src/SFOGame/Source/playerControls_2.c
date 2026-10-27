/*
 * SFOGame/Source/playerControls: 2 files, 00247140-00247250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00247140 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DC330[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cMenuChoiceMsg_Clone, 0x2C, "playerControls.hh", 0x23)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DC330;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
MSG_CLONE_END
static inline void merge_flush_func_00247140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00247140 */

/* merge_units: begin func_00247250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004F7E58;
extern PtrMsg* cMenuChoiceMsg_SOBJ_convert(void*);
extern int* cMessage_SOBJ_getClassId(void);
extern int cSystem_SOBJ_toInt(void*);
extern void cScriptBase_declareParent(void*, int);

int Script_cMenuChoiceMsg_Who(ScriptArg* args) {
    return cSystem_SOBJ_toInt(cMenuChoiceMsg_SOBJ_convert(args[0].p)->who);
}

int Script_cMenuChoiceMsg_Choice(ScriptArg* args) {
    volatile int choice = cMenuChoiceMsg_SOBJ_convert(args[0].p)->choice; /* stored to the stack and reloaded */
    return choice;
}

void cMenuChoiceMsg_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F7E58, *cMessage_SOBJ_getClassId());
}
static inline void merge_flush_func_00247250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00247250 */
