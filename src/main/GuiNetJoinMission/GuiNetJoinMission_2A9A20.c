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
extern char g_Game[];
G_002A9A20* cDME_GetLobby(void);
int GuiLobbyScreen_GetLobbyString(S_002A9A20* self, int a, int b, int c, int d, int e);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, int c, S_002A9A20* d, int e);
Ag_002A9A20* cGameSystem_GetAgentData(void* a, int b);
char* std_basic_string_char_char_traits_char_c_str(void* s);
E_002A9A20* SFOLobbyList_GetSlot(void* v, int i);
int SFOLobby_RegionSelect(G_002A9A20* g, int i);
void std_basic_string_char_char_traits_char_ctor_charP(Str_002A9A20* s, const char* c);
void func_003FD740(Str_002A9A20* s);
void String_Dtor(Str_002A9A20* s, int flags);
void Libc_Strcpy(char* d, const char* s);
void GuiSaveAgentWidget_HandleEvent(S_002A9A20* self);
}
extern "C" void GuiOnlineOptions_ApplyChanges(S_002A9A20* self)
{
    G_002A9A20* g = cDME_GetLobby();
    if (g) {
        E_002A9A20* e = SFOLobbyList_GetSlot(self->fA0, self->f9C);
        if (e) {
            if (SFOLobby_RegionSelect(g, self->f9C)) {
                Prof_002A9A20* pr = &cGameSystem_GetAgentData(g_Game, -1)->prof;
                Str_002A9A20 s;
                std_basic_string_char_char_traits_char_ctor_charP(&s, e->name);
                func_003FD740(&s);
                Libc_Strcpy(pr->name, std_basic_string_char_char_traits_char_c_str(&s));
                pr->fC4 = e->f0;
                self->f98 = self->f9C;
                String_Dtor(&s, 0);
            } else {
                void* ui = D_004FFC04;
                cGameFrontEnd_PushMessageBox(ui, 2, D_004AB808, GuiLobbyScreen_GetLobbyString(self, 0x70, 0, 0, 0, 0), 0, 0);
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
extern void* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((void *)cDME_GetLobby()) /* merge_units */

extern void SFOLobby_ServerScreenExit(void* p);
extern void SFOLobbyList_ClearAndCompactList(M2A9B50* m);
void GuiOnlineOptions_Deactivate(S2A9B50* s)
{
    if (s->active) {
        void* p = cDME_GetLobby();
        if (p)
            SFOLobby_ServerScreenExit(p);
        SFOLobbyList_ClearAndCompactList(&s->mA0);
        s->active = 0;
    }
}
#undef cDME_GetLobby /* merge_units */
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
G_002A9BA0* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((G_002A9BA0 *)cDME_GetLobby()) /* merge_units */

void SFOLobby_MissionScreenExit(G_002A9BA0* g);
void cGameFrontEnd_LobbyCallback(void);
int SFOLobby_ServerScreenStart(G_002A9BA0* g, void* cb, void* a);
#if 0 /* merge_units */
int GuiLobbyScreen_GetLobbyString(S_002A9BA0* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((S_002A9A20 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, int c, S_002A9BA0* d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (S_002A9A20 *)(a4), (a5))) /* merge_units */

void GuiTextWidget_SetDisableWrap(Txt_002A9BA0* t, int a);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
void* GuiWidget_FindChild_charP(S_002A9BA0* self, char* name);
#if 0 /* merge_units */
Ag_002A9BA0* cGameSystem_GetAgentData(void* a, int b);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((Ag_002A9BA0 *)cGameSystem_GetAgentData((a0), (a1))) /* merge_units */

char* cAgentData_GetUserName(Ag_002A9BA0* ag);
void GuiTextListWidget_Clear(List_002A9BA0* l);
unsigned char SFOLobby_ServerMuisGetRegionList(G_002A9BA0* g);
#if 0 /* merge_units */
E_002A9BA0* SFOLobbyList_GetSlot(void* v, int i);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((E_002A9BA0 *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_002A9BA0* s, const char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_002A9A20 *)(a0), (a1))) /* merge_units */

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

void GuiArrayWidget_SetSelected(List_002A9BA0* l, int a, int b);
}
static inline W_002A9BA0* FindAs_002A9BA0(S_002A9BA0* self, char* name, char* type)
{
    W_002A9BA0* w = (W_002A9BA0*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void GuiOnlineOptions_Activate(S_002A9BA0* self)
{
    G_002A9BA0* g;
    W_002A9BA0* w;
    Ag_002A9BA0* ag;
    Prof_002A9BA0* pr;
    char* pname;
    int key;
    if (self->b80)
        return;
    g = cDME_GetLobby();
    if (g) {
        if (g->f255C == 4)
            SFOLobby_MissionScreenExit(g);
        if (!SFOLobby_ServerScreenStart(g, (void*)cGameFrontEnd_LobbyCallback, self->fA0)) {
            void* ui = D_004FFC04;
            cGameFrontEnd_PushMessageBox(ui, 2, D_004AB808, GuiLobbyScreen_GetLobbyString(self, 0x72, 0, 0, 0, 0), self, 0x1E);
            return;
        }
    }
    self->b80 = 1;
    if (self->p88) {
        GuiTextWidget_SetDisableWrap(self->p88, 1);
        GuiTextWidget_SetText(self->p88, nGlobalization_GetString_charP("GameTitle"), 0);
    }
    w = FindAs_002A9BA0(self, D_0048BBF8, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game, -1)), 0);
    w = FindAs_002A9BA0(self, D_0048BBE8, D_004A7520);
    if (w && self->p88)
        GuiTextWidget_SetText(w, std_basic_string_char_char_traits_char_c_str(self->p88->s48), 0);
    self->f9C = -1;
    ag = cGameSystem_GetAgentData(g_Game, -1);
    pr = &ag->prof;
    key = pr->fC4;
    pname = pr->name;
    if (self->p90) {
        unsigned char ok;
        GuiTextListWidget_Clear(self->p90);
        ok = SFOLobby_ServerMuisGetRegionList(g);
        if (ok) {
            int i;
            for (i = 0; i < self->fA4; i++) {
                E_002A9BA0* e = SFOLobbyList_GetSlot(self->fA0, i);
                if (e) {
                    Str_002A9BA0 s;
                    std_basic_string_char_char_traits_char_ctor_charP(&s, e->name);
                    func_003FD740(&s);
                    GuiTextListWidget_AddItem(self->p90, std_basic_string_char_char_traits_char_c_str(&s), i, 0);
                    if (e->f0 == key && !strcmp(std_basic_string_char_char_traits_char_c_str(&s), pname))
                        self->f98 = i;
                    String_Dtor(&s, 0);
                }
            }
        }
        if (!ok || !self->p90->f94) {
            void* ui = D_004FFC04;
            cGameFrontEnd_PushMessageBox(ui, 2, D_004AB808, GuiLobbyScreen_GetLobbyString(self, 0x72, 0, 0, 0, 0), self, 0x1E);
            return;
        }
    }
    if (self->f98 == -1) {
        void* ui = D_004FFC04;
        cGameFrontEnd_PushMessageBox(ui, 2, D_004AB808, GuiLobbyScreen_GetLobbyString(self, 0x6F, 0, 0, 0, 0), 0, 0);
        if (self->p8C)
            GuiTextWidget_SetText(self->p8C, nGlobalization_GetString_charP("NotSet"), 0);
        pr->fC4 = -1;
        Libc_Strcpy(pr->name, D_004AB808);
    } else {
        if (self->p8C)
            GuiTextWidget_SetText(self->p8C, pname, 0);
        if (self->p90)
            GuiArrayWidget_SetSelected(self->p90, 0, self->f98);
    }
    self->f9C = self->f98;
}
#undef cDME_GetLobby /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameSystem_GetAgentData /* merge_units */
#undef SFOLobbyList_GetSlot /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef func_003FD740 /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A9BA0 */
