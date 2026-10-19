/*
 * main/GuiAgentCreate: range (3 files, 0028BA90-0028BF90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "child_list_iter.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_0028BA90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Look { char pad[0x440]; } __attribute__((aligned(16)));
struct Prof { char pad0[0x40]; Look look; };
/* quad copy loop idiom as in src\main\LightMgr_RemoveFromTable.c (retail uses a hand-written addi) */
static inline void QMoveP(void* d, Prof* p, int n) {
    void* ss = &p->look;
    int nn = n;
    void* dd = d;
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}

struct Data { char pad0[0x60]; Prof prof; };
struct Screen { char pad0[0x70]; Data* data; };
struct Agent {
    char pad0[0x8DC]; unsigned char b8DC; char pad8DD[0x91C - 0x8DD];
    unsigned char b91C; char pad91D[0x95C - 0x91D];
    unsigned char b95C; char pad95D[0x99C - 0x95D];
    int i99C; int i9A0;
};
struct Cfg { char pad[0x59D]; unsigned char b59D; };
struct Holder { Cfg* cfg; };
extern "C" {
extern char D_004A9930[], D_004A9940[], D_004A9950[], D_004A9960[];
extern char g_Game[];
extern int D_004FFC04;
extern Holder g_MemCard;
extern char g_AgentPartCache[];
void Appearance_RemoveBlankPairs(Look* l);
void AgentPartCache_Unlock(void* p);
Agent* Agent_GetSelected(void* p, int i);
void AgentData_StoreAppearance(Agent* a, Look* l);
int Gui_GetScreenList(void);
int Gui_GetScreenStack(void);
int GuiManager_FindOrLoad(int list, char* a, char* b);
void GuiStack_SwapScreens(int stack, Screen* s, int n);
int Loc_LookupText(char* s);
void FrontEnd_OpenPopup(int a, int b, int t1, int t2, Screen* s, int c);
}
/* opt_propagation off + the Holder* local keep the lui/addiu/lw 0 form for g_MemCard. */
#pragma opt_propagation off
extern "C" void GuiAgentCreate_Save(Screen* self)
{
    Look look;
    QMoveP(&look, &self->data->prof, 0x44);
    Appearance_RemoveBlankPairs(&look);
    AgentPartCache_Unlock(g_AgentPartCache);
    {
        Agent* a = Agent_GetSelected(g_Game, -1);
        a->b8DC = 0;
        a->b91C = 0;
        a->i99C = -1;
        a->b95C = 0;
        a->i9A0 = -1;
    }
    AgentData_StoreAppearance(Agent_GetSelected(g_Game, -1), &look);
    Holder* h = &g_MemCard;
    if (h->cfg->b59D) {
        int n = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9930, D_004A9940);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, n);
    } else {
        int p = D_004FFC04;
        int t1 = Loc_LookupText(D_004A9950);
        FrontEnd_OpenPopup(p, 4, t1, Loc_LookupText(D_004A9960), self, 3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028BA90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028BA90 */

/* merge_units: begin func_0028BBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0028BBE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x10]; unsigned short flags;
};
struct Src_0028BBE0 { char pad[4]; char name[4]; };
struct Ui_0028BBE0 { char pad[0x2E]; unsigned char b2E; };
struct Self_0028BBE0 {
    char pad0[0x4C]; void* f4C; void* f50; W_0028BBE0* f54; char pad58[0xCC - 0x58]; int fCC; int fD0; char padD4[4]; int fD8;
};
extern "C" {
extern char D_004A7520[];
extern unsigned char D_004FFBB8;
extern int g_CardSlotId;
#if 0 /* merge_units */
extern Ui_0028BBE0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Ui_0028BBE0 **)&D_004FFC04) /* merge_units */

char* String_CStr(void* s);
void GuiAgentCreate_SelectOption(Self_0028BBE0* self, char* n);
void GuiAgentCreate_SleepChildren(void* p);
void GuiAgentCreate_Randomize(Self_0028BBE0* self, int a, int b);
void GuiAgentCreate_WakeChildren(Src_0028BBE0* w);
#if 0 /* merge_units */
void* Agent_GetSelected(void* a, int b);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((void *)Agent_GetSelected((a0), (a1))) /* merge_units */

