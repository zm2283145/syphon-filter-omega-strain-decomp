/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ script type registration, identity conversions and accessors.
 */

#include "gobj_types.h"

extern int D_005436B8;   /* cGOBJ script-type key */
extern int D_005436C0;   /* cGOBJ script-type value */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* func_003CB1D0(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);
extern int* func_004080E0(void);

/* Registers the cGOBJ script type: parent type, then one accepted interface. */
int ScriptType_cGOBJ_Init(void) {
    int* key;

    key = func_003CB1D0();
    ScriptType_SetParent(D_005436C0, *key);
    key = func_004080E0();
    return ScriptType_AddAccepted(D_005436C0, *key);
}

/* Identity conversion of a GOBJ script value; the volatile mirrors the stack temporary. */
int GObj_IdentityA(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* GObj_IdentityB(void* self) {
    return self;
}

/* Address of the cGOBJ script-type key. */
int* cGOBJ_GetScriptTypeKeyPtr(void) {
    return &D_005436B8;
}

int cGOBJ_v0B(void) {
    return D_005436B8;
}

int cGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
