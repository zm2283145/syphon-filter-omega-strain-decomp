/*
 * SFOGame/Source/targetManager: 2 files, 0022C0A0-0022C140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022C0A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern GameUI* g_Hud;
extern MarkerTarget* cGOBJ_SOBJ_convert(void*);
extern int Global_ClearRadarBlip(MarkerTarget*);
extern void Global_SetWaypoint(MarkerTarget*);
extern int cHudTargetManager_Remove(void*, int*, int);
extern void cHudTargetManager_SetWaypoint(void*, MarkerTarget*);

int Script_SetWaypoint(ScriptArg* args) {
    Global_SetWaypoint(cGOBJ_SOBJ_convert(args[0].p));
    return 0;
}

void Global_SetWaypoint(MarkerTarget* obj) {
    cHudTargetManager_SetWaypoint(g_Hud->markerMgr, obj);
}

int Script_ClearRadarBlip(ScriptArg* args) {
    Global_ClearRadarBlip(cGOBJ_SOBJ_convert(args[0].p));
    return 0;
}

int Global_ClearRadarBlip(MarkerTarget* obj) {
    return cHudTargetManager_Remove(g_Hud->markerMgr, &obj->markerKey, 0);
}
static inline void merge_flush_func_0022C0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C0A0 */

/* merge_units: begin func_0022C140 */
#pragma push /* merge_units */
typedef union { int i; float f; void* p; } ScriptArg_0022C140;

#if 0 /* merge_units */
extern void* cGOBJ_SOBJ_convert(void* p);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((void *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

extern void SetRadarBlip_cGOBJP_float(void* obj, float value);

/* Script native: sets a radar blip value on the resolved object. */
int Script_SetRadarBlip_2(ScriptArg_0022C140* args)
{
    ScriptArg_0022C140 value[1];
    value[0].i = args[1].i;
    SetRadarBlip_cGOBJP_float(cGOBJ_SOBJ_convert(args[0].p), value[0].f);
    return 0;
}
#undef cGOBJ_SOBJ_convert /* merge_units */
static inline void merge_flush_func_0022C140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C140 */
