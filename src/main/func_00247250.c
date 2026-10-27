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
