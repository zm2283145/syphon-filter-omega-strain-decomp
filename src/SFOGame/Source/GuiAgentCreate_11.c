/*
 * SFOGame/Source/GuiAgentCreate: 10 files, 0028E640-0028F200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028E640 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)

/* Camera preset blend: eases the current camera preset toward the selected table entry. */

extern "C" {
float BlendFloat(float* p, float a, float b);
float BlendRot(float target, float cur, float* maxStep);
}
struct Fl { float v; Fl& operator=(const Fl& o) { v = o.v; return *this; } operator float() const { return v; } Fl& operator=(float x) { v = x; return *this; } };
struct CamE {
    char name[16];
    int id;
    Fl f0, f1, f2, f3, f4, f5, f6;
};
struct CamMgr { char pad[0x11C10]; CamE e[1]; };
extern "C" CamMgr g_AgentPartCache;
struct CamOwner { char pad[0x2E10]; signed char sel[8]; };
struct CamT {
    char pad0[0x70];
    CamOwner* owner;
    char pad74[0x80 - 0x74];
    CamE cur;
    char padB0[0xC0 - 0xB0];
    int c0;
    char padC4[0xD0 - 0xC4];
    int d0;
    char padD4[0xED - 0xD4];
    signed char ed;
};
static inline void GetE(CamT* t, CamE& o) {
    if (t->d0 == 0) o = g_AgentPartCache.e[t->owner->sel[t->ed]];
    else o = g_AgentPartCache.e[0];
}

extern "C" void GuiAgentCreate_BlendMenOnOff(CamT* t)
{
    if (t->c0) {
        float acc = 0.0f;
        CamE e; GetE(t, e);
        t->cur.f0 = BlendFloat(&acc, e.f0, t->cur.f0);
        t->cur.f1 = BlendFloat(&acc, e.f1, t->cur.f1);
        t->cur.f2 = BlendFloat(&acc, e.f2, t->cur.f2);
        t->cur.f3 = BlendFloat(&acc, e.f3, t->cur.f3);
        t->cur.f4 = BlendRot(e.f4, t->cur.f4, &acc);
        t->cur.f5 = BlendRot(e.f5, t->cur.f5, &acc);
        t->cur.f6 = BlendRot(e.f6, t->cur.f6, &acc);
        t->c0++;
        if (acc < 0.0001f) {
            t->c0 = 0;
            GetE(t, t->cur);
        }
    }
}
static inline void merge_flush_func_0028E640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028E640 */

/* merge_units: begin func_0028EA40 */
#pragma push /* merge_units */
extern int g_Pad0HeldMask;
extern unsigned char D_004FFBB8;

typedef struct {
    char pad0[0x59D];
    unsigned char flag;
} Game59D;
extern Game59D *g_MemCard;

typedef struct {
    char pad0[0xAC];
    float angle;
    char padD0[0xC0 - 0xB0];
    int locked;
} Obj;

void GuiWidget_onAdvanceTime(Obj *o, float dt);

#pragma push
#pragma opt_propagation off
void GuiAgentCreate_onAdvanceTime(Obj *o, float dt)
{
    int flags;
    float step;
    GuiWidget_onAdvanceTime(o, dt);
    flags = g_Pad0HeldMask;
    step = 3.1415927f * (dt / 30.0f);
    if (o->locked == 0) {
        if (flags & 1) {
            o->angle += step;
            if (o->angle > 3.1415927f) {
                o->angle -= 6.2831855f;
            }
        }
        if (flags & 2) {
            o->angle -= step;
            if (o->angle < -3.1415927f) {
                o->angle += 6.2831855f;
            }
        }
    }
    D_004FFBB8 = g_MemCard->flag != 0;
}
#pragma pop
static inline void merge_flush_func_0028EA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028EA40 */

/* merge_units: begin func_0028EB40 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
void GuiAgentCreate_UserInterfaceRotate(Obj *o, float dt)
{
    int flags = g_Pad0HeldMask;
    float step = 3.1415927f * (dt / 30.0f);
    if (o->locked == 0) {
        if (flags & 1) {
            o->angle += step;
            if (o->angle > 3.1415927f) {
                o->angle -= 6.2831855f;
            }
        }
        if (flags & 2) {
            o->angle -= step;
            if (o->angle < -3.1415927f) {
                o->angle += 6.2831855f;
            }
        }
    }
}
#pragma pop
static inline void merge_flush_func_0028EB40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028EB40 */

