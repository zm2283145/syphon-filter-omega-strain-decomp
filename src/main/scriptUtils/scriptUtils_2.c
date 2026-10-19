/*
 * main/scriptUtils: 4 files, 00267EE0-00268030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00267EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vc_copy.h"
struct V4 {
    __int128 q;
    V4() {}
};
class GObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual V4 GetPos();
};
struct Holder {
    char pad[0x30];
    GObj* obj;
};
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" float Global_Distance(GObj* g, GObj* o) {
    V4 a = g->GetPos();
    V4 b = o->GetPos();
    V4 d;
    V4 r;
    float ret;
    {
        V4* pr = &r; V4* pa = &a; V4* pb = &b;
        asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    }
    {
V4* dd; V4* ss; int t; __int128 x; V4* pv;
ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
        asm {
            lqc2 vf1, 0(pv)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni t, vf4
            mtc1 t, ret
        }
    }
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_00267EE0 */

/* merge_units: begin func_00267F90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "scriptUtils_types.h"

extern char* g_Hud;
extern void* GObj_IdentityB(void* obj);
extern int Global_ClearCallout(char* obj);
extern int Global_ClearCallout_2(CalloutOwner* obj);
extern CalloutOwner* NpcScript_GetReceiver(void* obj);
extern int Hud_ClearCallout(char* a0, char* key, int a2, int a3, int a4);

int Script_ClearCallout_2(ScriptArg* args) {
    Global_ClearCallout_2(NpcScript_GetReceiver(args[0].p));
    return 0;
}

int Global_ClearCallout_2(CalloutOwner* obj) {
    return Hud_ClearCallout(g_Hud, obj->callout + 12, 0, 0, 1);
}

int Script_ClearCallout(ScriptArg* args) {
    Global_ClearCallout(GObj_IdentityB(args[0].p));
    return 0;
}

int Global_ClearCallout(char* obj) {
    return Hud_ClearCallout(g_Hud, obj + 12, 0, 0, 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00267F90 */

/* merge_units: begin func_00268030 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_00268030;
#if 0 /* merge_units */
extern void* NpcScript_GetReceiver(void* p);
#endif /* merge_units */
#define NpcScript_GetReceiver(a0) ((void *)NpcScript_GetReceiver((a0))) /* merge_units */

extern void Global_SetCalloutLabel_2(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_4(ScriptArg_00268030* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = NpcScript_GetReceiver(args[0].p);
    Global_SetCalloutLabel_2(obj, *(int*)labelArg, value, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268030(void) {}
#undef NpcScript_GetReceiver /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268030 */

/* merge_units: begin func_00268090 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void Global_SetCalloutLabel_2(void* obj, int label, int text, int flag);
#endif /* merge_units */
#define Global_SetCalloutLabel_2(a0, a1, a2, a3) (Global_SetCalloutLabel_2((a0), (a1), (a2), (a3))) /* merge_units */



/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCalloutLabel_3(ScriptArg* args)
{
    int labelArg[1];
    int textArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = NpcScript_GetReceiver(args[0].p);
    Global_SetCalloutLabel_2(obj, *(int*)labelArg, text, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268090(void) {}
#undef Global_SetCalloutLabel_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268090 */
