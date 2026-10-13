#pragma cplusplus on
#include "types.h"
struct Str_002A9A20 { char d[0x10]; };
struct G_002A9A20 { int f0; };
struct Prof_002A9A20 { char pad0[0x80]; char name[0x44]; int fC4; };
struct Ag_002A9A20 { char pad0[0x8DC]; Prof_002A9A20 prof; };
struct E_002A9A20 { int f0; char name[4]; };
struct S_002A9A20 {
    char pad0[0x4C]; unsigned char b4C; char pad4D[0x98 - 0x4D];
    int f98; int f9C; char fA0[4];
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AB808[];
extern char D_004FFB50[];
G_002A9A20* DME_GetLobby(void);
int func_0033CE30(S_002A9A20* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_002A9A20* d, int e);
Ag_002A9A20* Agent_GetSelected(void* a, int b);
char* String_CStr(void* s);
E_002A9A20* LobbyArray_At(void* v, int i);
int SFOLobby_JoinLobby(G_002A9A20* g, int i);
void String_CtorCStr_13B480(Str_002A9A20* s, const char* c);
void func_003FD740(Str_002A9A20* s);
void String_Dtor(Str_002A9A20* s, int flags);
void String_Copy(char* d, const char* s);
void GuiSaveAgentWidget_HandleEvent(S_002A9A20* self);
}
extern "C" void func_002A9A20(S_002A9A20* self)
{
    G_002A9A20* g = DME_GetLobby();
    if (g) {
        E_002A9A20* e = LobbyArray_At(self->fA0, self->f9C);
        if (e) {
            if (SFOLobby_JoinLobby(g, self->f9C)) {
                Prof_002A9A20* pr = &Agent_GetSelected(D_004FFB50, -1)->prof;
                Str_002A9A20 s;
                String_CtorCStr_13B480(&s, e->name);
                func_003FD740(&s);
                String_Copy(pr->name, String_CStr(&s));
                pr->fC4 = e->f0;
                self->f98 = self->f9C;
                String_Dtor(&s, 0);
            } else {
                void* ui = D_004FFC04;
                FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x70, 0, 0, 0, 0), 0, 0);
                return;
            }
        }
    }
    self->b4C = 1;
    GuiSaveAgentWidget_HandleEvent(self);
}
