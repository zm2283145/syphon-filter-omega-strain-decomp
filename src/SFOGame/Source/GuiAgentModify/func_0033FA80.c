/* GuiAgentModify_onInput: agent-modify screen input (save, back, part groups, part stepping);
 * same shape as GuiAgentCreate_onInput. */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* volatile type: retail re-reads ev->type in every check (no CSE across checks) */
struct Ev_0033FA80 { volatile unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct W_0033FA80 { char pad[0x14]; unsigned short flags; };
struct Pair_0033FA80 { __int128 a; __int128 b; };
struct App_0033FA80 { char pad0[0x20]; __int128 q20; char pad30[0x10]; Pair_0033FA80 pairs[1]; };
struct Act_0033FA80 { char pad[0x40]; App_0033FA80 app; };
struct Npc_0033FA80 { char pad[0x60]; char sub60[0x40]; App_0033FA80 app; };
struct Blk_0033FA80 { char d[0x440]; };
struct Info_0033FA80 { int w[63]; };
struct Self_0033FA80 {
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void v14();
    virtual void* GetFocus();
    char pad4[0x48]; unsigned char b4C; char pad4D[0x88 - 0x4D];
    W_0033FA80* f88; Npc_0033FA80* f8C; char pad90[0xEC - 0x90];
    int fEC; int fF0; char padF4[4]; int fF8; char padFC[0x144 - 0xFC];
    void* g144; void* g148; void* g14C; void* g150; void* g154; unsigned char b158;
};
extern "C" {
extern signed char D_00493A60;
extern Blk_0033FA80 D_0055D510[];
extern __int128 D_0055DE10;
extern char g_AgentPartCache[];
extern char g_Game[];
extern void* D_004FFC04;
extern char D_00585E90[];
extern char D_004B9EF8[];
extern char D_004B9F00[];
extern char D_004B9F10[];
extern char D_004B9ED0[];
extern char D_004B9EE8[];
int SKL_FindPartIndex(App_0033FA80* app, char* type);
void SKL_RemoveBlanks(Blk_0033FA80* b);
void Monster_RestoreLockedPartsTex(char* c);
void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_SetSkl(void* ag, Blk_0033FA80* b);
void* cDME_GetLobby(void);
void cGameFrontEnd_LobbySetAgentStats(void* a, Info_0033FA80* i);
void SFOLobby_UpdateStats(void* a, Info_0033FA80* i);
void GuiSaveAgentWidget_HandleEvent(Self_0033FA80* self);
char* nGlobalization_GetString_charP(char* key);
void cGameFrontEnd_PushMessageBox(void* fe, int kind, char* a, char* b, Self_0033FA80* self, int c);
void cMotionManager_FlushUpdateList(void);
void* Gui_Manager(void);
void* GuiManager_OpenGui(void* a, char* b, char* c);
void* Gui_Canvas(void);
void GuiCanvas_Transition(void* a, void* b, void* c);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void GuiCanvas_SetFocus(void* ui, void* w);
void GuiAgentModify_MakeChildrenFocusable(Self_0033FA80* self, void* g);
void GuiAgentModify_MakeChildrenNotFocusable(Self_0033FA80* self, void* g);
void GuiAgentModify_TattooPatchesLockout(Self_0033FA80* self);
void GuiAgentModify_UserInterface(Self_0033FA80* self, int a, int b);
void GuiAgentModify_SetBigPatch(Self_0033FA80* self);
int GuiAgentModify_onInput(Self_0033FA80* self, Ev_0033FA80* ev);
}

static inline void QCopy_0033FA80(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v0, -0x10(d)
        .set reorder
    }
}
static inline __int128 And_0033FA80(__int128 a, __int128 b) { __int128 r; asm { pand r, a, b } return r; }
static inline __int128 Or_0033FA80(__int128 a, __int128 b) { asm { por a, a, b } return a; }
static inline __int128 Not_0033FA80(__int128 a) { __int128 r; asm { pnor r, a, a } return r; }
static inline App_0033FA80* App_0033FA80_(char* s) { return (App_0033FA80*)(s + 0x40); }
static inline unsigned char Down_0033FA80(Ev_0033FA80* e) { unsigned char r = 0; if (e->type == 1 && !e->b2) r = 1; return r; }
static inline unsigned char Btn_0033FA80(Ev_0033FA80* e, int b) { unsigned char r = 0; if (Down_0033FA80(e) != 0 && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_0033FA80(Ev_0033FA80* e, int b) { unsigned char r = 0; if (Btn_0033FA80(e, b) != 0 && e->b6 == 0) r = 1; return r; }

extern "C" int GuiAgentModify_onInput(Self_0033FA80* self, Ev_0033FA80* ev)
{
    if (Plain_0033FA80(ev, 0x40)) {
    }
    if (Plain_0033FA80(ev, 0x80)) {
        int k = SKL_FindPartIndex(App_0033FA80_(self->f8C->sub60), D_004B9EF8);
        if (k != -1) {
            __int128 q;
            Act_0033FA80* a;
            __int128 pa;
            Npc_0033FA80* n;
            __int128 m;
            n = self->f8C;
            a = (Act_0033FA80*)n->sub60;
            m = D_0055DE10;
            q = a->app.q20;
            pa = a->app.pairs[k].a;
            a->app.q20 = Or_0033FA80(And_0033FA80(q, Not_0033FA80(m)), And_0033FA80(pa, m));
        }
        if (D_00493A60 == -1)
            D_00493A60 = 0;
        QCopy_0033FA80(&D_0055D510[D_00493A60], App_0033FA80_(self->f8C->sub60), 0x44);
        SKL_RemoveBlanks(&D_0055D510[D_00493A60]);
        Monster_RestoreLockedPartsTex(g_AgentPartCache);
        cAgentData_SetSkl(cGameSystem_GetAgentData(g_Game, -1), &D_0055D510[D_00493A60]);
        if (cDME_GetLobby()) {
            cDME_GetLobby();
            Info_0033FA80 info = *(Info_0033FA80*)D_00585E90;
            cGameFrontEnd_LobbySetAgentStats(D_004FFC04, &info);
            SFOLobby_UpdateStats(cDME_GetLobby(), &info);
        }
        self->b4C = 1;
        GuiSaveAgentWidget_HandleEvent(self);
        return 1;
    }
    if (Plain_0033FA80(ev, 0x10)) {
        if (self->b158) {
            void* fe = D_004FFC04;
            char* a = nGlobalization_GetString_charP(D_004B9F00);
            char* b = nGlobalization_GetString_charP(D_004B9F10);
            cGameFrontEnd_PushMessageBox(fe, 5, a, b, self, 0xC);
        } else {
            Monster_RestoreLockedPartsTex(g_AgentPartCache);
            cMotionManager_FlushUpdateList();
            void* pg = GuiManager_OpenGui(Gui_Manager(), D_004B9ED0, D_004B9EE8);
            GuiCanvas_Transition(Gui_Canvas(), self, pg);
        }
        return 1;
    }
    if (Plain_0033FA80(ev, 0x2000) && self->fF0) {
        GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
        if (self->fEC == 2) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g144);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 3) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g148);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            if (!self->fF8 && self->f88)
                self->f88->flags &= ~2;
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 0) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g14C);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiAgentModify_TattooPatchesLockout(self);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 1) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g150);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiAgentModify_TattooPatchesLockout(self);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        }
    }
    if (Plain_0033FA80(ev, 0x8000) && !self->fF0) {
        GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
        GuiAgentModify_MakeChildrenFocusable(self, self->g154);
        if (self->fEC == 2) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g144);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g144);
        } else if (self->fEC == 3) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g148);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g148);
        } else if (self->fEC == 0) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g14C);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g14C);
        } else if (self->fEC == 1) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g150);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g150);
        }
        GuiAgentModify_TattooPatchesLockout(self);
    }
    if (Plain_0033FA80(ev, 4)) {
        GuiAgentModify_UserInterface(self, 1, 0);
        if (!self->fF0 && self->fEC == 1)
            GuiAgentModify_SetBigPatch(self);
    }
    if (Plain_0033FA80(ev, 8)) {
        GuiAgentModify_UserInterface(self, 0, 1);
        if (!self->fF0 && self->fEC == 1)
            GuiAgentModify_SetBigPatch(self);
    }
    return 0;
}
