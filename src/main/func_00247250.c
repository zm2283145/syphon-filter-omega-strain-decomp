/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004F7E58;
extern PtrMsg* func_002472E0(void*);
extern int* Message_GetScriptTypeKeyPtr(void);
extern int func_003CB1A0(void*);
extern void ScriptType_SetParent(void*, int);

int Script_cMenuChoiceMsg_Who(ScriptArg* args) {
    return func_003CB1A0(func_002472E0(args[0].p)->who);
}

int Script_cMenuChoiceMsg_Choice(ScriptArg* args) {
    volatile int choice = func_002472E0(args[0].p)->choice; /* stored to the stack and reloaded */
    return choice;
}

void ScriptType_cMenuChoiceMsg_Init(void) {
    ScriptType_SetParent(D_004F7E58, *Message_GetScriptTypeKeyPtr());
}
