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
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004FFB50[];
extern void DME_StartThread(void);
extern void TeamRelations_Create(void);
extern void World_Setup(void* w);
extern void DME_JoinGame(void);
extern void func_0042B0C0(void);
extern void func_00185840(void);
extern void NetObj_LoadNetworkData(void);
extern void DME_Update(void);
static inline int IsHostGR(void)
{
    if (D_005721C8) return D_005721C0;
    return 1;
}
void Game_Reset(void)
{
    if (D_005721C8) DME_StartThread();
    TeamRelations_Create();
    World_Setup(D_004FFB50);
    if (D_005721C8) {
        DME_JoinGame();
        func_0042B0C0();
        if (!IsHostGR()) {
            func_00185840();
            NetObj_LoadNetworkData();
        } else {
            TeamRelations_Create();
        }
    }
    if (D_005721C8) DME_Update();
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
extern char D_004FFC90[];
extern char D_004FFB8C[];
extern char D_0055DDA0[];
extern void func_003A64F0(void);
extern void func_00165DC0(O169*);
extern int ScriptMgr_ExportSymbols(char*, char*, char*);
extern int Archive_Open(char*, char*, int, int);
extern void func_003E2140(char*, int);
extern void ScriptMgr_InitClient(char*);
extern void PartsTable_Load(int);
extern void ArchiveList_CloseNamed(char*, char*);
extern void ManUtils_LoadSKL(char*);
extern void func_0036B3B0(int, int, int);
extern void func_0042C1E0(void);
#pragma opt_propagation off
void App_BindIopRpc(O169* o) {
    char buf[0x40];
    if (!D_0048A010) return;
    D_0048A010 = 0;
    func_003A64F0();
    func_00165DC0(o);
    if (ScriptMgr_ExportSymbols(D_00555070, D_0048B2F8, D_004FFC90)) {
        char* arc;
        int h;
        sprintf(buf, "%s\\COMMON\\SCRIPTS.HOG", D_0048B2F8);
        arc = D_004FFB8C;
        h = Archive_Open(arc, buf, 0, 0);
        func_003E2140(D_00555070, h);
        ScriptMgr_InitClient(D_00555070);
        PartsTable_Load(h);
        ArchiveList_CloseNamed(arc, buf);
    }
    ManUtils_LoadSKL(D_0055DDA0);
    func_0036B3B0(2, 0xC1C00, 16);
    func_0042C1E0();
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
extern unsigned char D_004FFBA0;
extern F1Cfg1695* D_004FFD2C;
extern float D_004C1FC8;
extern int D_005383D4;
extern int D_005383C0;
extern void* D_004FFC04;
extern char D_005381F0[];
extern void* func_0010D050(void);
extern void ChangeThreadPriority(void* p, int n);
extern void func_003A65F0(int n);
extern void func_00165E40(F1Game1695* g);
extern void Game_LoadIni(F1Game1695* g);
extern void Loc_LoadCommonPool(char* name);
extern void func_003A6560(void);
extern void func_00165DD0(F1Game1695* g);
extern void Renderer_Init(void* p, int a, int b, int c, int d, int e, int f, int g);
extern void Boot_LoadFonts(F1Game1695* g);
extern void FrontEnd_CreateCanvas(void* p, int n);
extern void FrontEnd_SetLoadingScreen(void* p, int a, void* b, int c);
void StringPool_Load(F1Game1695* g)
{
    ChangeThreadPriority(func_0010D050(), 10);
    func_003A65F0(1);
    func_00165E40(g);
    Game_LoadIni(g);
    Loc_LoadCommonPool(D_0048B2F8);
    func_003A6560();
    func_00165DD0(g);
    if (D_004FFBA0 == 9) {
        Renderer_Init(D_005381F0, g->x254, g->x258, 0x20, 0x10, g->b250, 4000, 500);
        D_005383D4 = g->x260;
        D_005383C0 = (unsigned char)(int)(D_004C1FC8 * D_004FFD2C->scale);
        Boot_LoadFonts(g);
        FrontEnd_CreateCanvas(D_004FFC04, 0);
        FrontEnd_SetLoadingScreen(D_004FFC04, 1, "ROOT", 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001695C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001695C0 */
