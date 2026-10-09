/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ script type registration and model-context setup.
 */

#include "gobj_types.h"

extern int D_0053B4F0;   /* cVUM_GOBJ script-type value */
extern int D_0053B4F8;   /* cVUM_GOBJ script-type key */
extern char D_0053BB70[];
extern char D_00555070[];
extern int ModelCtx_Init(int* ctx, ModelCtxParams* params);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int Skel_Find(void* table, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cVUM_GOBJ script type under cGOBJ. */
void ScriptType_cVUM_GOBJ_Init(void) {
    int* base;

    base = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_0053B4F8, *base);
}

int cVUM_GOBJ_v0B(void) {
    return D_0053B4F0;
}

int cVUM_GOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/*
 * Looks up the skeleton and initializes the embedded model context.
 * a1 is passed through to Skel_Find unchanged.
 */
void cVUM_GOBJ_InitModel(cVUM_GOBJ* self, int a1) {
    ModelCtxParams params;
    int skel;

    skel = Skel_Find(D_0053BB70, a1);
    params.unk04 = self->base.unk50;
    params.unk10 = 1.0f;
    params.unk14 = 0.5f;
    params.skel = skel;
    params.unk18 = 0.2f;
    params.unk1C = 0.2f;
    params.unk20 = 0.2f;
    ModelCtx_Init(&self->modelCtx, &params);
}
