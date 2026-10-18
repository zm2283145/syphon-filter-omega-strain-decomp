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


extern void AgentData_ResetMission(int);
extern int Agent_GetSelected(int, int);
extern char D_004FFB50[];                      /* world object */
extern char* D_004FFC0C;                       /* world +0xBC service */
extern GameTimerService* D_004FFC2C;           /* world +0xDC service */
extern int D_004FFC3C;                         /* world +0xEC service */
extern unsigned char D_005721C8;               /* multiplayer flag */
extern int Game_IsMultiplayer(void);
extern int Global_ResetLevel(void);
extern void Global_ResetStats(void);
extern int Script_ClearSchedules_3DFB20(void);
extern void func_0013A290(GameTimerService*);
extern int PlayerInput_ClosePickupMenu(int);
extern int Backpack_RemoveAll(void);
extern int func_0025A120(void);
extern void func_002795A0(int);
extern int func_003FA1E0(int);

int Script_ResetLevel(void) {
    Global_ResetLevel();
    return 0;
}

/* Resets world services, the selected agent's mission data and all script schedules. */
int Global_ResetLevel(void) {
    GameTimerService* svc;
    int agent;

    PlayerInput_ClosePickupMenu((int)(D_004FFC0C + 0x50));
    Backpack_RemoveAll();
    func_0025A120();
    agent = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(agent);
    svc = D_004FFC2C;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
    func_0013A290(D_004FFC2C);
    func_003FA1E0((int)((char*)D_004FFC2C + 0x100));
    func_002795A0(D_004FFC3C);
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

    agent = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(agent);
    svc = D_004FFC2C;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
}

int Script_IsMultiplayer(void) {
    return Game_IsMultiplayer() & 0xFF;
}

int Game_IsMultiplayer(void) {
    return D_005721C8;
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


extern int Hud_StartGlobalTimer(GameTimerService*, int, float);

/* Starts the global timer: forwards to the timer service. */
int Global_StartGlobalTimer(int id, float value) {
    return Hud_StartGlobalTimer(D_004FFC2C, id, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F890 */

/* merge_units: begin func_0012F8A0 */
#pragma push /* merge_units */
extern void* GObj_IdentityB(int handle);
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
    Global_AddTremor(GObj_IdentityB(args[0]), *a, bv, cv);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F8A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F8A0 */
