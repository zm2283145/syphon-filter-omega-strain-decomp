/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern GameUI* g_Hud;
extern MarkerTarget* GObj_IdentityB(void*);
extern int Global_SetRadarBlip(MarkerTarget*);
extern int printf(char*, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int HudTargets_Add(void*, int*, int);

int Script_SetRadarBlip(ScriptArg* args) {
    Global_SetRadarBlip(GObj_IdentityB(args[0].p));
    return 0;
}

/* Prints the deprecation message "******* Don't use this function, Use SetRadarBlip( gobj )\n", then sets the blip. */
int Radar_SetBlipDeprecated(MarkerTarget* obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    printf("******* Don't use this function, Use SetRadarBlip( gobj )\n", a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    return Global_SetRadarBlip(obj);
}

int Global_SetRadarBlip(MarkerTarget* obj) {
    return HudTargets_Add(g_Hud->markerMgr, &obj->markerKey, 1);
}
