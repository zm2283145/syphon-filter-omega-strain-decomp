#pragma cplusplus on
#include "types.h"
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
extern char D_004FFB50[];
extern unsigned char D_004FFBB8;
extern int D_004FFBBC;
extern Ui_0028BBE0* D_004FFC04;
char* String_CStr(void* s);
void func_0028D610(Self_0028BBE0* self, char* n);
int strcmp(const char* a, const char* b);
void func_0028C1D0(void* p);
void func_0028CB20(Self_0028BBE0* self, int a, int b);
void func_0028C2A0(Src_0028BBE0* w);
void* Agent_GetSelected(void* a, int b);
void AgentData_SetName(void* ag, char* text);
void* func_0041DB80(Self_0028BBE0* self, char* name);
void func_0041BEB0(W_0028BBE0* w, char* s, int a);
void func_0028BA90(Self_0028BBE0* self);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* ui, void* w);
void AgentData_Create(void* ag, int a, int b);
void* Gui_GetScreenList(void);
void* func_00418A80(void* a, char* b, char* c);
void GuiStack_SwapScreens(void* ui, Self_0028BBE0* self, void* pg);
int func_0041EF10(Self_0028BBE0* self, Src_0028BBE0* w, int msg, int sub, char* text);
}
static inline W_0028BBE0* FindAs_0028BBE0(Self_0028BBE0* self, char* name, char* type)
{
    W_0028BBE0* w = (W_0028BBE0*)func_0041DB80(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" int func_0028BBE0(Self_0028BBE0* self, Src_0028BBE0* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x10 && sub == 1)
        return 1;
    if (m == 0) {
        char* n;
        self->fD0 = 0;
        n = String_CStr(w->name);
        func_0028D610(self, n);
        if (!strcmp(n, "gender")) {
            self->fCC = 0;
            self->fD0 = 1;
        }
        if (!strcmp(n, "randomize")) {
            func_0028C1D0(self->f4C);
            self->fCC = 1;
            self->fD0 = 1;
            func_0028CB20(self, 1, 0);
        }
        if (!strcmp(n, "body")) {
            func_0028C2A0(w);
            func_0028C1D0(self->f50);
            self->fCC = 2;
            self->fD0 = 1;
        }
        if (!strcmp(n, "head")) {
            func_0028C2A0(w);
            func_0028C1D0(self->f4C);
            if (!self->fD8 && self->f54)
                self->f54->flags &= ~2;
            self->fCC = 3;
            self->fD0 = 1;
        }
        if (!strcmp(n, "agentname")) {
            func_0028C1D0(self->f50);
            self->fCC = 4;
            self->fD0 = 1;
        }
    }
    if (m == 0x1A) {
        if (sub == 1 || sub == 2) {
            W_0028BBE0* x;
            if (text && *text) {
                W_0028BBE0* t;
                AgentData_SetName(Agent_GetSelected(D_004FFB50, -1), text);
                t = FindAs_0028BBE0(self, "value_agent_name", D_004A7520);
                if (t)
                    func_0041BEB0(t, text, 0);
            }
            if (sub == 2 && text && *text) {
                func_0028BA90(self);
                return 1;
            }
            x = (W_0028BBE0*)func_0041DB80(self, "agentname");
            if (x)
                GuiScreen_SetFocus(Gui_GetScreenStack(), x);
            return 1;
        } else if (sub == 3) {
            void* pg;
            D_004FFBB8 = 0;
            D_004FFBBC = -1;
            AgentData_Create(Agent_GetSelected(D_004FFB50, -1), 0, 1);
            if (D_004FFC04->b2E)
                pg = func_00418A80(Gui_GetScreenList(), "GuiCommandCenter", "CMDCENTR");
            else
                pg = func_00418A80(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "onoffsel");
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
        }
    }
    return func_0041EF10(self, w, msg, sub, text);
}