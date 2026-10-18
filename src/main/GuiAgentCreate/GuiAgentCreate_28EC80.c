/*
 * main/GuiAgentCreate: range (5 files, 0028EC80-0028F110)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028EC80 */
#pragma push /* merge_units */
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
void GuiWidget_BaseWake(void);
void GuiWidget_SendEvent(S_28EC80* a, int b, int c, int d, int e);
int Agent_GetSelected(void* a, int b);
W28EC80* GuiWidget_FindChildByName(S_28EC80* a, char* b);
char* AgentData_GetName(int a);
void GuiTextWidget_SetText(void* w, char* s, int a);
G_28EC80* Gui_GetScreenStack(void);
}
extern "C" void GuiAgentCreate_Wake(S_28EC80* self)
{
    W28EC80* p;
    D_004FFC04->b2F = 1;
    GuiWidget_BaseWake();
    if (self->f58)
        GuiWidget_SendEvent(self, self->f58, 10, 0, 0);
    p = GuiWidget_FindChildByName(self, D_004A99B0);
    p = (p && p->IsA(D_004A7520)) ? p : 0;
    if (p)
        GuiTextWidget_SetText(p, AgentData_GetName(Agent_GetSelected(D_004FFB50, -1)), 0);
    Gui_GetScreenStack()->f68 |= 0xC;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028EC80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028EC80 */

/* merge_units: begin func_0028ED60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0028ED60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x44]; void* f48;
};
struct Self_0028ED60 { char pad0[0x48]; void* f48; W_0028ED60* f4C; W_0028ED60* f50; W_0028ED60* f54; W_0028ED60* f58; W_0028ED60* f5C; };
struct Aw_0028ED60 { char pad[0xC]; unsigned char bC; char padD[3]; };
extern "C" {
extern char D_004A9BF0[];
extern Self_0028ED60* D_00506390;
extern char D_004A9988[];
extern char D_004A9870[];
extern char D_004A9990[];
extern char D_004A9C40[];
extern char D_004A9A40[];
extern char D_0055DDA0[];
void GuiWidget_Init(Self_0028ED60* self);
#if 0 /* merge_units */
void* GuiWidget_FindChildByName(Self_0028ED60* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((void *)GuiWidget_FindChildByName((S_28EC80 *)(a0), (a1))) /* merge_units */

void func_00290BC0(void);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_0028ED60* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */

void func_002888C0(Aw_0028ED60* a);
#if 0 /* merge_units */
void* Agent_GetSelected(void* a, int b);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((void *)Agent_GetSelected((a0), (a1))) /* merge_units */

void AgentData_FilterAwards(void* ag, Aw_0028ED60* a);
void AgentPartCache_Lock(void* p, Aw_0028ED60* a);
void func_002887C0(Aw_0028ED60* a, int flags);
}
static inline W_0028ED60* FindAs_0028ED60(Self_0028ED60* self, char* name, char* type)
{
    W_0028ED60* w = (W_0028ED60*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void GuiAgentCreate_Init(Self_0028ED60* self)
{
    W_0028ED60* w;
    Aw_0028ED60 a;
    GuiWidget_Init(self);
    w = FindAs_0028ED60(self, "playercharacter", D_004A9BF0);
    if (w) {
        D_00506390 = self;
        w->f48 = (void*)func_00290BC0;
    }
    self->f48 = GuiWidget_FindChildByName(self, "createagent_grp");
    self->f4C = FindAs_0028ED60(self, D_004A9988, D_004A9870);
    self->f50 = FindAs_0028ED60(self, D_004A9990, D_004A9870);
    self->f58 = FindAs_0028ED60(self, "selectindicator", D_004A9C40);
    self->f5C = FindAs_0028ED60(self, "value_slot", D_004A7520);
    self->f54 = FindAs_0028ED60(self, "beard", D_004A9870);
    if (self->f5C)
        GuiTextWidget_SetText(self->f5C, D_004A9A40, 0);
    func_002888C0(&a);
    a.bC = 1;
    AgentData_FilterAwards(Agent_GetSelected(D_004FFB50, -1), &a);
    AgentPartCache_Lock(D_0055DDA0, &a);
    func_002887C0(&a, -1);
}
#undef GuiWidget_FindChildByName /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef Agent_GetSelected /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028ED60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028ED60 */

/* merge_units: begin func_0028EFC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0028EFC0, func_002886D0)
#pragma pop /* merge_units */
/* merge_units: end func_0028EFC0 */

/* merge_units: begin func_0028F020 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_0028F020)
#pragma pop /* merge_units */
/* merge_units: end func_0028F020 */

/* merge_units: begin func_0028F110 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_0028F110)
#pragma pop /* merge_units */
/* merge_units: end func_0028F110 */
