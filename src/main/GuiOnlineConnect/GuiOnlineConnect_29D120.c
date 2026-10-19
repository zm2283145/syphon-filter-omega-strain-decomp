#pragma cplusplus on
#include "types.h"
struct Str_0029D120 { char d[0x10]; };
struct E_0029D120 { unsigned char b0; char pad1[0x33]; char name[4]; };
struct L_0029D120;
struct S_0029D120 {
    char pad0[0x88]; int f88; char pad8C[8]; unsigned char b94; char pad95[3]; char f98[4]; int f9C; char padA0[0x14];
    char fB4[0x1C]; char fD0[0x1C]; L_0029D120* pEC;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AABF0[];
void* DME_GetLobby(void);
void App_CardWaitPoll(void);
int SFOLobby_EnterNetworkState(void* g, void* cb, void* a, void* b, void* c);
void GuiTextListWidget_Clear(L_0029D120* l);
E_0029D120* LobbyArray_At(void* v, int i);
void GuiTextListWidget_AddItem(L_0029D120* l, char* s, int i, int a);
void GuiArrayWidget_Select(L_0029D120* l, int a, int b);
void GuiOnlineConnect_ShowGroup(S_0029D120* self, int a);
void SFOLobby_LeaveNetworkState(void* g);
unsigned char SFOLobby_FormatError(void* g, int a);
void FrontEnd_LeaveOnline(void* ui, int a);
char* GuiScreen_GetLobbyString(S_0029D120* self, int a, int b, int c, int d, int e);
void String_CtorCStr_13B480(Str_0029D120* s, const char* c);
char* String_CStr(Str_0029D120* s);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_0029D120* d, int e);
void String_Dtor(Str_0029D120* s, int flags);
}
extern "C" void GuiOnlineConnect_ListConfigs(S_0029D120* self)
{
    void* g = DME_GetLobby();
    if (!g)
        return;
    if (SFOLobby_EnterNetworkState(g, (void*)App_CardWaitPoll, self->f98, self->fB4, self->fD0)) {
        int sel;
        int i;
        self->b94 = 1;
        self->f88 = 5;
        GuiTextListWidget_Clear(self->pEC);
        sel = -1;
        for (i = 0; i < self->f9C; i++) {
            E_0029D120* e = LobbyArray_At(self->f98, i);
            GuiTextListWidget_AddItem(self->pEC, e->name, i, 0);
            if (e->b0)
                sel = i;
        }
        if (sel != -1)
            GuiArrayWidget_Select(self->pEC, 0, sel);
        GuiOnlineConnect_ShowGroup(self, 0);
    } else {
        unsigned char r;
        SFOLobby_LeaveNetworkState(g);
        self->b94 = 0;
        r = SFOLobby_FormatError(g, 0);
        if (r == 0x2F || r == 0x30) {
            Str_0029D120 a;
            Str_0029D120 b;
            self->f88 = 3;
            FrontEnd_LeaveOnline(D_004FFC04, 1);
            String_CtorCStr_13B480(&a, GuiScreen_GetLobbyString(self, 6, 0, 0, 0, 0));
            String_CtorCStr_13B480(&b, GuiScreen_GetLobbyString(self, r == 0x2F ? 8 : 0x83, 0, 0, 0, 0));
            {
                char* tb = String_CStr(&b);
                FrontEnd_OpenPopup(D_004FFC04, 5, String_CStr(&a), tb, self, 0);
            }
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
        } else {
            void* ui;
            self->f88 = 4;
            ui = D_004FFC04;
            FrontEnd_OpenPopup(ui, 2, D_004AABF0, GuiScreen_GetLobbyString(self, 5, 0, 0, 0, 0), self, 0);
        }
    }
}