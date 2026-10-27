/*
 * SFOGame/Source/player: 1 file, 00175A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00175A90 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x6AC]; char timer[0x30]; float baseTime; } SoundMgr175;
typedef union { int i; float f; } ScriptArg;

extern SoundMgr175* g_Hud;
extern int nGlobalization_GetString_charP(int id);
extern void cHud_cHudTimer_ScheduleExpiration(void* timer, int obj, float time);

/* Script native: starts the player timer with the given time and optional target. */
int Script_cPlayer_SetTimer_2(ScriptArg* args)
{
    float timeArg[1];
    int idArg[1];
    float time;
    int id;
    idArg[0] = args[2].i;
    *(int*)timeArg = args[1].i;
    time = *timeArg;
    id = *(int*)idArg ? nGlobalization_GetString_charP(*(int*)idArg) : 0;
    cHud_cHudTimer_ScheduleExpiration(g_Hud->timer, id, time + g_Hud->baseTime);
    return 0;
}
static inline void merge_flush_func_00175A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175A90 */
