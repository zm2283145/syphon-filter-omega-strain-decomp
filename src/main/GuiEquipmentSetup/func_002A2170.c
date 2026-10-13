#pragma cplusplus on
#include "types.h"
struct W_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char name[4];
};
struct St_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual void SetState(int s); virtual unsigned char GetState();
};
struct Net_002A2170 { char pad[0x30]; St_002A2170* p30; };
struct G_002A2170 { char pad[0x26A0]; unsigned char b26A0; };
struct S_002A2170 { char pad0[0xC0]; int fC0; char padC4[0x14]; unsigned char bD8; };
extern "C" {
extern char D_004AB0B0[];
extern char D_004A9870[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern Net_002A2170* D_004FFC0C;
extern unsigned char D_004FFC29;
extern char D_0055A300[];
extern unsigned char D_005723F8;
extern unsigned char D_00572400;
extern char D_004FFB50[];
void func_002A3A10(S_002A2170* self);
char* String_CStr(void* s);
int strcmp(const char* a, const char* b);
void Pad_Reset(void* p);
void DME_SendPlayGameMsg(void);
void* Gui_GetScreenStack(void);
void GuiStack_SwapScreens(void* ui, S_002A2170* self, void* pg);
G_002A2170* DME_GetLobby(void);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void* Gui_GetScreenList(void);
void* func_00418A80(void* a, char* b, char* c);
void Game_EndLevel(void* a, int b);
int func_0041EF10(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text);
}
extern "C" int func_002A2170(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text)
{
    unsigned short m;
    func_002A3A10(self);
    m = msg;
    if (m == 2) {
        char* n = String_CStr(w->name);
        if (!strcmp(n, D_004AB0B0)) {
            if (D_005721C8) {
                int ok;
                w = (w && w->IsA(D_004A9870)) ? w : 0;
                if (D_005721C8)
                    ok = D_005721C0;
                else
                    ok = 1;
                if (ok) {
                    if (D_004FFC0C->p30->GetState() == 3) {
                        if (self->fC0 == 2) {
                            D_004FFC29 = 0;
                            Pad_Reset(D_0055A300);
                            DME_SendPlayGameMsg();
                            GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
                            D_004FFC0C->p30->SetState(4);
                        }
                    } else if (self->fC0 > 0) {
                        D_004FFC0C->p30->SetState(3);
                        D_005723F8 = 1;
                        if (!self->bD8) {
                            G_002A2170* g;
                            self->bD8 = 1;
                            g = DME_GetLobby();
                            if (g)
                                g->b26A0 = 1;
                        }
                    }
                } else if (D_00572400) {
                    D_004FFC29 = 0;
                    Pad_Reset(D_0055A300);
                    GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
                    D_004FFC0C->p30->SetState(4);
                } else if (D_004FFC0C->p30->GetState() == 1) {
                    char* t;
                    D_004FFC0C->p30->SetState(2);
                    t = Loc_LookupText("EQS_WAITING");
                    if (t)
                        func_0041BEB0(w, t, 0);
                } else {
                    char* t;
                    D_004FFC0C->p30->SetState(1);
                    t = Loc_LookupText("EQS_EQUIP");
                    if (t)
                        func_0041BEB0(w, t, 0);
                }
            } else {
                D_004FFC29 = 0;
                Pad_Reset(D_0055A300);
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
            }
            return 1;
        }
        if (!strcmp(n, "equipbutton")) {
            void* pg = func_00418A80(Gui_GetScreenList(), "GuiEquipmentModify", "eqmodify");
            D_004FFC0C->p30->SetState(1);
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
    }
    if (m == 0x1A && !sub) {
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
        Game_EndLevel(D_004FFB50, 3);
        return 1;
    }
    return func_0041EF10(self, w, msg, sub, text);
}