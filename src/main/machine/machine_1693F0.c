/*
 * main/machine: range (3 files, 001693F0-001695C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001693F0 */
#pragma push /* merge_units */
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char g_Game[];
extern void cDME_StartUpdateThread(void);
extern void cTeam_Init(void);
extern void cGameSystem_Init(void* w);
extern void cDME_JoinGame(void);
extern void cDME_SetNetReady(void);
extern void cHuman_LoadNetworkData(void);
extern void cNetObj_LoadNetworkData(void);
extern void DME_Update(void);
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
extern void* D_004FFC04;
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
