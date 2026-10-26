#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { char pad[0x84]; int f84; } O33;
extern void* D_004FFC04;
extern char D_004B99D8[];
extern int DME_GetLobby(void);
extern char* GuiScreen_GetLobbyString(O33*, int, char*, char*, int, int);
extern int FrontEnd_OpenPopup(void*, int, char*, char*, int, int);
extern void FrontEnd_ClosePopup(void*, int);
extern int SFOLobby_AddBuddy(int, int);
extern unsigned char SFOLobby_FormatError(int, int);
extern void String_CtorCStr_13B480(String*, char*);
extern char* String_CStr(String*);
extern void String_Dtor(String*, int);

void GuiLobbyScreen_ContactInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = DME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = FrontEnd_OpenPopup(g, 0, D_004B99D8, GuiScreen_GetLobbyString(self, 0x39, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_AddBuddy(lobby, buddy)) {
        void* g = D_004FFC04;
        FrontEnd_OpenPopup(g, 2, D_004B99D8, GuiScreen_GetLobbyString(self, 0x3A, name, 0, 0, 0), 0, 0);
    } else {
        int c;
        String a;
        String b;
        switch (SFOLobby_FormatError(lobby, 0)) {
        case 0x1E: c = 0x3C; break;
        case 0x25: c = 0x3D; break;
        case 0x1D: c = 0x17; break;
        case 0x2A: c = 0x3E; break;
        default: c = 0x3F; break;
        }
        String_CtorCStr_13B480(&a, GuiScreen_GetLobbyString(self, 0x3B, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, GuiScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
        {
            char* t = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), t, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
    FrontEnd_ClosePopup(D_004FFC04, h);
}

