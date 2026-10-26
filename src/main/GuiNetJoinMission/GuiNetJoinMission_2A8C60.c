#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Loc_LookupText(int);
int GuiMissionLobbyScreen_GetDisplayMode();
int GuiMissionLobbyScreen_SetDisplayMode(char * , int);
int GuiTextWidget_SetText(int, int, int);
int DME_GetLobby();
int SFOLobby_LobbySetDisplay(int, int);
extern int D_0048BBD8;
extern int D_0048BBE0;

void GuiNetJoinMission_ToggleListDisplay(char * arg0) {
    int temp_a0;
    int temp_a0_2;
    int temp_v0;
    int temp_v0_2;

    if ((GuiMissionLobbyScreen_GetDisplayMode() & 0xFF) == 2) {
        GuiMissionLobbyScreen_SetDisplayMode(arg0, 0);
        if (DME_GetLobby() != 0) {
            SFOLobby_LobbySetDisplay(DME_GetLobby(), 1);
        }
        temp_v0 = Loc_LookupText(D_0048BBD8);
        if (temp_v0 != 0) {
            temp_a0 = F_(arg0, 0x160, int);
            if (temp_a0 != 0) {
                GuiTextWidget_SetText(temp_a0, temp_v0, 0);
            }
        }
    } else {
        GuiMissionLobbyScreen_SetDisplayMode(arg0, 2);
        if (DME_GetLobby() != 0) {
            SFOLobby_LobbySetDisplay(DME_GetLobby(), 0);
        }
        temp_v0_2 = Loc_LookupText(D_0048BBE0);
        if (temp_v0_2 != 0) {
            temp_a0_2 = F_(arg0, 0x160, int);
            if (temp_a0_2 != 0) {
                GuiTextWidget_SetText(temp_a0_2, temp_v0_2, 0);
            }
        }
    }
}
