/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int D_004EE700;   /* cHotboxMsg type id */
extern int D_004EE708;   /* cHotboxMsg script type */
extern int cGOBJ_SOBJ_toInt(void*);
extern void* cGOBJ_SOBJ_convert(int);
extern int Global_MakeGOBJInteractable(void* gobj);
extern int Global_MakeNPCInteractable(void* npc);
extern void* cNPC_SOBJ_convert(int handle);
extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

int Script_cHotboxMsg_Who(HotboxScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((cHotboxMsg*)args[0].p)->who);
}

int Script_cHotboxMsg_Action(HotboxScriptArg* args) {
    return ((cHotboxMsg*)args[0].p)->action;
}

/* Registers the cHotboxMsg script type under its parent type. */
void cHotboxMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE708, *parent);
}

int cHotboxMsg_getSOBJClassId(void) {
    return D_004EE700;
}

/* volatile mirrors the original stack temporary. */
int Script_MakeNPCInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeNPCInteractable(cNPC_SOBJ_convert(args[0].i));
    return hotbox;
}

int Script_MakeGOBJInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeGOBJInteractable(cGOBJ_SOBJ_convert(args[0].i));
    return hotbox;
}
