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
