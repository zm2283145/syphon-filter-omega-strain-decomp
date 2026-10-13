#pragma cplusplus on
#include "types.h"
struct W28EC80 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
};
struct Mgr_28EC80 { char pad[0x2F]; unsigned char b2F; };
struct S_28EC80 { char pad0[0x58]; int f58; };
struct G_28EC80 { char pad[0x68]; unsigned int f68; };
extern "C" {
extern Mgr_28EC80* D_004FFC04;
extern char D_004FFB50[];
extern char D_004A99B0[];
extern char D_004A7520[];
void func_0041EFA0(void);
void func_0041E0F0(S_28EC80* a, int b, int c, int d, int e);
int Agent_GetSelected(void* a, int b);
W28EC80* func_0041DB80(S_28EC80* a, char* b);
char* func_00336170(int a);
void func_0041BEB0(void* w, char* s, int a);
G_28EC80* Gui_GetScreenStack(void);
}
extern "C" void func_0028EC80(S_28EC80* self)
{
    W28EC80* p;
    D_004FFC04->b2F = 1;
    func_0041EFA0();
    if (self->f58)
        func_0041E0F0(self, self->f58, 10, 0, 0);
    p = func_0041DB80(self, D_004A99B0);
    p = (p && p->IsA(D_004A7520)) ? p : 0;
    if (p)
        func_0041BEB0(p, func_00336170(Agent_GetSelected(D_004FFB50, -1)), 0);
    Gui_GetScreenStack()->f68 |= 0xC;
}
