/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration and accessor for cWeaponVisChangeMsg.
 * Address lies after guiMLTextWidget.cc (ends 0x0043E330).
 */

#include "loose05_types.h"

extern int D_00583970; /* cWeaponVisChangeMsg key */
extern int D_00583978; /* cWeaponVisChangeMsg type id */
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parent);

/* Script native: returns the message's visibility word. */
int Script_cWeaponVisChangeMsg_Visibility(ScriptMsg24** args) {
    volatile int value = args[0]->value; /* stored to the stack and reloaded */

    return value;
}

/* cWeaponVisChangeMsg derives from the message base type. */
void ScriptType_cWeaponVisChangeMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_00583978, *parent);
}

int* cWeaponVisChangeMsg_GetScriptTypeKeyPtr(void) {
    return &D_00583970;
}

int cWeaponVisChangeMsg_v03(void) {
    return D_00583970;
}
