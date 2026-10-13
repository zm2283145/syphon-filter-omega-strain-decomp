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
extern char D_004FFB50[];
extern char D_004ABCD0[];
extern char* D_0048BCF0;
extern char D_004A7520[];
extern void* D_004FFC04;
G_002AFA80* DME_GetLobby(void);
void func_004426B0(G_002AFA80* g);
void func_002CC260(void);
int func_0044B420(G_002AFA80* g, void* cb, void* a, void* b);
Ag_002AFA80* Agent_GetSelected(void* a, int b);
void String_Copy(char* d, const char* s);
void String_CtorCStr_13B480(Str_002AFA80* s, const char* c);
void func_0013D680(Str_002AFA80* d, Str_002AFA80* s);
void func_00138B70(Str_002AFA80* s, int flags);
char* func_0044A060(G_002AFA80* g);
void func_0041BEB0(W_002AFA80* w, char* s, int a);
unsigned char func_0044A1D0(G_002AFA80* g);
int func_0033CE30(Self_002AFA80* self, int a, int b, int c, int d, int e);
void FrontEnd_OpenPopup(void* a, int b, char* c, int d, Self_002AFA80* e, int f);
void* func_0041DB80(Self_002AFA80* self, char* name);
char* Loc_LookupText(char* key);
}
static inline W_002AFA80* FindAs_002AFA80(Self_002AFA80* self, char* name, char* type)
{
    W_002AFA80* w = (W_002AFA80*)func_0041DB80(self, name);
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
extern "C" void func_002AFA80(Self_002AFA80* self)
{
    G_002AFA80* g;
    W_002AFA80* w;
    if (self->b80)
        return;
    g = DME_GetLobby();
    if (g) {
        if (g->f255C == 4)
            func_004426B0(g);
        if (func_0044B420(g, (void*)func_002CC260, self->fC8, self->fAC)) {
            char* n = g->name;
            G_002AFA80* g2;
            if (n) {
                Str_002AFA80 s;
                String_Copy(Agent_GetSelected(D_004FFB50, -1)->name, n);
                String_CtorCStr_13B480(&s, n);
                func_0013D680(&self->s174, &s);
                func_00138B70(&s, 0);
            } else {
                Str_002AFA80 s2;
                String_CtorCStr_13B480(&s2, D_004ABCD0);
                func_0013D680(&self->s174, &s2);
                func_00138B70(&s2, 0);
            }
            g2 = DME_GetLobby();
            if (g2) {
                char* t = func_0044A060(g2);
                if (self->p160)
                    func_0041BEB0(self->p160, t ? t : D_004ABCD0, 0);
            }
            self->b170 = func_0044A1D0(g);
        } else {
            void* ui = D_004FFC04;
            FrontEnd_OpenPopup(ui, 2, D_004ABCD0, func_0033CE30(self, 0x58, 0, 0, 0, 0), self, 0xF);
        }
    }
    w = FindAs_002AFA80(self, D_0048BCF0, D_004A7520);
    if (w)
        func_0041BEB0(w, Agent_GetSelected(D_004FFB50, -1)->name, 0);
    SetVis_002AFA80(self, self->p168);
    SetVis_002AFA80(self, self->p16C);
    SetVis_002AFA80(self, self->pA4);
    if (self->p164) {
        char* t = Loc_LookupText(self->b170 ? "DestroyCell" : "ResignCell");
        func_0041BEB0(self->p164, t ? t : D_004ABCD0, 0);
    }
    if (self->p88) {
        self->p88->bB4 = 1;
        self->p88->bB5 = 1;
    }
    self->b80 = 1;
}