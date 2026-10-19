/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A0DC0-002A0E80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0DC0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Agent_GetSelected(char *, int, int, signed char);               
int AgentData_AddLevelProgress(int, int, int, int);                    
const unsigned int g_OnlineMissionTable[12] = { 0x0, 0x1, 0x2, 0x4, 0x5, 0x8, 0xC, 0xD, 0x10, 0x0, 0x0, 0x0 };
extern char g_Game;
extern signed char g_GameState;
extern signed char g_PrevGameState;
extern char * D_004FFC04;
extern signed char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;

void GuiMissionSetup_OnGameCreated(void) {
    int temp_s0;
    signed char temp_a3;

    temp_a3 = g_GameState;
    g_PrevGameState = temp_a3;
    g_GameState = 3;
    F_(D_004FFC04, 0x35, signed char) = 1;
    F_(D_004FFC04, 0x33, signed char) = 1;
    temp_s0 = F_(D_004FFC04, 0x248, int);
    if (temp_s0 != -1) {
        AgentData_AddLevelProgress(Agent_GetSelected(&g_Game, -1, 3, temp_a3), F_(&(*(char*)g_OnlineMissionTable), (temp_s0 * 4), int) + 1, 6, 1);
    }
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0DC0 */

/* merge_units: begin func_002A0E80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */

extern char D_004AAFF0[];
#if 0 /* merge_units */
extern char* D_005064B8;
#endif /* merge_units */
#define D_005064B8 (*(char **)&D_005064B8) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_005064A8;
#endif /* merge_units */
#define D_005064A8 (*(unsigned char*)&D_005064A8) /* merge_units */

extern char* GuiScreen_GetLobbyString(void* self, int id, int a, int b, int c, int d);
extern char* Loc_LookupText(char* key);
extern void FrontEnd_OpenPopup(void* gui, int kind, char* title, char* text, int a, int b);
extern void Net_CleanupGame(void);

static inline unsigned char Nz2A0E80(int v) { return v != 0; }
/* Shows the pending message box (built-in text or a looked-up key) and clears the request. */
void GuiMissionSetup_OnGameCreateFailed(void* self, int builtin)
{
    void* g;
    if (builtin) {
        g = D_004FFC04;
        FrontEnd_OpenPopup(g, 2, D_004AAFF0, GuiScreen_GetLobbyString(self, 0x59, 0, 0, 0, 0), 0, 0);
    } else {
        g = D_004FFC04;
        FrontEnd_OpenPopup(g, 2, D_004AAFF0, Loc_LookupText(D_005064B8), 0, 0);
    }
    if (Nz2A0E80(D_005064B0) == 1) Net_CleanupGame();
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
}
#undef D_004FFC04 /* merge_units */
#undef D_005064B8 /* merge_units */
#undef D_005064A8 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0E80 */
