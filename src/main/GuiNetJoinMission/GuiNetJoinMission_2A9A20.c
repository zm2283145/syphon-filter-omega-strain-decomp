/*
 * main/GuiNetJoinMission: 3 files, 002A9A20-002A9BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A9A20 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_002A9A20 */

/* merge_units: begin func_002A9B50 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; } M2A9B50;
typedef struct { char pad0[0x80]; unsigned char active; char pad81[0xA0 - 0x81]; M2A9B50 mA0; } S2A9B50;
#if 0 /* merge_units */
extern void* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((void *)DME_GetLobby()) /* merge_units */

extern void func_00442E90(void* p);
extern void LobbyArray_Free(M2A9B50* m);
void func_002A9B50(S2A9B50* s)
{
    if (s->active) {
        void* p = DME_GetLobby();
        if (p)
            func_00442E90(p);
        LobbyArray_Free(&s->mA0);
        s->active = 0;
    }
}
#undef DME_GetLobby /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A9B50 */

/* merge_units: begin func_002A9BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_002A9BA0 { char d[0x10]; };
struct W_002A9BA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct G_002A9BA0 { char pad0[0x255C]; int f255C; };
struct Prof_002A9BA0 { char pad0[0x80]; char name[0x44]; int fC4; };
struct Ag_002A9BA0 { char pad0[0x8DC]; Prof_002A9BA0 prof; };
struct Txt_002A9BA0 { char pad[0x48]; char s48[4]; };
struct List_002A9BA0 { char pad[0x94]; int f94; };
struct E_002A9BA0 { int f0; char name[4]; };
struct S_002A9BA0 {
    char pad0[0x80]; unsigned char b80; char pad81[7]; Txt_002A9BA0* p88; W_002A9BA0* p8C; List_002A9BA0* p90; char pad94[4];
    int f98; int f9C; char fA0[4]; int fA4;
};
extern "C" {
extern char* D_0048BBF8;
extern char* D_0048BBE8;
extern char D_004A7520[];
#if 0 /* merge_units */
G_002A9BA0* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((G_002A9BA0 *)DME_GetLobby()) /* merge_units */

void func_004426B0(G_002A9BA0* g);
void App_CardWaitPoll(void);
int func_00442F40(G_002A9BA0* g, void* cb, void* a);
#if 0 /* merge_units */
int func_0033CE30(S_002A9BA0* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define func_0033CE30(a0, a1, a2, a3, a4, a5) (func_0033CE30((S_002A9A20 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_002A9BA0* d, int e);
#endif /* merge_units */
#define FrontEnd_OpenPopup(a0, a1, a2, a3, a4, a5) (FrontEnd_OpenPopup((a0), (a1), (a2), (a3), (S_002A9A20 *)(a4), (a5))) /* merge_units */

void func_0041C0F0(Txt_002A9BA0* t, int a);
char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
void* GuiWidget_FindChildByName(S_002A9BA0* self, char* name);
#if 0 /* merge_units */
Ag_002A9BA0* Agent_GetSelected(void* a, int b);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((Ag_002A9BA0 *)Agent_GetSelected((a0), (a1))) /* merge_units */

char* AgentData_GetName(Ag_002A9BA0* ag);
void GuiTextListWidget_Clear(List_002A9BA0* l);
unsigned char SFOLobby_RequestLobbyList(G_002A9BA0* g);
#if 0 /* merge_units */
E_002A9BA0* LobbyArray_At(void* v, int i);
#endif /* merge_units */
#define LobbyArray_At(a0, a1) ((E_002A9BA0 *)LobbyArray_At((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void String_CtorCStr_13B480(Str_002A9BA0* s, const char* c);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str_002A9A20 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_003FD740(Str_002A9BA0* s);
#endif /* merge_units */
#define func_003FD740(a0) (func_003FD740((Str_002A9A20 *)(a0))) /* merge_units */

void GuiTextListWidget_AddItem(List_002A9BA0* l, char* s, int i, int a);
int strcmp(const char* a, const char* b);
#if 0 /* merge_units */
void String_Dtor(Str_002A9BA0* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_002A9A20 *)(a0), (a1))) /* merge_units */

void GuiArrayWidget_Select(List_002A9BA0* l, int a, int b);
}
static inline W_002A9BA0* FindAs_002A9BA0(S_002A9BA0* self, char* name, char* type)
{
    W_002A9BA0* w = (W_002A9BA0*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_002A9BA0(S_002A9BA0* self)
{
    G_002A9BA0* g;
    W_002A9BA0* w;
    Ag_002A9BA0* ag;
    Prof_002A9BA0* pr;
    char* pname;
    int key;
    if (self->b80)
        return;
    g = DME_GetLobby();
    if (g) {
        if (g->f255C == 4)
            func_004426B0(g);
        if (!func_00442F40(g, (void*)App_CardWaitPoll, self->fA0)) {
            void* ui = D_004FFC04;
            FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x72, 0, 0, 0, 0), self, 0x1E);
            return;
        }
    }
    self->b80 = 1;
    if (self->p88) {
        func_0041C0F0(self->p88, 1);
        GuiTextWidget_SetText(self->p88, Loc_LookupText("GameTitle"), 0);
    }
    w = FindAs_002A9BA0(self, D_0048BBF8, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, AgentData_GetName(Agent_GetSelected(D_004FFB50, -1)), 0);
    w = FindAs_002A9BA0(self, D_0048BBE8, D_004A7520);
    if (w && self->p88)
        GuiTextWidget_SetText(w, String_CStr(self->p88->s48), 0);
    self->f9C = -1;
    ag = Agent_GetSelected(D_004FFB50, -1);
    pr = &ag->prof;
    key = pr->fC4;
    pname = pr->name;
    if (self->p90) {
        unsigned char ok;
        GuiTextListWidget_Clear(self->p90);
        ok = SFOLobby_RequestLobbyList(g);
        if (ok) {
            int i;
            for (i = 0; i < self->fA4; i++) {
                E_002A9BA0* e = LobbyArray_At(self->fA0, i);
                if (e) {
                    Str_002A9BA0 s;
                    String_CtorCStr_13B480(&s, e->name);
                    func_003FD740(&s);
                    GuiTextListWidget_AddItem(self->p90, String_CStr(&s), i, 0);
                    if (e->f0 == key && !strcmp(String_CStr(&s), pname))
                        self->f98 = i;
                    String_Dtor(&s, 0);
                }
            }
        }
        if (!ok || !self->p90->f94) {
            void* ui = D_004FFC04;
            FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x72, 0, 0, 0, 0), self, 0x1E);
            return;
        }
    }
    if (self->f98 == -1) {
        void* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x6F, 0, 0, 0, 0), 0, 0);
        if (self->p8C)
            GuiTextWidget_SetText(self->p8C, Loc_LookupText("NotSet"), 0);
        pr->fC4 = -1;
        String_Copy(pr->name, D_004AB808);
    } else {
        if (self->p8C)
            GuiTextWidget_SetText(self->p8C, pname, 0);
        if (self->p90)
            GuiArrayWidget_Select(self->p90, 0, self->f98);
    }
    self->f9C = self->f98;
}
#undef DME_GetLobby /* merge_units */
#undef func_0033CE30 /* merge_units */
#undef FrontEnd_OpenPopup /* merge_units */
#undef Agent_GetSelected /* merge_units */
#undef LobbyArray_At /* merge_units */
#undef String_CtorCStr_13B480 /* merge_units */
#undef func_003FD740 /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A9BA0 */
