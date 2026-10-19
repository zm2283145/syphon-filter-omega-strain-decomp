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
extern void Hud_SetCalloutLabel(void*, char*, int, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void Global_SetCalloutLabel_2(CalloutOwner* owner, int a1, int value, int a3) {
    Hud_SetCalloutLabel(g_Hud, owner->label + 0xC, a1, 0, 0, a3, 1, (float)value, 0.0f);
}
#pragma pop /* merge_units */
/* merge_units: end func_002680E0 */

/* merge_units: begin func_00268120 */
#pragma push /* merge_units */
void Global_SetCallout_2(CalloutOwner* owner, int a1, int value, int a3); /* gsynth: defined below */typedef union { int i; void* p; } ScriptArg;
extern void* NpcScript_GetReceiver(void* p);
#if 0 /* merge_units */
extern void Global_SetCallout_2(void* obj, int label, int value, int flag);
#endif /* merge_units */
#define Global_SetCallout_2(a0, a1, a2, a3) (Global_SetCallout_2((CalloutOwner *)(a0), (a1), (a2), (a3))) /* merge_units */

int Script_SetCallout_4(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = NpcScript_GetReceiver(args[0].p);
    Global_SetCallout_2(obj, *(int*)labelArg, value, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268120(void) {}
#undef Global_SetCallout_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268120 */

/* merge_units: begin func_00268180 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void Global_SetCallout_2(void* obj, int label, int text, int flag);
#endif /* merge_units */
#define Global_SetCallout_2(a0, a1, a2, a3) (Global_SetCallout_2((CalloutOwner *)(a0), (a1), (a2), (a3))) /* merge_units */



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
    obj = NpcScript_GetReceiver(args[0].p);
    Global_SetCallout_2(obj, *(int*)labelArg, text, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268180(void) {}
#undef Global_SetCallout_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268180 */

/* merge_units: begin func_002681D0 */
#pragma push /* merge_units */
extern void Hud_ShowCallout(void*, char*, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void Global_SetCallout_2(CalloutOwner* owner, int a1, int value, int a3) {
    Hud_ShowCallout(g_Hud, owner->label + 0xC, a1, 0, 0, a3, (float)value, 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002681D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002681D0 */

/* merge_units: begin func_00268210 */
#pragma push /* merge_units */
extern void* GObj_IdentityB(void* p);
extern void Global_SetCalloutLabel(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_2(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCalloutLabel(obj, *(int*)labelArg, value, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268210 */
