#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { int f0; int count; } L_002AF040;
typedef struct { char pad0[0x1C]; L_002AF040 list; } G_002AF040;
typedef struct { int id; int f4; char pad8[0xC - 8]; String fC; char pad18[0x2C - 0x18]; String name; } E_002AF040;
typedef struct { char pad0[0x78]; unsigned char b78; char pad79[0x174 - 0x79]; String s174; } S_002AF040;
extern void* D_004FFC04;
extern char D_004ABCD0[];
extern G_002AF040* DME_GetLobby(void);
extern E_002AF040* LobbyArray_At(L_002AF040* l, int i);
extern char* String_CStr(String* s);
extern int String_CompareNoCase(String* a, char* b);
extern int GuiScreen_GetLobbyString(S_002AF040* it, int id, String* a, String* b, int c, int d);
extern void FrontEnd_OpenPopup(void* mgr, int a, char* fmt, int v, S_002AF040* it, int b);
extern void GuiScreen_PollLobby(S_002AF040* self);
void func_002AF040(S_002AF040* self)
{
    G_002AF040* g;
    int i;
    E_002AF040* e;
    L_002AF040* list;
    int n;
    if (!self->b78)
        return;
    g = DME_GetLobby();
    if (!g)
        return;
    list = &g->list;
    n = list ? list->count : 0;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(list, i);
        if (e && (e->id == 2 || e->id == 6) && !e->f4) {
            e->f4 = 1;
            if (!String_CompareNoCase(&e->name, String_CStr(&self->s174))) {
                void* mgr;
                int k;
                self->b78 = 0;
                k = e->id == 2 ? 0x2F : 0x7F;
                mgr = D_004FFC04;
                FrontEnd_OpenPopup(mgr, 2, D_004ABCD0, GuiScreen_GetLobbyString(self, k, &e->fC, &e->name, 0, 0), self, 0x17);
                return;
            }
        }
    }
    GuiScreen_PollLobby(self);
}



