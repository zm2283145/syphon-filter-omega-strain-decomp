/*
 * main/scriptUtils: range (4 files, 00268270-00268360)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00268270 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; char label[1]; } Callout002682C0;
void Global_SetCalloutLabel(Callout002682C0* callout, int a, int x, int d); /* gsynth: defined below */
typedef union { int i; void* p; } ScriptArg;

extern void* GObj_IdentityB(void* p);
#if 0 /* merge_units */
extern void Global_SetCalloutLabel(void* obj, int label, int text, int flag);
#endif /* merge_units */
#define Global_SetCalloutLabel(a0, a1, a2, a3) (Global_SetCalloutLabel((void *)(a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCalloutLabel(ScriptArg* args)
{
    int textArg[1];
    int labelArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCalloutLabel(obj, *(int*)labelArg, text, 0);
    return 0;
}
#undef Global_SetCalloutLabel /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268270 */

/* merge_units: begin func_002682C0 */
#pragma push /* merge_units */
extern void* g_Hud;
extern void Hud_SetCalloutLabel(void* hud, char* label, int a, int b, int c, int d, int e, float x, float y);
/* Set a callout label on the HUD. */
void Global_SetCalloutLabel(Callout002682C0* callout, int a, int x, int d)
{
    Hud_SetCalloutLabel(g_Hud, callout->label, a, 0, 0, d, 1, (float)x, 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002682C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002682C0 */

/* merge_units: begin func_00268300 */
#pragma push /* merge_units */
extern void Global_SetCallout(void* obj, int label, int text, unsigned char flag);

/* Script native: sets a callout (label, text, flag) on the resolved object. */
int Script_SetCallout_2(ScriptArg* args)
{
    int textArg[1];
    int labelArg[1];
    int text;
    unsigned char on;
    void* obj;
    on = args[3].i != 0;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCallout(obj, *(int*)labelArg, text, on);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268300 */

/* merge_units: begin func_00268360 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void Global_SetCallout(void* obj, int label, int text, int flag);
#endif /* merge_units */
#define Global_SetCallout(a0, a1, a2, a3) (Global_SetCallout((a0), (a1), (a2), (unsigned char)(a3))) /* merge_units */


/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCallout(ScriptArg* args)
{
    int textArg[1];
    int labelArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCallout(obj, *(int*)labelArg, text, 0);
    return 0;
}
#undef Global_SetCallout /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268360 */
