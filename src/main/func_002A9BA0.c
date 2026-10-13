#pragma cplusplus on
#include "types.h"
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
extern void* D_004FFC04;
extern char D_004AB808[];
extern char* D_0048BBF8;
extern char* D_0048BBE8;
extern char D_004A7520[];
extern char D_004FFB50[];
G_002A9BA0* func_004294C0(void);
void func_004426B0(G_002A9BA0* g);
void func_002CC260(void);
int func_00442F40(G_002A9BA0* g, void* cb, void* a);
int func_0033CE30(S_002A9BA0* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_002A9BA0* d, int e);
void func_0041C0F0(Txt_002A9BA0* t, int a);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void* func_0041DB80(S_002A9BA0* self, char* name);
Ag_002A9BA0* Agent_GetSelected(void* a, int b);
char* func_00336170(Ag_002A9BA0* ag);
char* String_CStr(void* s);
void func_00421070(List_002A9BA0* l);
unsigned char func_00442D80(G_002A9BA0* g);
E_002A9BA0* func_0044F290(void* v, int i);
void String_CtorCStr_13B480(Str_002A9BA0* s, const char* c);
void func_003FD740(Str_002A9BA0* s);
void func_00421290(List_002A9BA0* l, char* s, int i, int a);
int strcmp(const char* a, const char* b);
void func_00138B70(Str_002A9BA0* s, int flags);
void String_Copy(char* d, const char* s);
void func_00424430(List_002A9BA0* l, int a, int b);
}
static inline W_002A9BA0* FindAs_002A9BA0(S_002A9BA0* self, char* name, char* type)
{
    W_002A9BA0* w = (W_002A9BA0*)func_0041DB80(self, name);
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
    g = func_004294C0();
    if (g) {
        if (g->f255C == 4)
            func_004426B0(g);
        if (!func_00442F40(g, (void*)func_002CC260, self->fA0)) {
            void* ui = D_004FFC04;
            FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x72, 0, 0, 0, 0), self, 0x1E);
            return;
        }
    }
    self->b80 = 1;
    if (self->p88) {
        func_0041C0F0(self->p88, 1);
        func_0041BEB0(self->p88, Loc_LookupText("GameTitle"), 0);
    }
    w = FindAs_002A9BA0(self, D_0048BBF8, D_004A7520);
    if (w)
        func_0041BEB0(w, func_00336170(Agent_GetSelected(D_004FFB50, -1)), 0);
    w = FindAs_002A9BA0(self, D_0048BBE8, D_004A7520);
    if (w && self->p88)
        func_0041BEB0(w, String_CStr(self->p88->s48), 0);
    self->f9C = -1;
    ag = Agent_GetSelected(D_004FFB50, -1);
    pr = &ag->prof;
    key = pr->fC4;
    pname = pr->name;
    if (self->p90) {
        unsigned char ok;
        func_00421070(self->p90);
        ok = func_00442D80(g);
        if (ok) {
            int i;
            for (i = 0; i < self->fA4; i++) {
                E_002A9BA0* e = func_0044F290(self->fA0, i);
                if (e) {
                    Str_002A9BA0 s;
                    String_CtorCStr_13B480(&s, e->name);
                    func_003FD740(&s);
                    func_00421290(self->p90, String_CStr(&s), i, 0);
                    if (e->f0 == key && !strcmp(String_CStr(&s), pname))
                        self->f98 = i;
                    func_00138B70(&s, 0);
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
            func_0041BEB0(self->p8C, Loc_LookupText("NotSet"), 0);
        pr->fC4 = -1;
        String_Copy(pr->name, D_004AB808);
    } else {
        if (self->p8C)
            func_0041BEB0(self->p8C, pname, 0);
        if (self->p90)
            func_00424430(self->p90, 0, self->f98);
    }
    self->f9C = self->f98;
}