/* merge_units: begin func_0028EC00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentCreate.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiAgentCreate_types.h"

#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

extern int Monster_RestoreLockedPartsTex(void* p);
extern void cMotionManager_FlushUpdateList(void);
extern GuiManagerState* Gui_Canvas(void);
extern int GuiWidget_onSleep(void* self);
extern int GuiWidget_onRemove(void* self);

int GuiAgentCreate_onRemove(void* self) {
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    return GuiWidget_onRemove(self);
}

/* Calls the base handler, then clears bits 2-3 of the gui manager flags. */
GuiManagerState* GuiAgentCreate_onSleep(void* self) {
    GuiManagerState* gui;

    GuiWidget_onSleep(self);
    gui = Gui_Canvas();
    gui->flags &= ~12;
    return gui;
}
#undef g_AgentPartCache /* merge_units */
static inline void merge_flush_func_0028EC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028EC00 */

/* merge_units: begin func_0028EC80 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern char g_Game[];
extern char D_004A99B0[];
extern char D_004A7520[];
void GuiWidget_onWake(void);
void GuiWidget_SendMessage(S_28EC80* a, int b, int c, int d, int e);
int cGameSystem_GetAgentData(void* a, int b);
W28EC80* GuiWidget_FindChild_charP(S_28EC80* a, char* b);
char* cAgentData_GetUserName(int a);
void GuiTextWidget_SetText(void* w, char* s, int a);
#if 0 /* merge_units */
G_28EC80* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((G_28EC80 *)Gui_Canvas()) /* merge_units */

}
extern "C" void GuiAgentCreate_onWake(S_28EC80* self)
{
    W28EC80* p;
    D_004FFC04->b2F = 1;
    GuiWidget_onWake();
    if (self->f58)
        GuiWidget_SendMessage(self, self->f58, 10, 0, 0);
    p = GuiWidget_FindChild_charP(self, D_004A99B0);
    p = (p && p->IsA(D_004A7520)) ? p : 0;
    if (p)
        GuiTextWidget_SetText(p, cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game, -1)), 0);
    Gui_Canvas()->f68 |= 0xC;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028EC80(void) {}
#undef Gui_Canvas /* merge_units */
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
#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

void GuiWidget_onAdd(Self_0028ED60* self);
#if 0 /* merge_units */
void* GuiWidget_FindChild_charP(Self_0028ED60* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((void *)GuiWidget_FindChild_charP((S_28EC80 *)(a0), (a1))) /* merge_units */


void ManRenderWrapper(void);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_0028ED60* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */


void std_vector_charPtr_ctor_void_2(Aw_0028ED60* a);
#if 0 /* merge_units */
void* cGameSystem_GetAgentData(void* a, int b);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((void *)cGameSystem_GetAgentData((a0), (a1))) /* merge_units */


void cAgentData_GetLockedParts_cArrayP(void* ag, Aw_0028ED60* a);
void Monster_HideLockedPartsTex(void* p, Aw_0028ED60* a);
void std_vector_charPtr_dtor_void_2(Aw_0028ED60* a, int flags);
}
static inline W_0028ED60* FindAs_0028ED60(Self_0028ED60* self, char* name, char* type)
{
    W_0028ED60* w = (W_0028ED60*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void GuiAgentCreate_onAdd(Self_0028ED60* self)
{
    W_0028ED60* w;
    Aw_0028ED60 a;
    GuiWidget_onAdd(self);
    w = FindAs_0028ED60(self, "playercharacter", D_004A9BF0);
    if (w) {
        D_00506390 = self;
        w->f48 = (void*)ManRenderWrapper;
    }
    self->f48 = GuiWidget_FindChild_charP(self, "createagent_grp");
    self->f4C = FindAs_0028ED60(self, D_004A9988, D_004A9870);
    self->f50 = FindAs_0028ED60(self, D_004A9990, D_004A9870);
    self->f58 = FindAs_0028ED60(self, "selectindicator", D_004A9C40);
    self->f5C = FindAs_0028ED60(self, "value_slot", D_004A7520);
    self->f54 = FindAs_0028ED60(self, "beard", D_004A9870);
    if (self->f5C)
        GuiTextWidget_SetText(self->f5C, D_004A9A40, 0);
    std_vector_charPtr_ctor_void_2(&a);
    a.bC = 1;
    cAgentData_GetLockedParts_cArrayP(cGameSystem_GetAgentData(g_Game, -1), &a);
    Monster_HideLockedPartsTex(g_AgentPartCache, &a);
    std_vector_charPtr_dtor_void_2(&a, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028ED60(void) {}
#undef g_AgentPartCache /* merge_units */
#undef GuiWidget_FindChild_charP /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef cGameSystem_GetAgentData /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028ED60 */

/* merge_units: begin func_0028EFC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0028EFC0, std_vector_imp_charPtr_1_dtor_void_2)
static inline void merge_flush_func_0028EFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028EFC0 */

/* merge_units: begin func_0028F020 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_0028F020)
static inline void merge_flush_func_0028F020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028F020 */

/* merge_units: begin func_0028F110 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_0028F110)
static inline void merge_flush_func_0028F110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028F110 */

/* merge_units: begin func_0028F200 */
#pragma push /* merge_units */
Rel* func_0028F200(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0028F200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028F200 */