void AgentData_SetName(void* ag, char* text);
void* GuiWidget_FindChildByName(Self_0028BBE0* self, char* name);
void GuiTextWidget_SetText(W_0028BBE0* w, char* s, int a);
#if 0 /* merge_units */
void GuiAgentCreate_Save(Self_0028BBE0* self);
#endif /* merge_units */
#define GuiAgentCreate_Save(a0) (GuiAgentCreate_Save((Screen *)(a0))) /* merge_units */

#if 0 /* merge_units */
void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

void GuiScreen_SetFocus(void* ui, void* w);
void AgentData_Create(void* ag, int a, int b);
#if 0 /* merge_units */
void* Gui_GetScreenList(void);
#endif /* merge_units */
#define Gui_GetScreenList() ((void *)Gui_GetScreenList()) /* merge_units */

#if 0 /* merge_units */
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((void *)GuiManager_FindOrLoad((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void GuiStack_SwapScreens(void* ui, Self_0028BBE0* self, void* pg);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((int)(a0), (Screen *)(a1), (int)(a2))) /* merge_units */

int GuiWidget_OnEvent(Self_0028BBE0* self, Src_0028BBE0* w, int msg, int sub, char* text);
}
static inline W_0028BBE0* FindAs_0028BBE0(Self_0028BBE0* self, char* name, char* type)
{
    W_0028BBE0* w = (W_0028BBE0*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" int GuiAgentCreate_HandleEvent(Self_0028BBE0* self, Src_0028BBE0* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x10 && sub == 1)
        return 1;
    if (m == 0) {
        char* n;
        self->fD0 = 0;
        n = String_CStr(w->name);
        GuiAgentCreate_SelectOption(self, n);
        if (!strcmp(n, "gender")) {
            self->fCC = 0;
            self->fD0 = 1;
        }
        if (!strcmp(n, "randomize")) {
            GuiAgentCreate_SleepChildren(self->f4C);
            self->fCC = 1;
            self->fD0 = 1;
            GuiAgentCreate_Randomize(self, 1, 0);
        }
        if (!strcmp(n, "body")) {
            GuiAgentCreate_WakeChildren(w);
            GuiAgentCreate_SleepChildren(self->f50);
            self->fCC = 2;
            self->fD0 = 1;
        }
        if (!strcmp(n, "head")) {
            GuiAgentCreate_WakeChildren(w);
            GuiAgentCreate_SleepChildren(self->f4C);
            if (!self->fD8 && self->f54)
                self->f54->flags &= ~2;
            self->fCC = 3;
            self->fD0 = 1;
        }
        if (!strcmp(n, "agentname")) {
            GuiAgentCreate_SleepChildren(self->f50);
            self->fCC = 4;
            self->fD0 = 1;
        }
    }
    if (m == 0x1A) {
        if (sub == 1 || sub == 2) {
            W_0028BBE0* x;
            if (text && *text) {
                W_0028BBE0* t;
                AgentData_SetName(Agent_GetSelected(g_Game, -1), text);
                t = FindAs_0028BBE0(self, "value_agent_name", D_004A7520);
                if (t)
                    GuiTextWidget_SetText(t, text, 0);
            }
            if (sub == 2 && text && *text) {
                GuiAgentCreate_Save(self);
                return 1;
            }
            x = (W_0028BBE0*)GuiWidget_FindChildByName(self, "agentname");
            if (x)
                GuiScreen_SetFocus(Gui_GetScreenStack(), x);
            return 1;
        } else if (sub == 3) {
            void* pg;
            D_004FFBB8 = 0;
            g_CardSlotId = -1;
            AgentData_Create(Agent_GetSelected(g_Game, -1), 0, 1);
            if (D_004FFC04->b2E)
                pg = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "CMDCENTR");
            else
                pg = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "onoffsel");
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
        }
    }
    return GuiWidget_OnEvent(self, w, msg, sub, text);
}
#undef D_004FFC04 /* merge_units */
#undef Agent_GetSelected /* merge_units */
#undef GuiAgentCreate_Save /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef Gui_GetScreenList /* merge_units */
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028BBE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028BBE0 */

/* merge_units: begin func_0028BF90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Clear flag 0x80 on every other child of the given type. */
extern "C" {
extern char D_004A9870[];
void func_0028BF90(ChildWidget* o);
}
static inline ChildWidget* cast28BF90(ChildWidget* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void func_0028BF90(ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (cast28BF90(c)) n->obj->flags &= ~0x80;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028BF90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028BF90 */
