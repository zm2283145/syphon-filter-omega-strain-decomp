/*
 * SFOGame/Source/machine: 10 files, 00169210-001693F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00169210 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#include "short_string_data.h"

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cStartLevelMsg_dtor, D_004DADD0, cMessage_dtor)
static inline void merge_flush_func_00169210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169210 */

/* merge_units: begin func_00169270 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cPauseMusicMsg_dtor, D_004D97F0, cMessage_dtor)
static inline void merge_flush_func_00169270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169270 */

/* merge_units: begin func_001692D0 */
#pragma push /* merge_units */
/* String character data. */
DEFINE_SHORT_STRING_DATA(std_basic_string_char_char_traits_char_c_str)
static inline void merge_flush_func_001692D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001692D0 */

/* merge_units: begin func_001692F0 */
#pragma push /* merge_units */
extern char D_005721F0;   /* already-initialized flag / instance */
extern char D_005721E0[];
extern void* nGlobalization_GetString_charP(void* storage);

/* Lazy singleton: returns the instance if set up, else initializes it. */
void* cDME_GetQuitMessage(void) {
    if (D_005721F0) {
        return &D_005721F0;
    }
    return nGlobalization_GetString_charP(D_005721E0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001692F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001692F0 */

/* merge_units: begin func_00169330 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern signed char D_005721F0;
#endif /* merge_units */
#define D_005721F0 (*(signed char*)&D_005721F0) /* merge_units */


#if 0 /* merge_units */
extern int D_005721E0;
#endif /* merge_units */
#define D_005721E0 (*(int*)&D_005721E0) /* merge_units */


#if 0 /* merge_units */
extern int nGlobalization_GetString_charP(void*);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) ((int)nGlobalization_GetString_charP((a0))) /* merge_units */



/* Returns nGlobalization_GetString_charP(&D_005721E0) when the D_005721F0 flag is set, else 0. */
int cDME_GetQuitTitle(void) {
    int r = D_005721F0;
    if (r != 0) r = nGlobalization_GetString_charP(&D_005721E0);
    else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169330(void) {}
#undef D_005721F0 /* merge_units */
#undef D_005721E0 /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169330 */

/* merge_units: begin func_00169360 */
#pragma push /* merge_units */
extern char D_005721D8[];

int cDME_Quit(void) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)D_005721D8;
    cond = v0 == 0;
    if (cond) goto L00169380;
    v0 = 0 + 1;
    *(char*)(char*)D_005721D8 = 0;
    goto L00169388;
L00169380:;
    v0 = 0;
L00169388:;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00169360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169360 */

/* merge_units: begin func_00169390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void* D_004FFC04;
extern unsigned char g_IsMultiplayer;    /* nonzero in a multiplayer game */
extern int cNetMsgThrottle_NextFrame(void);
extern void cGameFrontEnd_LobbyUpdate(void* obj);
extern int cDME_GetLobby(void);
extern int DME_Update(void);

/* Per-frame service: flush network messages in multiplayer, then update D_004FFC04. */
void cMachine_NetUpdate(void) {
    if (g_IsMultiplayer != 0) {
        cNetMsgThrottle_NextFrame();
        DME_Update();
    }
    if (D_004FFC04 != 0 && cDME_GetLobby() != 0) {
        cGameFrontEnd_LobbyUpdate(D_004FFC04);
    }
}
static inline void merge_flush_func_00169390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169390 */

/* merge_units: begin func_001693F0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
extern unsigned char D_005721C0;
extern char g_Game[];
extern void cDME_StartUpdateThread(void);
extern void cTeam_Init(void);
extern void cGameSystem_Init(void* w);
extern void cDME_JoinGame(void);
extern void cDME_SetNetReady(void);
extern void cHuman_LoadNetworkData(void);
extern void cNetObj_LoadNetworkData(void);
#if 0 /* merge_units */
extern void DME_Update(void);
#endif /* merge_units */
#define DME_Update() ((void)DME_Update()) /* merge_units */

static inline int IsHostGR(void)
{
    if (g_IsMultiplayer) return D_005721C0;
    return 1;
}
void cMachine_NetInit(void)
{
    if (g_IsMultiplayer) cDME_StartUpdateThread();
    cTeam_Init();
    cGameSystem_Init(g_Game);
    if (g_IsMultiplayer) {
        cDME_JoinGame();
        cDME_SetNetReady();
        if (!IsHostGR()) {
            cHuman_LoadNetworkData();
            cNetObj_LoadNetworkData();
        } else {
            cTeam_Init();
        }
    }
    if (g_IsMultiplayer) DME_Update();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001693F0(void) {}
#undef DME_Update /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001693F0 */

/* merge_units: begin func_001694B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x278]; unsigned char b278; } O169;
extern unsigned char D_0048A010;
extern char D_00555070[];
extern char D_0048B2F8[];
extern char g_LevelDirName[];
extern char D_004FFB8C[];
extern char g_AgentPartCache[];
extern void Iop_LoadMcUsbModules(void);
extern void cMachine_InitUSB(O169*);
extern int cScriptInterpreter_Init(char*, char*, char*);
extern int cHogList_Open(char*, char*, int, int);
extern void cScriptInterpreter_SetHog(char*, int);
extern void cScriptInterpreter_ExecClientScripts(char*);
extern void cAgentData_LoadPartData(int);
extern void cHogList_Close(char*, char*);
extern void Monster_MonsterInit(char*);
extern void cMemMan_Init_int_uint_uint(int, int, int);
extern void cNellyMoser_nmsCreate(void);
#pragma opt_propagation off
void App_BindIopRpc(O169* o) {
    char buf[0x40];
    if (!D_0048A010) return;
    D_0048A010 = 0;
    Iop_LoadMcUsbModules();
    cMachine_InitUSB(o);
    if (cScriptInterpreter_Init(D_00555070, D_0048B2F8, g_LevelDirName)) {
        char* arc;
        int h;
        sprintf(buf, "%s\\COMMON\\SCRIPTS.HOG", D_0048B2F8);
        arc = D_004FFB8C;
        h = cHogList_Open(arc, buf, 0, 0);
        cScriptInterpreter_SetHog(D_00555070, h);
        cScriptInterpreter_ExecClientScripts(D_00555070);
        cAgentData_LoadPartData(h);
        cHogList_Close(arc, buf);
    }
    Monster_MonsterInit(g_AgentPartCache);
    cMemMan_Init_int_uint_uint(2, 0xC1C00, 16);
    cNellyMoser_nmsCreate();
    o->b278 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001694B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001694B0 */

/* merge_units: begin func_001695C0 */
#pragma push /* merge_units */
typedef struct F1Game1695 { char pad0[0x250]; unsigned char b250; char pad251[3]; int x254; int x258; int pad25C; int x260; } F1Game1695;
typedef struct F1Cfg1695 { char pad0[0x1C]; float scale; } F1Cfg1695;
extern unsigned char g_GameState;
extern F1Cfg1695* g_OptionsRecord;
extern float D_004C1FC8;
extern int D_005383D4;
extern int D_005383C0;
extern char g_Video[];
extern void* GetThreadId(void);
extern void ChangeThreadPriority(void* p, int n);
extern void SFOLibInit(int n);
extern void cMachine_InitTimers(F1Game1695* g);
extern void cMachine_InitINI(F1Game1695* g);
extern void nGlobalization_LoadCommonStrings(char* name);
extern void Iop_LoadPadSoundModules(void);
extern void cMachine_InitJoystick(F1Game1695* g);
extern void XLib_Init(void* p, int a, int b, int c, int d, int e, int f, int g);
extern void cMachine_InitFonts(F1Game1695* g);
extern void FrontEnd_CreateCanvas(void* p, int n);
extern void FrontEnd_SetLoadingScreen(void* p, int a, void* b, int c);
void StringPool_Load(F1Game1695* g)
{
    ChangeThreadPriority(GetThreadId(), 10);
    SFOLibInit(1);
    cMachine_InitTimers(g);
    cMachine_InitINI(g);
    nGlobalization_LoadCommonStrings(D_0048B2F8);
    Iop_LoadPadSoundModules();
    cMachine_InitJoystick(g);
    if (g_GameState == 9) {
        XLib_Init(g_Video, g->x254, g->x258, 0x20, 0x10, g->b250, 4000, 500);
        D_005383D4 = g->x260;
        D_005383C0 = (unsigned char)(int)(D_004C1FC8 * g_OptionsRecord->scale);
        cMachine_InitFonts(g);
        FrontEnd_CreateCanvas(D_004FFC04, 0);
        FrontEnd_SetLoadingScreen(D_004FFC04, 1, "ROOT", 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001695C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001695C0 */
