#pragma cplusplus on
#include "types.h"
struct Screen { char pad0[0x88]; int unk88; char pad8C[0xC]; int unk98; char pad9C[0x64]; int unk100; char pad104[0x5C]; int unk160; int unk164; int unk168; int unk16C; unsigned char unk170; };
extern "C" {
    int cGameSystem_GetAgentData(void*,int);
    void cGameFrontEnd_PopMessageBox(int,int);
    int cGameFrontEnd_PushMessageBox(int,int,char*,int,Screen* = 0,int = 0);
    int Gui_Manager();
    void GuiKeyboard_Display(int,int,char*,Screen*,int,int,int);
    void GuiLobbyScreen_PushLobbyScreen(Screen*,int);
    void GuiLobbyScreen_CellInviteAgent(Screen*,int,char*);
    int GuiLobbyScreen_GetLobbyString(Screen*,int,char*,char*,int = 0,int = 0);
    void GuiMissionLobbyScreen_SetDisplayMode(Screen*,int);
    int GuiMissionLobbyScreen_onMessage(Screen*,int,int,int,char*);
    int GuiManager_OpenGui(int,char*,char*);
    void GuiTextWidget_SetText(int,char*,int);
    int cDME_GetLobby();
    char* SFOLobby_CellGetMessage(int);
    int SFOLobby_CellSetMessage(int,char*);
    int SFOLobby_CellResign(int);
    int SFOLobby_CellRemoveAgent(int,int);
    int SFOLobby_GetAgentID(int,char*);
    unsigned char SFOLobby_GetErrorDetails(int,int);
    extern char D_004ABCD0[],D_004ABCD8[],D_004ABCE8[],g_Game[];
    extern int D_004FFC04;
}
extern "C" int GuiNetAgencyCell_onMessage(Screen* arg0, int arg1, int arg2, int arg3, char* arg4) {
    Screen* temp_s4;
    Screen* var_a0;
    int temp_v1;
    char *var_s0;
    char *var_v0;
    int selected;

    var_a0 = arg0;
    temp_v1 = arg2 & 0xFFFF;
    temp_s4 = var_a0;
    var_s0 = arg4;
    if (temp_v1 == 2) {

        if (arg1 == temp_s4->unk164) {
            selected = cGameSystem_GetAgentData(g_Game, -1) + 0x8BC;
            cGameFrontEnd_PushMessageBox(D_004FFC04, 5, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, (temp_s4->unk170 != 0) ? 0x45 : 0x44, 0, (char*)selected), temp_s4, 17);
            return 1;
        }
        if (arg1 == temp_s4->unk168) {
            int temp_v0 = GuiManager_OpenGui(Gui_Manager(), D_004ABCD8, D_004ABCE8);
            if (temp_v0 != 0) {
                GuiKeyboard_Display(temp_v0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x49, 0, 0), D_004ABCD0, temp_s4, 15, 16, 0);
            }
            return 1;
        }
        if (arg1 == temp_s4->unk16C) {
            int temp_v0_2 = GuiManager_OpenGui(Gui_Manager(), D_004ABCD8, D_004ABCE8);
            if (temp_v0_2 != 0) {
                GuiKeyboard_Display(temp_v0_2, GuiLobbyScreen_GetLobbyString(temp_s4, 0x41, 0, 0), D_004ABCD0, temp_s4, 40, 14, 0);
            }
            return 1;
        }
    }
    if (temp_v1 == 26) {

        if (arg3 == 14) {
            var_s0 = var_s0 ? var_s0 : D_004ABCD0;
            int temp_v0_3 = cDME_GetLobby();
            if (temp_v0_3 != 0) {
                int temp_s1 = D_004FFC04;
                int temp_s1_2 = cGameFrontEnd_PushMessageBox(temp_s1, 0, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x42, 0, 0));
                if (SFOLobby_CellSetMessage(temp_v0_3, var_s0) != 0) {
                    int temp_v0_4 = cDME_GetLobby();
                    if (temp_v0_4 != 0) {
                        var_v0 = SFOLobby_CellGetMessage(temp_v0_4);
                        int temp_a0 = temp_s4->unk160;
                        if (temp_a0 != 0) {
                            var_v0 = var_v0 ? var_v0 : D_004ABCD0;
                            GuiTextWidget_SetText(temp_a0, var_v0, 0);
                        }
                    }
                } else {
                    int temp_s0 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(temp_s0, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x43, 0, 0));
                }
                cGameFrontEnd_PopMessageBox(D_004FFC04, temp_s1_2);
            }
            return 1;
        }
        if (arg3 == 17) {
            int temp_v0_5 = cDME_GetLobby();
            if (temp_v0_5 != 0) {
                selected = cGameSystem_GetAgentData(g_Game, -1);
                int temp_s0_2 = D_004FFC04;
                int temp_s1_3 = cGameFrontEnd_PushMessageBox(temp_s0_2, 0, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x46, 0, (char*)selected + 0x8BC));
                if (SFOLobby_CellResign(temp_v0_5) != 0) {
                    selected = cGameSystem_GetAgentData(g_Game, -1);
                    int temp_s0_3 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(temp_s0_3, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x47, 0, (char*)selected + 0x8BC), temp_s4, 15);
                } else {
                    selected = cGameSystem_GetAgentData(g_Game, -1);
                    int temp_s0_4 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(temp_s0_4, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x48, 0, (char*)selected + 0x8BC));
                }
                cGameFrontEnd_PopMessageBox(D_004FFC04, temp_s1_3);
            }
            return 1;
        }
        if (arg3 == 16) {
            if ((var_s0 != 0) && (*var_s0 != 0)) {
                int temp_v0_6 = cDME_GetLobby();
                if (temp_v0_6 != 0) {
                    int temp_s1_4 = SFOLobby_GetAgentID(temp_v0_6, var_s0);
                    if (SFOLobby_GetErrorDetails(temp_v0_6, 0) & 0xFF) {
                        int temp_s0_5 = D_004FFC04;
                        cGameFrontEnd_PushMessageBox(temp_s0_5, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x17, var_s0, 0));
                    } else {
                        GuiLobbyScreen_CellInviteAgent(temp_s4, temp_s1_4, var_s0);
                    }
                }
            }
            return 1;
        }
        if (arg3 == 18) {
            int temp_v0_7 = cDME_GetLobby();
            if (temp_v0_7 != 0) {
                int temp_s0_6 = D_004FFC04;
                int temp_s1_5 = cGameFrontEnd_PushMessageBox(temp_s0_6, 0, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x52, 0, 0));
                if (SFOLobby_CellRemoveAgent(temp_v0_7, temp_s4->unk100) != 0) {
                    int temp_s0_7 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(temp_s0_7, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x53, 0, 0));
                } else {
                    int temp_s0_8 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(temp_s0_8, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(temp_s4, 0x54, 0, 0));
                }
                cGameFrontEnd_PopMessageBox(D_004FFC04, temp_s1_5);
            }
            return 1;
        }
        if (arg3 == 15) {
            GuiLobbyScreen_PushLobbyScreen(temp_s4, 1);
            return 1;
        }
        if (arg3 == 23) {
            GuiLobbyScreen_PushLobbyScreen(temp_s4, 1);
            return 1;
        }
    }
    if (temp_v1 == 0) {
        if (arg1 != temp_s4->unk88) {
            if (arg1 == temp_s4->unk98) {
                GuiMissionLobbyScreen_SetDisplayMode(temp_s4, 3);
            } else if ((arg1 == temp_s4->unk164) || (arg1 == temp_s4->unk168) || (arg1 == temp_s4->unk16C)) {
                GuiMissionLobbyScreen_SetDisplayMode(temp_s4, 4);
            } else {
                GuiMissionLobbyScreen_SetDisplayMode(temp_s4, 1);
            }
        }

    }
    return GuiMissionLobbyScreen_onMessage(temp_s4, arg1, arg2, arg3, arg4);
}
