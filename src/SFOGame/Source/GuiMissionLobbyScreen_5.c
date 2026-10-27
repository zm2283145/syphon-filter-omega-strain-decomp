/*
 * SFOGame/Source/GuiMissionLobbyScreen: 1 file, 0033E5B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033E5B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Str5B0 { int d[4]; };
struct Nm5B0 { char c[0x20]; };
struct Rest5B0 { int w[11]; };
struct Info5B0 { int id; Nm5B0 name; Rest5B0 rest; };
struct Cfg5B0 { char pad[0xB5]; unsigned char fB5; };
struct O5B0 {
    char pad0[0x88]; Cfg5B0* f88; char pad8C[0xA8 - 0x8C]; int fa8;
    char padAC[0x110 - 0xAC]; int id; Nm5B0 name; Rest5B0 rest;
};
struct Ent5B0 { char pad0[0x24]; int f24; char pad28[0x34 - 0x28]; int f34; int f38; char pad3C[0x134 - 0x3C]; char nm[0x10]; };
struct FE5B0 { char pad0[0x35]; char f35; char pad36[0x188 - 0x36]; char ls[0x24C - 0x188]; int f24C; char pad250[4]; int f254; };
struct Lobby5B0 { char pad0[0x255C]; int f255C; int f2560; };
extern "C" {
extern Lobby5B0* cDME_GetLobby(void);
extern void DME_Update(void);
extern FE5B0* D_004FFC04;
extern char D_004B9C60[];
extern char D_004B9C98[];
extern char* D_00533000;
extern unsigned char D_00532FF0;
extern int D_00532FF8;
extern int D_005721A8;
extern char g_GameState;
extern char g_PrevGameState;
extern char g_Game[];
extern char g_LevelDirName[];
extern int g_OnlineMissionTable[];
extern char* D_0048C160[];
extern char* GuiLobbyScreen_GetLobbyString(O5B0*, unsigned char, char*, int, int, int);
extern int cGameFrontEnd_PushMessageBox(FE5B0*, int, char*, char*, O5B0*, int);
extern void cGameFrontEnd_PopMessageBox(FE5B0*, int);
extern void std_basic_string_char_char_traits_char_ctor_charP(Str5B0*, const char*);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
extern void String_Dtor(Str5B0*, int);
extern char* strncpy(char*, const char*, int);
extern char* strchr(const char*, int);
extern int strlen(const char*);
extern Ent5B0* SFOLobby_GetGameInfo(Lobby5B0*, int);
extern int SFOLobby_JoinGame(Lobby5B0*, int);
extern void SFOLobby_ExitGame(Lobby5B0*);
extern unsigned char SFOLobby_GetErrorDetails(Lobby5B0*, int);
extern void SFOLobby_Intel(Lobby5B0*);
extern void Game_ClearOtherAgentsB70(char*);
extern void GetMachine(void);
extern void cMachine_InitDME(void);
extern void MissionSelectData_SelectMission(void*, int);
extern unsigned long long cTimer_GetMillisecondTime(void);
extern void cGameFrontEnd_LobbyCallback(int, int);
extern char* nGlobalization_GetString_charP(char*);
extern void Net_CleanupGame(void);
}
extern "C" void GuiMenuScreen_JoinGame(O5B0* o, Info5B0* info, int arg2) {
    Str5B0 a1;
    Str5B0 b1;
    Str5B0 a2;
    Str5B0 b2;
    Str5B0 a3;
    Str5B0 b3;
    Str5B0 a4;
    Str5B0 a5;
    Str5B0 b5;
    char buf[0x10];
    Lobby5B0* lobby;
    int h;
    char* name;
    bool fail;
    Ent5B0* e;
    if (!o->fa8 || !cDME_GetLobby()) return;
    lobby = cDME_GetLobby();
    {
        FE5B0* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, 0x15, 0, 0, 0, 0), 0, 0);
    }
    name = 0;
    if (info->rest.w[7] >= 0 && info->rest.w[7] < 9) {
        int lv = g_OnlineMissionTable[info->rest.w[7]];
        if (lv != -1) {
            int cur = D_004FFC04->f24C;
            if (cur == -1 || lv == cur) name = D_0048C160[lv];
        }
    }
    if (name && name[0]) {
        strncpy(g_LevelDirName, name, 0x80);
    } else {
        std_basic_string_char_char_traits_char_ctor_charP(&a1, GuiLobbyScreen_GetLobbyString(o, 0x66, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b1, GuiLobbyScreen_GetLobbyString(o, 0x68, info->name.c, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b1);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a1), tb, 0, 0);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, h);
        String_Dtor(&b1, 0);
        String_Dtor(&a1, 0);
        return;
    }
    fail = false;
    e = SFOLobby_GetGameInfo(lobby, info->rest.w[9]);
    if (!e) fail = true;
    if (!fail) {
        int* pk = &e->f34;
        if (e->f38 != info->rest.w[7]) fail = true;
    if (!fail) {
        if (*pk != info->id) {
            if (o->f88 && o->f88->fB5 && e->nm[0]) {
                if (arg2) {
                    char* p = strchr(e->nm, 9);
                    int len = p ? p - e->nm : strlen(e->nm);
                    if (len < 1 || len > 15) fail = true;
                    else strncpy(buf, e->nm, len);
                    if (!fail) {
                        o->id = info->id;
                        o->name = info->name;
                        o->rest.w[0] = info->rest.w[0];
                        o->rest.w[1] = info->rest.w[1];
                        o->rest.w[2] = info->rest.w[2];
                        o->rest.w[3] = info->rest.w[3];
                        o->rest.w[4] = info->rest.w[4];
                        o->rest.w[5] = info->rest.w[5];
                        o->rest.w[6] = info->rest.w[6];
                        o->rest.w[7] = info->rest.w[7];
                        o->rest.w[8] = info->rest.w[8];
                        o->rest.w[9] = info->rest.w[9];
                        o->rest.w[10] = info->rest.w[10];
                        {
                            std_basic_string_char_char_traits_char_ctor_charP(&a2, GuiLobbyScreen_GetLobbyString(o, 0x89, 0, 0, 0, 0));
                            std_basic_string_char_char_traits_char_ctor_charP(&b2, GuiLobbyScreen_GetLobbyString(o, 0x8A, buf, 0, 0, 0));
                            {
                                char* tb = std_basic_string_char_char_traits_char_c_str(&b2);
                                cGameFrontEnd_PushMessageBox(D_004FFC04, 4, std_basic_string_char_char_traits_char_c_str(&a2), tb, o, 0x1E);
                            }
                            cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                            String_Dtor(&b2, 0);
                            String_Dtor(&a2, 0);
                        }
                        return;
                    }
                }
            } else {
                fail = true;
            }
        }
    }
    }
    if (fail) {
        std_basic_string_char_char_traits_char_ctor_charP(&a3, GuiLobbyScreen_GetLobbyString(o, 0x66, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b3, GuiLobbyScreen_GetLobbyString(o, 0x68, info->name.c, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b3);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a3), tb, 0, 0);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, h);
        String_Dtor(&b3, 0);
        String_Dtor(&a3, 0);
        return;
    }
    {
        int n = e->f24;
        int saved;
        void* ls;
        if (n < 1 || n > 4) n = 4;
        D_004FFC04->f254 = n;
        Game_ClearOtherAgentsB70(g_Game);
        GetMachine();
        cMachine_InitDME();
        lobby->f2560 = lobby->f255C;
        saved = D_004FFC04->f24C;
        ls = D_004FFC04->ls;
        MissionSelectData_SelectMission(ls, g_OnlineMissionTable[info->rest.w[7]]);
        if (SFOLobby_JoinGame(lobby, info->rest.w[9])) {
            bool timeout;
            int deadline = (int)cTimer_GetMillisecondTime() + 60000;
            while (!D_00532FF0 && deadline > cTimer_GetMillisecondTime()) {
                cGameFrontEnd_LobbyCallback(0, 0);
                SFOLobby_Intel(lobby);
                DME_Update();
            }
            timeout = false;
            if (!D_00532FF0) timeout = true;
            if (!timeout && (D_00532FF8 != 0) == 1) {
                g_PrevGameState = g_GameState;
                g_GameState = 3;
                D_004FFC04->f35 = 1;
            } else {
                char* msg;
                std_basic_string_char_char_traits_char_ctor_charP(&a4, GuiLobbyScreen_GetLobbyString(o, 0x66, 0, 0, 0, 0));
                msg = nGlobalization_GetString_charP(timeout ? D_004B9C98 : D_00533000);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a4), msg, 0, 0);
                if (timeout) {
                    int s = D_005721A8;
                    D_005721A8 = 0;
                    Net_CleanupGame();
                    if (s) D_005721A8 = s;
                } else {
                    Net_CleanupGame();
                }
                SFOLobby_ExitGame(lobby);
                lobby->f255C = lobby->f2560;
                MissionSelectData_SelectMission(ls, saved);
                String_Dtor(&a4, 0);
            }
        } else {
            int code;
            switch (SFOLobby_GetErrorDetails(lobby, 0)) {
            case 2: code = 0x6A; break;
            case 0x33: code = 0x6E; break;
            case 0x35: code = 0x6B; break;
            case 0x36: code = 0x6C; break;
            case 0x37: code = 0x6D; break;
            case 0x39: code = 0x76; break;
            default: code = 0x68; break;
            }
            {
                std_basic_string_char_char_traits_char_ctor_charP(&a5, GuiLobbyScreen_GetLobbyString(o, 0x66, 0, 0, 0, 0));
                std_basic_string_char_char_traits_char_ctor_charP(&b5, GuiLobbyScreen_GetLobbyString(o, code, info->name.c, 0, 0, 0));
                {
                    char* tb = std_basic_string_char_char_traits_char_c_str(&b5);
                    cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a5), tb, 0, 0);
                }
                MissionSelectData_SelectMission(ls, saved);
                String_Dtor(&b5, 0);
                String_Dtor(&a5, 0);
            }
        }
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    D_00532FF0 = 0;
    D_00532FF8 = 0;
    D_00533000 = 0;
}
static inline void merge_flush_func_0033E5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033E5B0 */
