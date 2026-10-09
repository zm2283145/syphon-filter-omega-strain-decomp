/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern GameUI* D_004FFC2C;
extern MarkerTarget* GObj_IdentityB(void*);
extern int Global_ClearRadarBlip(MarkerTarget*);
extern void Global_SetWaypoint(MarkerTarget*);
extern int ObjMarkerMgr_Remove(void*, int*, int);
extern void func_00272D10(void*, MarkerTarget*);

int Script_SetWaypoint(ScriptArg* args) {
    Global_SetWaypoint(GObj_IdentityB(args[0].p));
    return 0;
}

void Global_SetWaypoint(MarkerTarget* obj) {
    func_00272D10(D_004FFC2C->markerMgr, obj);
}

int Script_ClearRadarBlip(ScriptArg* args) {
    Global_ClearRadarBlip(GObj_IdentityB(args[0].p));
    return 0;
}

int Global_ClearRadarBlip(MarkerTarget* obj) {
    return ObjMarkerMgr_Remove(D_004FFC2C->markerMgr, &obj->markerKey, 0);
}
