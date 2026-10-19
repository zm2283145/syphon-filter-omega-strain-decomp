#pragma cplusplus on
#include "types.h"
struct Screen { char pad0[0x88]; int unk88; char pad8C[0xC]; int unk98; char pad9C[0x64]; int unk100; char pad104[0x5C]; int unk160; int unk164; int unk168; int unk16C; unsigned char unk170; };
extern "C" {
    int Agent_GetSelected(void*,int);
    void FrontEnd_ClosePopup(int,int);
    int FrontEnd_OpenPopup(int,int,char*,int,Screen* = 0,int = 0);
    int Gui_GetScreenList();
    void GuiKeyboard_Open(int,int,char*,Screen*,int,int,int);
    void GuiScreen_Navigate(Screen*,int);
    void func_0033C9E0(Screen*,int,char*);
    int GuiScreen_GetLobbyString(Screen*,int,char*,char*,int = 0,int = 0);
    void func_0033D8E0(Screen*,int);
    int func_0033DF00(Screen*,int,int,int,char*);
    int GuiManager_FindOrLoad(int,char*,char*);
    void GuiTextWidget_SetText(int,char*,int);
    int DME_GetLobby();
    char* func_0044A060(int);
    int func_0044A420(int,char*);
    int func_0044A800(int);
    int func_0044A810(int,int);
    int SFOLobby_LookupAccountId(int,char*);
    unsigned char func_00452FF0(int,int);
    extern char D_004ABCD0[],D_004ABCD8[],D_004ABCE8[],g_Game[];
    extern int D_004FFC04;
}
extern "C" int func_002AF310(Screen* arg0, int arg1, int arg2, int arg3, char* arg4) {
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
            selected = Agent_GetSelected(g_Game, -1) + 0x8BC;
            FrontEnd_OpenPopup(D_004FFC04, 5, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, (temp_s4->unk170 != 0) ? 0x45 : 0x44, 0, (char*)selected), temp_s4, 17);
            return 1;
        }
        if (arg1 == temp_s4->unk168) {
            int temp_v0 = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004ABCD8, D_004ABCE8);
            if (temp_v0 != 0) {
                GuiKeyboard_Open(temp_v0, GuiScreen_GetLobbyString(temp_s4, 0x49, 0, 0), D_004ABCD0, temp_s4, 15, 16, 0);
            }
            return 1;
        }
        if (arg1 == temp_s4->unk16C) {
            int temp_v0_2 = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004ABCD8, D_004ABCE8);
            if (temp_v0_2 != 0) {
                GuiKeyboard_Open(temp_v0_2, GuiScreen_GetLobbyString(temp_s4, 0x41, 0, 0), D_004ABCD0, temp_s4, 40, 14, 0);
            }
            return 1;
        }
    }
    if (temp_v1 == 26) {

        if (arg3 == 14) {
            var_s0 = var_s0 ? var_s0 : D_004ABCD0;
            int temp_v0_3 = DME_GetLobby();
            if (temp_v0_3 != 0) {
                int temp_s1 = D_004FFC04;
                int temp_s1_2 = FrontEnd_OpenPopup(temp_s1, 0, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x42, 0, 0));
                if (func_0044A420(temp_v0_3, var_s0) != 0) {
                    int temp_v0_4 = DME_GetLobby();
                    if (temp_v0_4 != 0) {
                        var_v0 = func_0044A060(temp_v0_4);
                        int temp_a0 = temp_s4->unk160;
                        if (temp_a0 != 0) {
                            var_v0 = var_v0 ? var_v0 : D_004ABCD0;
                            GuiTextWidget_SetText(temp_a0, var_v0, 0);
                        }
                    }
                } else {
                    int temp_s0 = D_004FFC04;
                    FrontEnd_OpenPopup(temp_s0, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x43, 0, 0));
                }
                FrontEnd_ClosePopup(D_004FFC04, temp_s1_2);
            }
            return 1;
        }
        if (arg3 == 17) {
            int temp_v0_5 = DME_GetLobby();
            if (temp_v0_5 != 0) {
                selected = Agent_GetSelected(g_Game, -1);
                int temp_s0_2 = D_004FFC04;
                int temp_s1_3 = FrontEnd_OpenPopup(temp_s0_2, 0, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x46, 0, (char*)selected + 0x8BC));
                if (func_0044A800(temp_v0_5) != 0) {
                    selected = Agent_GetSelected(g_Game, -1);
                    int temp_s0_3 = D_004FFC04;
                    FrontEnd_OpenPopup(temp_s0_3, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x47, 0, (char*)selected + 0x8BC), temp_s4, 15);
                } else {
                    selected = Agent_GetSelected(g_Game, -1);
                    int temp_s0_4 = D_004FFC04;
                    FrontEnd_OpenPopup(temp_s0_4, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x48, 0, (char*)selected + 0x8BC));
                }
                FrontEnd_ClosePopup(D_004FFC04, temp_s1_3);
            }
            return 1;
        }
        if (arg3 == 16) {
            if ((var_s0 != 0) && (*var_s0 != 0)) {
                int temp_v0_6 = DME_GetLobby();
                if (temp_v0_6 != 0) {
                    int temp_s1_4 = SFOLobby_LookupAccountId(temp_v0_6, var_s0);
                    if (func_00452FF0(temp_v0_6, 0) & 0xFF) {
                        int temp_s0_5 = D_004FFC04;
                        FrontEnd_OpenPopup(temp_s0_5, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x17, var_s0, 0));
                    } else {
                        func_0033C9E0(temp_s4, temp_s1_4, var_s0);
                    }
                }
            }
            return 1;
        }
        if (arg3 == 18) {
            int temp_v0_7 = DME_GetLobby();
            if (temp_v0_7 != 0) {
                int temp_s0_6 = D_004FFC04;
                int temp_s1_5 = FrontEnd_OpenPopup(temp_s0_6, 0, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x52, 0, 0));
                if (func_0044A810(temp_v0_7, temp_s4->unk100) != 0) {
                    int temp_s0_7 = D_004FFC04;
                    FrontEnd_OpenPopup(temp_s0_7, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x53, 0, 0));
                } else {
                    int temp_s0_8 = D_004FFC04;
                    FrontEnd_OpenPopup(temp_s0_8, 2, D_004ABCD0, GuiScreen_GetLobbyString(temp_s4, 0x54, 0, 0));
                }
                FrontEnd_ClosePopup(D_004FFC04, temp_s1_5);
            }
            return 1;
        }
        if (arg3 == 15) {
            GuiScreen_Navigate(temp_s4, 1);
            return 1;
        }
        if (arg3 == 23) {
            GuiScreen_Navigate(temp_s4, 1);
            return 1;
        }
    }
    if (temp_v1 == 0) {
        if (arg1 != temp_s4->unk88) {
            if (arg1 == temp_s4->unk98) {
                func_0033D8E0(temp_s4, 3);
            } else if ((arg1 == temp_s4->unk164) || (arg1 == temp_s4->unk168) || (arg1 == temp_s4->unk16C)) {
                func_0033D8E0(temp_s4, 4);
            } else {
                func_0033D8E0(temp_s4, 1);
            }
        }

    }
    return func_0033DF00(temp_s4, arg1, arg2, arg3, arg4);
}
