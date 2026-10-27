/*
 * main/ai: range (4 files, 0016AB50-0016AC20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ai_types.h"

/* merge_units: begin func_0016AB50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-native bindings. args[0] is the cAI receiver.
 */


extern int cGOBJ_SOBJ_toInt(AIGObj*);

/* Stores the elapsed time (args[1]) on the AI; volatile mirrors the original stack temporary. */
int Script_cAI_SendTimeElapsedMessage(AIScriptArg* args) {
    volatile int bits = args[1].i;
    ((cAI*)args[0].p)->timeElapsed = *(float*)&bits;
    return 0;
}

int Script_GetGOBJ_AI(AIScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((cAI*)args[0].p)->gobj);
}

int Script_cAI_IsVisible(AIScriptArg* args) {
    return ((cAI*)args[0].p)->gobj->unk38 != 0x80;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AB50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016AB50 */

/* merge_units: begin func_0016ABB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cAI_0016ABB0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual int GetTeam(); /* +0x68 */
};

/* Script native: returns the team of args[0]. */
extern "C" int Script_cAI_Team(ScriptArg* args)
{
    cAI_0016ABB0* ai = (cAI_0016ABB0*)args[0].p;
    volatile int team = ai->GetTeam();
    return team;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016ABB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016ABB0 */

/* merge_units: begin func_0016ABE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cAI_0016ABE0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual void SetTeam(int value); /* +0xA0 */
};

/* Script native: cAI::SetTeam(args[1]) on args[0]; returns 0. */
extern "C" int Script_cAI_SetTeam(ScriptArg* args)
{
    int part[1];
    cAI_0016ABE0* obj;
    part[0] = args[1].i;
    obj = (cAI_0016ABE0*)args[0].p;
    obj->SetTeam(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016ABE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016ABE0 */

/* merge_units: begin func_0016AC20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-type registration.
 */


extern char D_004EE5D8[];
extern char D_004EE5E0[];
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(int, int, int);
extern int* func_0022F170(void);
extern int* func_0026ED30(void);
extern int* func_0026ED70(void);
extern int* cAIBodyMovedMsg_SOBJ_getClassId(void);
extern int* cAIPickupableAwarenessMsg_SOBJ_getClassId(void);
extern int* cAIWeaponFiredMsg_SOBJ_getClassId(void);
extern int* cAINewAwarenessMsg_SOBJ_getClassId(void);
extern int* cAIDestinationReachedMsg_SOBJ_getClassId(void);
extern int* cAIWaypointReachedMsg_SOBJ_getClassId(void);
extern int* cAITimeElapsedMsg_SOBJ_getClassId(void);
extern int* cAIDeadMsg_SOBJ_getClassId(void);
extern int* cAIDeactivatedMsg_SOBJ_getClassId(void);
extern int* cAIActivatedMsg_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int, int);
extern void cScriptBase_declareParent(int, int);

/*
 * Registers the cAI script type under its parent, then registers each of the
 * message script types cAI accepts (one key getter per message type).
 */
int cAI_SOBJ_init(void) {
    int* key;

    key = func_0022F170();
    cScriptBase_declareParent(*(int*)D_004EE5E0, *key);
    key = cAIActivatedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDeactivatedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDeadMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAITimeElapsedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIWaypointReachedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDestinationReachedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAINewAwarenessMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIWeaponFiredMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIPickupableAwarenessMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIBodyMovedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = func_0026ED70();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = func_0026ED30();
    return cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
}

/* Address of the cAI script-type key. */
int cAI_SOBJ_getClassId(void) {
    return (int)D_004EE5D8;
}

int cAI_getSOBJClassId(void) {
    return *(int*)D_004EE5D8;
}

int cAI_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent((int)D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016AC20 */
