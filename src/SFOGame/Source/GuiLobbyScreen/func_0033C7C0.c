#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { char pad[0x84]; int f84; } O33;
extern void* D_004FFC04;
extern char D_004B99D8[];
extern int cDME_GetLobby(void);
extern char* GuiLobbyScreen_GetLobbyString(O33*, int, char*, char*, int, int);
extern int cGameFrontEnd_PushMessageBox(void*, int, char*, char*, int, int);
extern void cGameFrontEnd_PopMessageBox(void*, int);
extern int SFOLobby_ContactInviteAgent(int, int);
extern unsigned char SFOLobby_GetErrorDetails(int, int);
extern void std_basic_string_char_char_traits_char_ctor_charP(String*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(String*);
extern void String_Dtor(String*, int);

void GuiLobbyScreen_ContactInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = cDME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x39, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_ContactInviteAgent(lobby, buddy)) {
        void* g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x3A, name, 0, 0, 0), 0, 0);
    } else {
        int c;
        String a;
        String b;
        switch (SFOLobby_GetErrorDetails(lobby, 0)) {
        case 0x1E: c = 0x3C; break;
        case 0x25: c = 0x3D; break;
        case 0x1D: c = 0x17; break;
        case 0x2A: c = 0x3E; break;
        default: c = 0x3F; break;
        }
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x3B, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
        {
            char* t = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), t, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
}

