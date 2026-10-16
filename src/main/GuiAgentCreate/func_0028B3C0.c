#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* volatile type: retail re-reads ev->type in every check (no CSE across checks) */
struct Ev_0028B3C0 { volatile unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct W_0028B3C0 { char pad[0x14]; unsigned short flags; };
struct Npc_0028B3C0 { char pad[0x60]; char sub60[0x40]; char app[0x10]; };
struct Blk_0028B3C0 { char d[0x440]; };
struct Self_0028B3C0 {
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void v14();
    virtual void* GetFocus();
    char pad4[0x44]; void* f48; void* f4C; void* f50; W_0028B3C0* f54; char pad58[0x70 - 0x58];
    Npc_0028B3C0* f70; char pad74[0xCC - 0x74]; int fCC; int fD0; char padD4[4]; int fD8;
};
extern "C" {
extern signed char D_00493A60;
extern Blk_0028B3C0 D_0055D510[];
extern char D_004FFB50[];
extern char D_004A98E0[];
extern char D_004A98F0[];
extern char D_004A9900[];
extern char D_004A9910[];
extern char D_004A9920[];
void Appearance_RemoveBlankPairs(Blk_0028B3C0* b);
void* Agent_GetSelected(void* a, int b);
char* AgentData_GetName(void* ag);
void GuiAgentCreate_Save(Self_0028B3C0* self);
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
char* Loc_LookupText(char* key);
void GuiKeyboard_Open(void* pg, char* title, char* text, Self_0028B3C0* self, int a, int b, int c);
void* Gui_GetScreenStack(void);
void GuiStack_SwapScreens(void* a, void* b, void* c);
void GuiWidget_SendEvent(void* a, void* b, int kind, int v, int f);
void func_0028C0C0(void* p);
void func_0028BF90(void* p);
void GuiScreen_SetFocus(void* ui, void* w);
void GuiAgentCreate_StepOption(Self_0028B3C0* self, int a, int b);
int GuiAgentCreate_HandleInput(Self_0028B3C0* self, Ev_0028B3C0* ev);
}

static inline void QCopy_0028B3C0(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
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
static inline void* App_0028B3C0(char* s) { return s + 0x40; }
static inline unsigned char Down_0028B3C0(Ev_0028B3C0* e) { unsigned char r = 0; if (e->type == 1 && !e->b2) r = 1; return r; }
static inline unsigned char Btn_0028B3C0(Ev_0028B3C0* e, int b) { unsigned char r = 0; if (Down_0028B3C0(e) != 0 && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_0028B3C0(Ev_0028B3C0* e, int b) { unsigned char r = 0; if (Btn_0028B3C0(e, b) != 0 && e->b6 == 0) r = 1; return r; }

extern "C" int GuiAgentCreate_HandleInput(Self_0028B3C0* self, Ev_0028B3C0* ev)
{
    if (Plain_0028B3C0(ev, 0x40)) {
    }
    if (Plain_0028B3C0(ev, 0x80)) {
        void* ag;
        char* n;
        void* pg;
        if (D_00493A60 == -1)
            D_00493A60 = 0;
        QCopy_0028B3C0(&D_0055D510[D_00493A60], App_0028B3C0(self->f70->sub60), 0x44);
        Appearance_RemoveBlankPairs(&D_0055D510[D_00493A60]);
        ag = Agent_GetSelected(D_004FFB50, -1);
        n = AgentData_GetName(ag);
        if (!n || !*n) {
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A98E0, D_004A98F0);
            if (pg) {
                char* t = Loc_LookupText(D_004A9900);
                GuiKeyboard_Open(pg, t, AgentData_GetName(ag), self, 0xF, 2, 1);
            }
            return 1;
        }
        GuiAgentCreate_Save(self);
        return 1;
    }
    if (Plain_0028B3C0(ev, 0x10)) {
        void* pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9910, D_004A9920);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
        return 1;
    }
    if (Plain_0028B3C0(ev, 0x2000) && self->fD0) {
        if (self->fCC != 0 && self->fCC != 1)
            GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 0, 0);
        if (self->fCC == 2) {
            func_0028C0C0(self->f4C);
            func_0028BF90(self->f48);
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->GetFocus());
        } else if (self->fCC == 3) {
            func_0028C0C0(self->f50);
            func_0028BF90(self->f48);
            if (!self->fD8 && self->f54)
                self->f54->flags &= ~2;
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->GetFocus());
        } else if (self->fCC == 4) {
            void* ag = Agent_GetSelected(D_004FFB50, -1);
            void* pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A98E0, D_004A98F0);
            if (pg) {
                char* t = Loc_LookupText(D_004A9900);
                GuiKeyboard_Open(pg, t, AgentData_GetName(ag), self, 0xF, 1, 1);
            }
        }
    }
    if (Plain_0028B3C0(ev, 0x8000) && !self->fD0) {
        GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 0, 0);
        func_0028C0C0(self->f48);
        if (self->fCC == 2) {
            func_0028BF90(self->f4C);
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->f4C);
        } else {
            func_0028BF90(self->f50);
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->f50);
        }
    }
    if (Plain_0028B3C0(ev, 4))
        GuiAgentCreate_StepOption(self, 1, 0);
    if (Plain_0028B3C0(ev, 8))
        GuiAgentCreate_StepOption(self, 0, 1);
    return 0;
}
