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
void* cDME_GetLobby(void);
char* GuiLobbyScreen_GetLobbyString(void* self, int a, int b, int c, int d, int e);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, void* d, int e);
void GetMachine(void);
void cMachine_InitDME(void);
unsigned char SFOLobby_CreateGame(void* g, int a, int b, int c);
unsigned char SFOLobby_GetErrorDetails(void* g, int a);
void GuiMissionSetup_FailedLobbyConnect(void* self, int builtin);
void cGameFrontEnd_PopMessageBox(void* ui, int id);
void cGameFrontEnd_LobbyCallback(int a, int b);
void SFOLobby_Intel(void* g);
void GuiMissionSetup_SuccessLobbyConnect(void* self);
}
static inline bool Nz_002A0F60(int v) { return v != 0; }
extern "C" void GuiMissionSetup_CreateMission(S_002A0F60* self)
{
    Game_ClearOtherAgentsB70(g_Game);
    D_004FFC04->f254 = self->pF4->f40;
    if (!D_004FFC04->b32) {
        void* g = cDME_GetLobby();
        if (g) {
            Ui_002A0F60* ui = D_004FFC04;
            int k = ui->f248;
            int h = cGameFrontEnd_PushMessageBox(ui, 0, D_004AAFF0, GuiLobbyScreen_GetLobbyString(self, 0x16, 0, 0, 0, 0), 0, 0);
            int res;
            GetMachine();
            cMachine_InitDME();
            D_005064A8 = 0;
            D_005064B0 = 0;
            D_005064B8 = 0;
            res = SFOLobby_CreateGame(g, k, self->pF4->f40, self->pF4->b45);
            if (res == 0 && SFOLobby_GetErrorDetails(g, 0) == 0x31) {
                GuiMissionSetup_FailedLobbyConnect(self, 1);
                cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                return;
            }
            while (Nz_002A0F60(D_005064A8) ^ 1) {
                cGameFrontEnd_LobbyCallback(0, 0);
                SFOLobby_Intel(g);
            }
            {
                bool r = Nz_002A0F60(D_005064B0);
                if (r == 1 && (unsigned char)res == 1) {
                    GuiMissionSetup_SuccessLobbyConnect(self);
                    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                    return;
                }
                GuiMissionSetup_FailedLobbyConnect(self, r == 1);
                cGameFrontEnd_PopMessageBox(D_004FFC04, h);
            }
        }
    }
}
