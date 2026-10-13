#pragma cplusplus on
#include "types.h"
struct Str_002891D0 { char d[0x10]; };
struct Pg_002891D0 { char pad[0x10]; int f10; unsigned short flags; };
struct Ui_002891D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(void* p, int a); virtual void Hide(void* p);
};
struct Mgr_002891D0 { char pad[0x264]; unsigned char b264; };
struct S_002891D0 { char pad0[0x98]; void* p98; char pad9C[4]; void* pA0; char padA4[4]; int fA8; unsigned char bAC; unsigned char bAD; };
extern "C" {
extern Mgr_002891D0* D_004FFC04;
extern char D_004A96F8[];
extern char D_004A9718[];
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void* DME_GetLobby(void);
void func_002CA160(void* ui);
void func_002CC260(void);
int func_00442750(void* g, void* cb);
char* func_0033CE30(S_002891D0* self, int a, int b, int c, int d, int e);
void String_CtorCStr_13B480(Str_002891D0* s, const char* c);
char* String_CStr(Str_002891D0* s);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_002891D0* d, int e);
void FrontEnd_ClosePopup(void* ui, int id);
void String_Dtor(Str_002891D0* s, int flags);
void* Gui_GetScreenList(void);
Pg_002891D0* GuiManager_FindOrLoad(void* a, char* b, char* c);
Pg_002891D0* GuiManager_FindByName(void* a, char* b);
Ui_002891D0* Gui_GetScreenStack(void);
void func_0041E0F0(void* a, void* b, int c, int d, int e);
}
extern "C" void func_002891D0(S_002891D0* self)
{
    void* g;
    unsigned char ok;
    if (self->bAC) {
        if (self->pA0)
            func_0041BEB0(self->pA0, Loc_LookupText(D_004A96F8), 0);
        if (self->p98)
            func_0041BEB0(self->p98, Loc_LookupText(D_004A9718), 0);
        self->bAD = 0;
        return;
    }
    g = DME_GetLobby();
    if (!g)
        return;
    ok = 1;
    func_002CA160(D_004FFC04);
    if (!func_00442750(g, (void*)func_002CC260)) {
        Str_002891D0 a;
        Str_002891D0 b;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 0x1F, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x88, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, self, 0x1E);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->fA8);
        ok = 0;
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    } else {
        Pg_002891D0* p = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "CMDCENTR");
        if (p) {
            p->f10 = 1;
            p->flags &= ~2;
            Gui_GetScreenStack()->Show(p, 0);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->fA8);
    }
    D_004FFC04->b264 = ok;
    if (ok) {
        Pg_002891D0* q;
        Gui_GetScreenStack()->Hide(self);
        q = GuiManager_FindByName(Gui_GetScreenList(), "GuiCommandCenter");
        if (q) {
            q->flags |= 2;
            func_0041E0F0(q, Gui_GetScreenStack(), 0x10, 2, 0);
        }
    }
}