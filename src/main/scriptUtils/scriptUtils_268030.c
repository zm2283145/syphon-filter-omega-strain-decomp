/*
 * main/scriptUtils: range (2 files, 00268030-00268090)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00268030 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg;
extern void* NpcScript_GetReceiver(void* p);
extern void Global_SetCalloutLabel_2(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_4(ScriptArg* args)
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
#undef Global_SetCalloutLabel_2 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268090(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268090 */
