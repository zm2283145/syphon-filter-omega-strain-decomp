#pragma cplusplus on
#include "types.h"
struct Str_002AFA80 { char d[0x10]; };
struct W_002AFA80 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x10]; unsigned short flags;
};
struct Box_002AFA80 { char pad[0xB4]; unsigned char bB4; unsigned char bB5; };
struct G_002AFA80 { char pad0[0xE8C]; char name[0x255C - 0xE8C]; int f255C; };
struct Ag_002AFA80 { char pad[0x8BC]; char name[4]; };
struct Self_002AFA80 {
    char pad0[0x80]; unsigned char b80; char pad81[7]; Box_002AFA80* p88; char pad8C[0x18]; W_002AFA80* pA4; char padA8[4];
    char fAC[0x1C]; char fC8[0x98]; W_002AFA80* p160; W_002AFA80* p164; W_002AFA80* p168; W_002AFA80* p16C; unsigned char b170; char pad171[3];
    Str_002AFA80 s174;
};
extern "C" {
extern char g_Game[];
extern char D_004ABCD0[];
extern char* D_0048BCF0;
extern char D_004A7520[];
extern void* D_004FFC04;
G_002AFA80* cDME_GetLobby(void);
void SFOLobby_MissionScreenExit(G_002AFA80* g);
void cGameFrontEnd_LobbyCallback(void);
int func_0044B420(G_002AFA80* g, void* cb, void* a, void* b);
Ag_002AFA80* cGameSystem_GetAgentData(void* a, int b);
void Libc_Strcpy(char* d, const char* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str_002AFA80* s, const char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_002AFA80* d, Str_002AFA80* s);
void String_Dtor(Str_002AFA80* s, int flags);
char* SFOLobby_CellGetMessage(G_002AFA80* g);
void GuiTextWidget_SetText(W_002AFA80* w, char* s, int a);
unsigned char SFOLobby_CellIsPlayerCellLeader(G_002AFA80* g);
int GuiLobbyScreen_GetLobbyString(Self_002AFA80* self, int a, int b, int c, int d, int e);
void cGameFrontEnd_PushMessageBox(void* a, int b, char* c, int d, Self_002AFA80* e, int f);
void* GuiWidget_FindChild_charP(Self_002AFA80* self, char* name);
char* nGlobalization_GetString_charP(char* key);
}
static inline W_002AFA80* FindAs_002AFA80(Self_002AFA80* self, char* name, char* type)
{
    W_002AFA80* w = (W_002AFA80*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void SetVis_002AFA80(Self_002AFA80* self, W_002AFA80* w)
{
    if (w) {
        if (self->b170)
            w->flags |= 4;
        else
            w->flags &= ~4;
    }
}
extern "C" void GuiNetAgencyCell_Activate(Self_002AFA80* self)
{
    G_002AFA80* g;
    W_002AFA80* w;
    if (self->b80)
        return;
    g = cDME_GetLobby();
    if (g) {
        if (g->f255C == 4)
            SFOLobby_MissionScreenExit(g);
        if (func_0044B420(g, (void*)cGameFrontEnd_LobbyCallback, self->fC8, self->fAC)) {
            char* n = g->name;
            G_002AFA80* g2;
            if (n) {
                Str_002AFA80 s;
                Libc_Strcpy(cGameSystem_GetAgentData(g_Game, -1)->name, n);
                std_basic_string_char_char_traits_char_ctor_charP(&s, n);
                std_basic_string_char_char_traits_char_assign_basicstringR(&self->s174, &s);
                String_Dtor(&s, 0);
            } else {
                Str_002AFA80 s2;
                std_basic_string_char_char_traits_char_ctor_charP(&s2, D_004ABCD0);
                std_basic_string_char_char_traits_char_assign_basicstringR(&self->s174, &s2);
                String_Dtor(&s2, 0);
            }
            g2 = cDME_GetLobby();
            if (g2) {
                char* t = SFOLobby_CellGetMessage(g2);
                if (self->p160)
                    GuiTextWidget_SetText(self->p160, t ? t : D_004ABCD0, 0);
            }
            self->b170 = SFOLobby_CellIsPlayerCellLeader(g);
        } else {
            void* ui = D_004FFC04;
            cGameFrontEnd_PushMessageBox(ui, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(self, 0x58, 0, 0, 0, 0), self, 0xF);
        }
    }
    w = FindAs_002AFA80(self, D_0048BCF0, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, cGameSystem_GetAgentData(g_Game, -1)->name, 0);
    SetVis_002AFA80(self, self->p168);
    SetVis_002AFA80(self, self->p16C);
    SetVis_002AFA80(self, self->pA4);
    if (self->p164) {
        char* t = nGlobalization_GetString_charP(self->b170 ? "DestroyCell" : "ResignCell");
        GuiTextWidget_SetText(self->p164, t ? t : D_004ABCD0, 0);
    }
    if (self->p88) {
        self->p88->bB4 = 1;
        self->p88->bB5 = 1;
    }
    self->b80 = 1;
}