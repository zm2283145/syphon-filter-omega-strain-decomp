/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int D_004EE700;   /* cHotboxMsg type id */
extern int D_004EE708;   /* cHotboxMsg script type */
extern int GObj_IdentityA(void*);
extern void* GObj_IdentityB(int);
extern int Global_MakeGOBJInteractable(void* gobj);
extern int Global_MakeNPCInteractable(void* npc);
extern void* func_0014A690(int handle);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

int Script_cHotboxMsg_Who(HotboxScriptArg* args) {
    return GObj_IdentityA(((cHotboxMsg*)args[0].p)->who);
}

int Script_cHotboxMsg_Action(HotboxScriptArg* args) {
    return ((cHotboxMsg*)args[0].p)->action;
}

/* Registers the cHotboxMsg script type under its parent type. */
void ScriptType_cHotboxMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_004EE708, *parent);
}

int cHotboxMsg_v03(void) {
    return D_004EE700;
}

/* volatile mirrors the original stack temporary. */
int Script_MakeNPCInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeNPCInteractable(func_0014A690(args[0].i));
    return hotbox;
}

int Script_MakeGOBJInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeGOBJInteractable(GObj_IdentityB(args[0].i));
    return hotbox;
}
