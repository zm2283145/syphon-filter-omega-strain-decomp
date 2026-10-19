/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern GameUI* g_Hud;
extern MarkerTarget* GObj_IdentityB(void*);
extern int Global_ClearRadarBlip(MarkerTarget*);
extern void Global_SetWaypoint(MarkerTarget*);
extern int ObjMarkerMgr_Remove(void*, int*, int);
extern void HudTargets_SelectWaypoint(void*, MarkerTarget*);

int Script_SetWaypoint(ScriptArg* args) {
    Global_SetWaypoint(GObj_IdentityB(args[0].p));
    return 0;
}

void Global_SetWaypoint(MarkerTarget* obj) {
    HudTargets_SelectWaypoint(g_Hud->markerMgr, obj);
}

int Script_ClearRadarBlip(ScriptArg* args) {
    Global_ClearRadarBlip(GObj_IdentityB(args[0].p));
    return 0;
}

int Global_ClearRadarBlip(MarkerTarget* obj) {
    return ObjMarkerMgr_Remove(g_Hud->markerMgr, &obj->markerKey, 0);
}
