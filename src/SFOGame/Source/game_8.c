/*
 * SFOGame/Source/game: 3 files, 0012F910-0012F9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012F910 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_F910 { __int128 q; V_F910() {} };
struct Obj_F910 { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V_F910 GetPos(); };
extern "C" {
void cTremorManager_AddTremor(void* fx, V_F910* pos, float a, float b, float c, float d);
extern void* g_TremorList;
}
/* request a vision flash (tremor) at the object position; duration c/3 */
extern "C" void Global_AddTremor(Obj_F910* o, float a, float b, float c)
{
    void* fx = g_TremorList;
    V_F910 p = o->GetPos();
    cTremorManager_AddTremor(fx, &p, a, b, c / 3.0f, c);
}
static inline void merge_flush_func_0012F910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F910 */

/* merge_units: begin func_0012F9A0 */
#pragma push /* merge_units */
#include "scriptUtils_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char g_Game[]; /* world object */
extern int Global_RequestLevelEnd(void);
extern int cGameSystem_Restart(char* world, int);

int Script_RequestLevelEnd(void) {
    Global_RequestLevelEnd();
    return 0;
}

int Global_RequestLevelEnd(void) {
    return cGameSystem_Restart(g_Game, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F9A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F9A0 */

/* merge_units: begin func_0012F9D0 */
#pragma push /* merge_units */
extern void Global_SetScrollDelay(float delay);

/* Script native: SetScrollDelay(delay = args[0]).
 * volatile mirrors the original stack temporary. */
int Script_SetScrollDelay(ScriptArg* args) {
    volatile int bits = args[0].i;
    Global_SetScrollDelay(*(float*)&bits);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F9D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F9D0 */
