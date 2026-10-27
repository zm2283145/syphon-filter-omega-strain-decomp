/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int D_004EE700;   /* cHotboxMsg type id */
extern int D_004EE738;   /* cHotbox class type id */
extern int D_004EE740;   /* cHotbox script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int messageType);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cHotbox script type under its parent and adds cHotboxMsg to it. */
int cHotbox_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE740, *parent);
    return cScriptBase_declareMsgUse(D_004EE740, D_004EE700);
}

void* cHotbox_SOBJ_convert(void* self) {
    return self;
}

int* cHotbox_SOBJ_getClassId(void) {
    return &D_004EE738;
}

int cHotbox_getSOBJClassId(void) {
    return D_004EE738;
}

int cHotbox_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
