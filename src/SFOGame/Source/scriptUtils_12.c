/*
 * main/scriptUtils: 5 files, 002680E0-00268120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002680E0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct CalloutOwner {
    char pad[0x30];
    char* label;
} CalloutOwner;

extern void* g_Hud;
extern void cHud_SetCalloutLabel(void*, char*, int, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void nScriptUtils_SetCalloutLabel_cNPCP_charP_int_bool(CalloutOwner* owner, int a1, int value, int a3) {
    cHud_SetCalloutLabel(g_Hud, owner->label + 0xC, a1, 0, 0, a3, 1, (float)value, 0.0f);
}
#pragma pop /* merge_units */
/* merge_units: end func_002680E0 */

/* merge_units: begin func_00268120 */
#pragma push /* merge_units */
void nScriptUtils_SetCallout_cNPCP_charP_int_bool(CalloutOwner* owner, int a1, int value, int a3); /* gsynth: defined below */typedef union { int i; void* p; } ScriptArg;
extern void* cNPC_SOBJ_convert(void* p);
#if 0 /* merge_units */
extern void nScriptUtils_SetCallout_cNPCP_charP_int_bool(void* obj, int label, int value, int flag);
#endif /* merge_units */
#define nScriptUtils_SetCallout_cNPCP_charP_int_bool(a0, a1, a2, a3) (nScriptUtils_SetCallout_cNPCP_charP_int_bool((CalloutOwner *)(a0), (a1), (a2), (a3))) /* merge_units */

int Script_SetCallout_4(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = cNPC_SOBJ_convert(args[0].p);
    nScriptUtils_SetCallout_cNPCP_charP_int_bool(obj, *(int*)labelArg, value, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268120(void) {}
#undef nScriptUtils_SetCallout_cNPCP_charP_int_bool /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268120 */

/* merge_units: begin func_00268180 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void nScriptUtils_SetCallout_cNPCP_charP_int_bool(void* obj, int label, int text, int flag);
#endif /* merge_units */
#define nScriptUtils_SetCallout_cNPCP_charP_int_bool(a0, a1, a2, a3) (nScriptUtils_SetCallout_cNPCP_charP_int_bool((CalloutOwner *)(a0), (a1), (a2), (a3))) /* merge_units */



/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCallout_3(ScriptArg* args)
{
    int labelArg[1];
    int textArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = cNPC_SOBJ_convert(args[0].p);
    nScriptUtils_SetCallout_cNPCP_charP_int_bool(obj, *(int*)labelArg, text, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268180(void) {}
#undef nScriptUtils_SetCallout_cNPCP_charP_int_bool /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268180 */

/* merge_units: begin func_002681D0 */
#pragma push /* merge_units */
extern void cHud_SetCallout(void*, char*, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void nScriptUtils_SetCallout_cNPCP_charP_int_bool(CalloutOwner* owner, int a1, int value, int a3) {
    cHud_SetCallout(g_Hud, owner->label + 0xC, a1, 0, 0, a3, (float)value, 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002681D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002681D0 */

/* merge_units: begin func_00268210 */
#pragma push /* merge_units */
extern void* cGOBJ_SOBJ_convert(void* p);
extern void nScriptUtils_SetCalloutLabel_cGOBJP_charP_int_bool(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_2(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = cGOBJ_SOBJ_convert(args[0].p);
    nScriptUtils_SetCalloutLabel_cGOBJP_charP_int_bool(obj, *(int*)labelArg, value, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268210 */
