#pragma cplusplus on
#include "types.h"
struct P_002A0F60 { char pad[0x40]; int f40; char pad44; unsigned char b45; };
struct Ui_002A0F60 { char pad[0x32]; unsigned char b32; char pad33[0x248 - 0x33]; int f248; char pad24C[8]; int f254; };
struct S_002A0F60 { char pad[0xF4]; P_002A0F60* pF4; };
extern "C" {
extern Ui_002A0F60* D_004FFC04;
extern char D_004AAFF0[];
extern char g_Game[];
extern unsigned char D_005064A8;
extern int D_005064B0;
extern char* D_005064B8;
void Game_ClearOtherAgentsB70(void* p);
void* DME_GetLobby(void);
char* GuiScreen_GetLobbyString(void* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
void App_GetInstance(void);
void App_InitSystemsOnce(void);
unsigned char SFOLobby_CreateGame(void* g, int a, int b, int c);
unsigned char SFOLobby_FormatError(void* g, int a);
void GuiMissionSetup_OnGameCreateFailed(void* self, int builtin);
void FrontEnd_ClosePopup(void* ui, int id);
void App_CardWaitPoll(int a, int b);
void SFOLobby_Update(void* g);
void GuiMissionSetup_OnGameCreated(void* self);
}
static inline bool Nz_002A0F60(int v) { return v != 0; }
extern "C" void GuiMissionSetup_BeginMission(S_002A0F60* self)
{
    Game_ClearOtherAgentsB70(g_Game);
    D_004FFC04->f254 = self->pF4->f40;
    if (!D_004FFC04->b32) {
        void* g = DME_GetLobby();
        if (g) {
            Ui_002A0F60* ui = D_004FFC04;
            int k = ui->f248;
            int h = FrontEnd_OpenPopup(ui, 0, D_004AAFF0, GuiScreen_GetLobbyString(self, 0x16, 0, 0, 0, 0), 0, 0);
            int res;
            App_GetInstance();
            App_InitSystemsOnce();
            D_005064A8 = 0;
            D_005064B0 = 0;
            D_005064B8 = 0;
            res = SFOLobby_CreateGame(g, k, self->pF4->f40, self->pF4->b45);
            if (res == 0 && SFOLobby_FormatError(g, 0) == 0x31) {
                GuiMissionSetup_OnGameCreateFailed(self, 1);
                FrontEnd_ClosePopup(D_004FFC04, h);
                return;
            }
            while (Nz_002A0F60(D_005064A8) ^ 1) {
                App_CardWaitPoll(0, 0);
                SFOLobby_Update(g);
            }
            {
                bool r = Nz_002A0F60(D_005064B0);
                if (r == 1 && (unsigned char)res == 1) {
                    GuiMissionSetup_OnGameCreated(self);
                    FrontEnd_ClosePopup(D_004FFC04, h);
                    return;
                }
                GuiMissionSetup_OnGameCreateFailed(self, r == 1);
                FrontEnd_ClosePopup(D_004FFC04, h);
            }
        }
    }
}
