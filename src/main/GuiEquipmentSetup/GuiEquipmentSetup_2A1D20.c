/*
 * main/GuiEquipmentSetup: range (2 files, 002A1D20-002A2170)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_002A1D20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_002A1D20 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_002A1D20 { char pad[0x20]; void* f20; };
struct S_002A1D20 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16();
    virtual void* Next(void* cur, int dir);
    char pad4[0xD8]; float fDC;
};
extern "C" {
extern void* D_004FFC04;
Ui_002A1D20* Gui_GetScreenStack(void);
void GuiWidget_SendEvent(void* a, void* b, int c, int d, int e);
void GuiScreen_SetFocus(void* ui, void* w);
char* Loc_LookupText(char* key);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_002A1D20* d, int e);
}
static inline unsigned char Down_002A1D20(Ev_002A1D20* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_002A1D20(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_002A1D20(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_002A1D20(S_002A1D20* self, Ev_002A1D20* ev)
{
    if (Press_002A1D20(ev, 0x1000))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x4000 && ev->f6 == 0;
        if (b)
            return 1;
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x8000 && ev->f6 == 0;
        if (b) {
            void* cur = Gui_GetScreenStack()->f20;
            GuiWidget_SendEvent(cur, Gui_GetScreenStack(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = Gui_GetScreenStack();
                Ui_002A1D20* u = Gui_GetScreenStack();
                GuiScreen_SetFocus(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b) {
            void* cur = Gui_GetScreenStack()->f20;
            GuiWidget_SendEvent(cur, Gui_GetScreenStack(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = Gui_GetScreenStack();
                Ui_002A1D20* u = Gui_GetScreenStack();
                GuiScreen_SetFocus(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b) {
            char* a = Loc_LookupText("QuitTitle");
            char* c = Loc_LookupText("QuitMessage");
            if (a && c)
                FrontEnd_OpenPopup(D_004FFC04, 5, a, c, self, 0);
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 2;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? -1.0f : 1.0f;
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 1;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? 1.0f : -1.0f;
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A1D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A1D20 */

/* merge_units: begin func_002A2170 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern Net_002A2170* g_LocalPlayer;
extern unsigned char g_LoadoutPending;
extern char D_0055A300[];
extern unsigned char D_005723F8;
extern unsigned char D_00572400;
extern char g_Game[];
void func_002A3A10(S_002A2170* self);
char* String_CStr(void* s);
void Pad_Reset(void* p);
void DME_SendPlayGameMsg(void);
#if 0 /* merge_units */
void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

void GuiStack_SwapScreens(void* ui, S_002A2170* self, void* pg);
G_002A2170* DME_GetLobby(void);
void GuiTextWidget_SetText(void* w, char* s, int a);
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
void Game_EndLevel(void* a, int b);
int GuiWidget_OnEvent(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text);
}
extern "C" int func_002A2170(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text)
{
    unsigned short m;
    func_002A3A10(self);
    m = msg;
    if (m == 2) {
        char* n = String_CStr(w->name);
        if (!strcmp(n, D_004AB0B0)) {
            if (g_IsMultiplayer) {
                int ok;
                w = (w && w->IsA(D_004A9870)) ? w : 0;
                if (g_IsMultiplayer)
                    ok = D_005721C0;
                else
                    ok = 1;
                if (ok) {
                    if (g_LocalPlayer->p30->GetState() == 3) {
                        if (self->fC0 == 2) {
                            g_LoadoutPending = 0;
                            Pad_Reset(D_0055A300);
                            DME_SendPlayGameMsg();
                            GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
                            g_LocalPlayer->p30->SetState(4);
                        }
                    } else if (self->fC0 > 0) {
                        g_LocalPlayer->p30->SetState(3);
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
                    g_LoadoutPending = 0;
                    Pad_Reset(D_0055A300);
                    GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
                    g_LocalPlayer->p30->SetState(4);
                } else if (g_LocalPlayer->p30->GetState() == 1) {
                    char* t;
                    g_LocalPlayer->p30->SetState(2);
                    t = Loc_LookupText("EQS_WAITING");
                    if (t)
                        GuiTextWidget_SetText(w, t, 0);
                } else {
                    char* t;
                    g_LocalPlayer->p30->SetState(1);
                    t = Loc_LookupText("EQS_EQUIP");
                    if (t)
                        GuiTextWidget_SetText(w, t, 0);
                }
            } else {
                g_LoadoutPending = 0;
                Pad_Reset(D_0055A300);
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
            }
            return 1;
        }
        if (!strcmp(n, "equipbutton")) {
            void* pg = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiEquipmentModify", "eqmodify");
            g_LocalPlayer->p30->SetState(1);
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
    }
    if (m == 0x1A && !sub) {
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
        Game_EndLevel(g_Game, 3);
        return 1;
    }
    return GuiWidget_OnEvent(self, w, msg, sub, text);
}
#undef Gui_GetScreenStack /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A2170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A2170 */
