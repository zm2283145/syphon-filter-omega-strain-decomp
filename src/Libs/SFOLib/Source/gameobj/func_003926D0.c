/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ script type registration and model-context setup.
 */

#include "gobj_types.h"

extern int D_0053B4F0;   /* cVUM_GOBJ script-type value */
extern int D_0053B4F8;   /* cVUM_GOBJ script-type key */
extern char D_0053BB70[];
extern char D_00555070[];
extern int cSkeleton_Reset(int* ctx, ModelCtxParams* params);
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int cSkeletonDataBank_GetSkeletonData(void* table, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int base);

/* Registers the cVUM_GOBJ script type under cGOBJ. */
void cVUM_GOBJ_SOBJ_init(void) {
    int* base;

    base = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_0053B4F8, *base);
}

int cVUM_GOBJ_getSOBJClassId(void) {
    return D_0053B4F0;
}

int cVUM_GOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/*
 * Looks up the skeleton and initializes the embedded model context.
 * a1 is passed through to cSkeletonDataBank_GetSkeletonData unchanged.
 */
void cSKM_GOBJ_ResetSkeleton(cVUM_GOBJ* self, int a1) {
    ModelCtxParams params;
    int skel;

    skel = cSkeletonDataBank_GetSkeletonData(D_0053BB70, a1);
    params.unk04 = self->base.unk50;
    params.unk10 = 1.0f;
    params.unk14 = 0.5f;
    params.skel = skel;
    params.unk18 = 0.2f;
    params.unk1C = 0.2f;
    params.unk20 = 0.2f;
    cSkeleton_Reset(&self->modelCtx, &params);
}
