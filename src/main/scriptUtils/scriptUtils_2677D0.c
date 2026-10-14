/*
 * main/scriptUtils: range (2 files, 002677D0-00267810)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_002677D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void* GObj_IdentityB(void* obj);
extern int Global_SetPersonalTimer(void* obj, int a1, float time);

/* Script native: SetPersonalTimer(obj = args[0], time = args[1]).
 * volatile mirrors the original stack temporary. */
int Script_SetPersonalTimer_2(ScriptArg* args) {
    volatile int bits = args[1].i;
    Global_SetPersonalTimer(GObj_IdentityB(args[0].p), 0, *(float*)&bits);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002677D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002677D0 */

/* merge_units: begin func_00267810 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* GObj_IdentityB(void*);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Global_SetPersonalTimer(void*, int, float);
#endif /* merge_units */
#define Global_SetPersonalTimer(a0, a1, a2) (Global_SetPersonalTimer((a0), (a1), (a2))) /* merge_units */


/* Script: SetPersonalTimer(owner, time, id); arguments are staged through the stack. */
int Script_SetPersonalTimer(ScriptArg* args) {
    int id[1];
    int time[1];
    int idValue;
    void* owner;
    id[0] = args[2].i;
    time[0] = args[1].i;
    idValue = *(int*)id;
    owner = GObj_IdentityB(args[0].p);
    Global_SetPersonalTimer(owner, idValue, *(float*)time);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
#undef Global_SetPersonalTimer /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267810 */
