/*
 * SFOGame/Source/GuiNetJoinMission: 1 file, 002A8BE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiNetJoinMission_2A8BE0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int nGlobalization_GetString_charP(int);
int GuiMissionLobbyScreen_SetDisplayMode(int, int);
int GuiTextWidget_SetText(int, int, int);
int cDME_GetLobby();
int SFOLobby_LobbySetDisplay(int, int);
extern char D_004AB698[];
void * const D_0048BBD8[2] = { (void*)D_004AB698, (void*)0x0 };

void GuiNetJoinMission_DisplayGameList(int arg0) {
    int temp_a0;
    int temp_v0;

    GuiMissionLobbyScreen_SetDisplayMode(arg0, 0);
    if (cDME_GetLobby() != 0) {
        SFOLobby_LobbySetDisplay(cDME_GetLobby(), 1);
    }
    temp_v0 = nGlobalization_GetString_charP((*(int*)D_0048BBD8));
    if (temp_v0 != 0) {
        temp_a0 = F_(arg0, 0x160, int);
        if (temp_a0 != 0) {
            GuiTextWidget_SetText(temp_a0, temp_v0, 0);
        }
    }
}
static inline void merge_flush_GuiNetJoinMission_2A8BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiNetJoinMission_2A8BE0 */
