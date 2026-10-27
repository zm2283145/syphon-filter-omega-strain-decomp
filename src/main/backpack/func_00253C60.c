/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack script natives and script type registration.
 */

#include "types.h"
#include "backpack_types.h"

extern int D_004F7EB8;
extern int D_004F7EF8;
extern int D_004F7F78;
extern int D_004F7F80;
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int cBackpack_StealPlayerWeapons(cBackpack* backpack, int a1, int a2, int a3);
extern int Backpack_RemoveAll_Thunk(void);
extern int cBackpack_RemoveAll(void);
extern int* cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int msgType);
extern void cScriptBase_declareParent(int type, int baseType);

int Script_RemoveAllBackpacks(void) {
    Backpack_RemoveAll_Thunk();
    return 0;
}

int Backpack_RemoveAll_Thunk(void) {
    return cBackpack_RemoveAll();
}

/* Overloads with 3, 2 and 1 explicit arguments; missing ones default to 8. */
int Script_cBackpack_StealPlayerWeapons_3(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, args[2].u8, args[3].u8);
    return 0;
}

int Script_cBackpack_StealPlayerWeapons_2(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, args[2].u8, 8);
    return 0;
}

int Script_cBackpack_StealPlayerWeapons(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, 8, 8);
    return 0;
}

int Script_cBackpack_SetAutoPickup(BackpackScriptArg* args) {
    ((cBackpack*)args[0].p)->autoPickup = (unsigned int)args[1].i != 0;
    return 0;
}

/* Registers cBackpack under its base type and the two message types it handles. */
int cBackpack_SOBJ_init(void) {
    int* base = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7F80, *base);
    cScriptBase_declareMsgUse(D_004F7F80, D_004F7EB8);
    return cScriptBase_declareMsgUse(D_004F7F80, D_004F7EF8);
}

int cBackpack_getSOBJClassId(void) {
    return D_004F7F78;
}

int cBackpack_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
