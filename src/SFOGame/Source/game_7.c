/*
 * main/game: range (5 files, 0012F6E0-0012F8A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "game_types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_0012F6E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script bindings and global level/stat reset helpers.
 */


extern void cAgentData_ResetStats(int);
extern int cGameSystem_GetAgentData(int, int);
extern char g_Game[];                      /* world object */
extern char* g_LocalPlayer;                       /* world +0xBC service */
extern GameTimerService* g_Hud;           /* world +0xDC service */
extern int g_DecalMgr;                         /* world +0xEC service */
extern unsigned char g_IsMultiplayer;               /* multiplayer flag */
extern int Game_IsMultiplayer(void);
extern int Global_ResetLevel(void);
extern void Global_ResetStats(void);
extern int Script_ClearSchedules_3DFB20(void);
extern void std_vector_deleter_PDAQuip_clear(GameTimerService*);
extern int cPlayerControls_KillPickup(int);
extern int cBackpack_RemoveAll(void);
extern int AreaEffect_FinishAll(void);
extern void DecalMgr_KillAll(int);
extern int HudTicker_Reset(int);

int Script_ResetLevel(void) {
    Global_ResetLevel();
    return 0;
}

/* Resets world services, the selected agent's mission data and all script schedules. */
int Global_ResetLevel(void) {
    GameTimerService* svc;
    int agent;

    cPlayerControls_KillPickup((int)(g_LocalPlayer + 0x50));
    cBackpack_RemoveAll();
    AreaEffect_FinishAll();
    agent = cGameSystem_GetAgentData((int)g_Game, -1);
    cAgentData_ResetStats(agent);
    svc = g_Hud;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
    std_vector_deleter_PDAQuip_clear(g_Hud);
    HudTicker_Reset((int)((char*)g_Hud + 0x100));
    DecalMgr_KillAll(g_DecalMgr);
    return Script_ClearSchedules_3DFB20();
}

int Script_ResetStats(void) {
    Global_ResetStats();
    return 0;
}

/* Resets the selected agent's mission data and the timer service fields. */
void Global_ResetStats(void) {
    GameTimerService* svc;
    int agent;

    agent = cGameSystem_GetAgentData((int)g_Game, -1);
    cAgentData_ResetStats(agent);
    svc = g_Hud;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
}

int Script_IsMultiplayer(void) {
    return Game_IsMultiplayer() & 0xFF;
}

int Game_IsMultiplayer(void) {
    return g_IsMultiplayer;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F6E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F6E0 */

/* merge_units: begin func_0012F820 */
#pragma push /* merge_units */
int Global_StartGlobalTimer(int id, float value); /* gsynth: defined below */
#if 0 /* merge_units */
extern int Global_StartGlobalTimer(int timer, float time);
#endif /* merge_units */
#define Global_StartGlobalTimer(a0, a1) (Global_StartGlobalTimer((a0), (a1))) /* merge_units */


/* Script native: StartGlobalTimer(time = args[0], timer = args[1]).
 * volatile mirrors the original stack temporaries. */
int Script_StartGlobalTimer_2(ScriptArg* args) {
    volatile int timerSlot;
    volatile int timeSlot;
    int bits;
    int timer;

    timerSlot = args[1].i;
    bits = args[0].i;
    timer = timerSlot;
    timeSlot = bits;
    Global_StartGlobalTimer(timer, *(float*)&timeSlot);
    return 0;
}
#undef Global_StartGlobalTimer /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F820 */

/* merge_units: begin func_0012F860 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int Global_StartGlobalTimer(int unused, float time);
#endif /* merge_units */
#define Global_StartGlobalTimer(a0, a1) (Global_StartGlobalTimer((a0), (a1))) /* merge_units */


/* Script native: StartGlobalTimer(time = args[0]).
 * volatile mirrors the original stack temporary. */
int Script_StartGlobalTimer(ScriptArg* args) {
    volatile int bits = args[0].i;
    Global_StartGlobalTimer(0, *(float*)&bits);
    return 0;
}
#undef Global_StartGlobalTimer /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F860 */

/* merge_units: begin func_0012F890 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int cHud_StartGlobalTimer(GameTimerService*, int, float);

/* Starts the global timer: forwards to the timer service. */
int Global_StartGlobalTimer(int id, float value) {
    return cHud_StartGlobalTimer(g_Hud, id, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F890 */

/* merge_units: begin func_0012F8A0 */
#pragma push /* merge_units */
extern void* cGOBJ_SOBJ_convert(int handle);
extern void Global_AddTremor(void* obj, float a, float b, float c);
/* Script: AddTremor(obj, a, b, c). */
int Script_AddTremor(int* args)
{
    float c[1]; /* staged through the stack */
    float b[1];
    float a[1];
    float bv, cv;
    *(int*)c = args[3];
    *(int*)b = args[2];
    bv = *b;
    *(int*)a = args[1];
    cv = *c;
    Global_AddTremor(cGOBJ_SOBJ_convert(args[0]), *a, bv, cv);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F8A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F8A0 */
