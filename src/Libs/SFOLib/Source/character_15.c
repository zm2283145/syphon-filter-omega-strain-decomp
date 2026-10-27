/*
 * Libs/SFOLib/Source/character: 1 file, 003E6450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E6450 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; signed char c; } ScriptArg;
extern void* cSystem_SOBJ_convert(void* obj);
extern void* cGOBJ_SOBJ_convert(void* obj);
extern void nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(void* actor, int action, void* target, int extra, float value, int flag);

/* Script native: makes args[0] perform action args[1] on object args[2] with args[3]/args[4]. */
int Script_PerformAction_WithObject_3(ScriptArg* args)
{
    int p4[1];
    int p3[1];
    void* actor;
    int action;
    float value;
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    action = args[1].c;
    value = *(float*)p4;
    actor = cSystem_SOBJ_convert(args[0].p);
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(actor, action, cGOBJ_SOBJ_convert(args[2].p), *(int*)p3, value, 0);
    return 0;
}
static inline void merge_flush_character_3E6450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E6450 */
