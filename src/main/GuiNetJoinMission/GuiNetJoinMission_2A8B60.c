#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Loc_LookupText(int);
int GuiMissionLobbyScreen_SetDisplayMode(int, int);
int GuiTextWidget_SetText(int, int, int);
int DME_GetLobby();
int SFOLobby_LobbySetDisplay(int, int);
extern char D_004AB6A8[];
void * const D_0048BBE0[2] = { (void*)D_004AB6A8, (void*)0x0 };

void GuiNetJoinMission_DisplayAgentList(int arg0) {
    int temp_a0;
    int temp_v0;

    GuiMissionLobbyScreen_SetDisplayMode(arg0, 2);
    if (DME_GetLobby() != 0) {
        SFOLobby_LobbySetDisplay(DME_GetLobby(), 0);
    }
    temp_v0 = Loc_LookupText((*(int*)D_0048BBE0));
    if (temp_v0 != 0) {
        temp_a0 = F_(arg0, 0x160, int);
        if (temp_a0 != 0) {
            GuiTextWidget_SetText(temp_a0, temp_v0, 0);
        }
    }
}
