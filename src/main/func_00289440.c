#pragma cplusplus on
#include "types.h"
struct Str_00289440 { char d[0x10]; };
struct Txt_00289440 { char pad[0x48]; char s48[4]; };
struct Ag_00289440 { char pad[0x8CC]; char name[4]; };
struct Mgr_00289440 { char pad[0x264]; unsigned char b264; unsigned char b265; };
struct S_00289440 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void Refresh(int a);
    char pad4[0x48]; unsigned char b4C; char pad4D[0x3F]; Txt_00289440* p8C; char pad90[4]; Txt_00289440* p94; char pad98[4];
    Ag_00289440* p9C; char padA0[8]; int fA8; unsigned char bAC;
};
extern "C" {
extern Mgr_00289440* D_004FFC04;
extern char D_004A9730[];
void* DME_GetLobby(void);
char* func_0033CE30(S_00289440* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_00289440* d, int e);
char* String_CStr(void* s);
int func_00445A40(void* g, char* a, char* b);
int strcmp(const char* a, const char* b);
void String_Copy(char* d, const char* s);
char* AgentData_GetName(Ag_00289440* ag);
void func_00441C20(S_00289440* self, char* n);
void GuiSaveAgentWidget_HandleEvent(S_00289440* self);
void String_CtorCStr_13B480(Str_00289440* s, const char* c);
void func_0013D680(Str_00289440* d, Str_00289440* s);
void String_Dtor(Str_00289440* s, int flags);
int func_00452FF0(void* g, int a);
int func_002CA070(void* ui);
void FrontEnd_ClosePopup(void* ui, int id);
}
static inline int StrNe_00289440(const char* a, const char* b) { return strcmp(a, b); }
static inline void Assign_00289440(S_00289440* self, Str_00289440* d, int id)
{
    Str_00289440 t;
    String_CtorCStr_13B480(&t, func_0033CE30(self, id, 0, 0, 0, 0));
    func_0013D680(d, &t);
    String_Dtor(&t, 0);
}
extern "C" void func_00289440(S_00289440* self)
{
    void* g = DME_GetLobby();
    unsigned char ok;
    char* pw;
    if (!g)
        return;
    {
        void* ui = D_004FFC04;
        self->fA8 = FrontEnd_OpenPopup(ui, 0, D_004A9730, func_0033CE30(self, 0x1B, 0, 0, 0, 0), 0, 0);
        pw = String_CStr(self->p94->s48);
        ok = func_00445A40(g, String_CStr(self->p8C->s48), pw);
    }
    if (ok) {
        unsigned char changed;
        char* cur;
        char* n;
        self->bAC = 0;
        changed = 0;
        cur = self->p9C->name;
        if (StrNe_00289440(String_CStr(self->p94->s48), cur)) {
            String_Copy(self->p9C->name, String_CStr(self->p94->s48));
            changed = 1;
        }
        n = String_CStr(self->p8C->s48);
        if (strcmp(n, AgentData_GetName(self->p9C))) {
            func_00441C20(self, String_CStr(self->p8C->s48));
        } else {
            if (D_004FFC04->b265)
                changed = 1;
            if (changed) {
                self->b4C = 1;
                GuiSaveAgentWidget_HandleEvent(self);
            } else {
                self->Refresh(1);
            }
        }
        return;
    }
    {
        Str_00289440 a;
        Str_00289440 b;
        int kind;
        int cb;
        String_CtorCStr_13B480(&a, D_004A9730);
        String_CtorCStr_13B480(&b, D_004A9730);
        switch ((unsigned char)func_00452FF0(g, 0)) {
        case 0x3C:
            Assign_00289440(self, &a, 0x1E);
            Assign_00289440(self, &b, 0x80);
            kind = 2;
            break;
        case 0x3B:
            if (func_002CA070(D_004FFC04)) {
                Assign_00289440(self, &a, 0x1D);
                Assign_00289440(self, &b, 0x1C);
                kind = 4;
            } else {
                Assign_00289440(self, &a, 0x1D);
                Assign_00289440(self, &b, 0x8B);
                kind = 2;
            }
            break;
        case 0x3A:
            Assign_00289440(self, &a, 0x75);
            Assign_00289440(self, &b, 0x81);
            kind = 2;
            break;
        default:
            Assign_00289440(self, &a, 0x1F);
            Assign_00289440(self, &b, 0x88);
            kind = 2;
            break;
        }
        cb = kind == 4 ? 0x1F : -1;
        {
            pw = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, kind, String_CStr(&a), pw, self, cb);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->fA8);
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
        D_004FFC04->b264 = ok;
    }
}