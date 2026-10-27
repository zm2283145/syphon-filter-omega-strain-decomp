/*
 * SFOGame/Source/GuiAgentModify: 7 files, 003428D0-00342F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003428D0 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on
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
    char pad0[0x8C];
    CamOwner* owner;
    char pad90[0xA0 - 0x90];
    CamE cur;
    char padD0[0xE0 - 0xD0];
    int c0;
    char padE4[0xF0 - 0xE4];
    int d0;
    char padF4[0x10D - 0xF4];
    signed char ed;
};
static inline void GetE(CamT* t, CamE& o) {
    if (t->d0 == 0) o = g_AgentPartCache.e[t->owner->sel[t->ed]];
    else o = g_AgentPartCache.e[0];
}

extern "C" void GuiAgentModify_BlendMenOnOff(CamT* t)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003428D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003428D0 */

/* merge_units: begin func_00342CD0 */
#pragma push /* merge_units */
extern int g_Pad0HeldMask;

typedef struct {
    char pad0[0xCC];
    float angle;
    char padD0[0xE0 - 0xD0];
    int locked;
} Obj;

void GuiWidget_onAdvanceTime(Obj *o, float dt);

#pragma push
#pragma opt_propagation off
void GuiAgentModify_onAdvanceTime(Obj *o, float dt)
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
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00342CD0 */

/* merge_units: begin func_00342DC0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
void GuiAgentModify_UserInterfaceRotate(Obj *o, float dt)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00342DC0 */

/* merge_units: begin func_00342E80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiAgentModify_types.h"

#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

extern int Monster_RestoreLockedPartsTex(void* p);
extern void cMotionManager_FlushUpdateList(void);
extern GuiManagerState* Gui_Canvas(void);
extern int GuiWidget_onSleep(void* self);
extern int GuiWidget_onRemove(void* self);

int GuiAgentModify_onRemove(void* self) {
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    return GuiWidget_onRemove(self);
}

/* Calls the base handler, then clears bits 2-3 of the gui manager flags. */
GuiManagerState* GuiAgentModify_onSleep(void* self) {
    GuiManagerState* gui;

    GuiWidget_onSleep(self);
    gui = Gui_Canvas();
    gui->flags &= ~12;
    return gui;
}
#undef g_AgentPartCache /* merge_units */
static inline void merge_flush_func_00342E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00342E80 */

/* merge_units: begin func_00342F00 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short a14; } W342F00;
typedef struct { char pad[0x78]; W342F00* a78; char pad7C[0xDC]; unsigned char a158; } S342F00;
typedef struct { char pad[0x2F]; unsigned char a2F; } G342F00;
typedef struct { char pad[0x68]; unsigned int a68; } M342F00;
typedef struct { char pad[0xB68]; unsigned char aB68; char padB69[9]; unsigned char aB72; } A342F00;
extern G342F00* D_004FFC04;
extern char g_Game[];
extern void GuiWidget_onWake(S342F00* o);
extern void GuiWidget_SendMessage(void* self, void* w, int a, int b, int c);
#if 0 /* merge_units */
extern M342F00* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((M342F00 *)Gui_Canvas()) /* merge_units */

extern A342F00* cGameSystem_GetAgentData(void* list, int idx);
void GuiAgentModify_onWake(S342F00* o)
{
    M342F00* m;
    A342F00* ag;
    D_004FFC04->a2F = 1;
    GuiWidget_onWake(o);
    if (o->a78) GuiWidget_SendMessage(o, o->a78, 10, 0, 0);
    if (o->a78) o->a78->a14 &= ~2;
    m = Gui_Canvas();
    m->a68 |= 0xC;
    ag = cGameSystem_GetAgentData(g_Game, -1);
    ag->aB68 = 0;
    ag->aB72 = 1;
    o->a158 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342F00(void) {}
#undef Gui_Canvas /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00342F00 */

/* merge_units: begin func_00342FA0 */
#pragma push /* merge_units */
typedef struct { char data[0x10]; __int128 key; } E;
typedef struct {
    char pad[0x80];
    E e[(0x22C0 - 0x80) / 0x20];
    short a[0x20];
    short b[0x20];
    char pad2340[0x2C0C - 0x2340];
    unsigned char u;
    signed char s;
} Sub;
typedef struct { char pad[0x60]; Sub sub; } P;
typedef struct { char pad[0x8C]; P *p; } O;
void GuiAgentModify_CheckBigPatch(O* o, int idx); /* gsynth: defined below */
#pragma cplusplus on
struct W_342FA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x44];
    void* f48;
};
typedef struct { char pad[0xA0]; char fA0[4]; } C_342FA0;
typedef struct { char pad[0xB70]; unsigned char bB70; } A_342FA0;
typedef struct {
    char pad[0x78]; W_342FA0* f78; W_342FA0* f7C; W_342FA0* f80; W_342FA0* f84; W_342FA0* f88; C_342FA0* f8C;
    char pad90[0x114 - 0x90];
    int f114; int f118; int f11C; int f120; int f124; int f128;
    W_342FA0* f12C; W_342FA0* f130; W_342FA0* f134; W_342FA0* f138; W_342FA0* f13C; W_342FA0* f140;
    W_342FA0* f144; W_342FA0* f148; W_342FA0* f14C; W_342FA0* f150; W_342FA0* f154;
} O_342FA0;
extern "C" {
extern char D_004B9F58[]; extern char D_004B9F50[]; extern char D_004B9F60[]; extern char D_004B9F68[];
extern char D_004B9F20[];
extern char D_004A9870[]; extern char D_004A9C40[]; extern char D_004A7520[]; extern char D_004B88F0[]; extern char D_004A9BF0[];
extern O_342FA0* D_005331D0;
void GuiWidget_onAdd(O_342FA0* o);
int SKL_FindPartIndex(void* p, char* name);
void GuiAgentModify_CheckSmallPatch(O_342FA0* o, int v);
#if 0 /* merge_units */
void GuiAgentModify_CheckBigPatch(O_342FA0* o, int v);
#endif /* merge_units */
#define GuiAgentModify_CheckBigPatch(a0, a1) (GuiAgentModify_CheckBigPatch((O *)(a0), (a1))) /* merge_units */


W_342FA0* GuiWidget_FindChild_charP(void* o, char* name);
void GuiAgentModify_MakeChildrenInvisible(O_342FA0* o, W_342FA0* w);
void AgentRenderWrapper(void);
#if 0 /* merge_units */
A_342FA0* cGameSystem_GetAgentData(void* p, int i);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((A_342FA0 *)cGameSystem_GetAgentData((a0), (a1))) /* merge_units */


char* cAgentData_GetUserName(A_342FA0* a);
char* AgentData_GetRankText(A_342FA0* a);
void GuiTextWidget_SetText(W_342FA0* w, char* s, int f);
int nGlobalization_GetStringIndex(char* k);
char* nGlobalization_GetString_int(int id);
void GuiAgentModify_TattooPatchesLockout(O_342FA0* o);
void GuiAgentModify_onAdd(O_342FA0* o);
}
static inline W_342FA0* Cast_342FA0(W_342FA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiAgentModify_onAdd(O_342FA0* o)
{
    W_342FA0* p;
    W_342FA0* a;
    W_342FA0* b;
    GuiWidget_onAdd(o);
    o->f114 = SKL_FindPartIndex(o->f8C->fA0, "TATT1");
    o->f118 = SKL_FindPartIndex(o->f8C->fA0, "TATT2");
    o->f11C = SKL_FindPartIndex(o->f8C->fA0, "TATT3");
    o->f120 = SKL_FindPartIndex(o->f8C->fA0, "PATC1");
    o->f124 = SKL_FindPartIndex(o->f8C->fA0, "PATC2");
    o->f128 = SKL_FindPartIndex(o->f8C->fA0, "PATC3");
    GuiAgentModify_CheckSmallPatch(o, o->f120);
    GuiAgentModify_CheckSmallPatch(o, o->f124);
    GuiAgentModify_CheckBigPatch(o, o->f128);
    o->f12C = Cast_342FA0(GuiWidget_FindChild_charP(o, "leftarm"), D_004A9870);
    o->f130 = Cast_342FA0(GuiWidget_FindChild_charP(o, "rightarm"), D_004A9870);
    o->f134 = Cast_342FA0(GuiWidget_FindChild_charP(o, "back"), D_004A9870);
    o->f138 = Cast_342FA0(GuiWidget_FindChild_charP(o, "leftarm2"), D_004A9870);
    o->f13C = Cast_342FA0(GuiWidget_FindChild_charP(o, "rightarm2"), D_004A9870);
    o->f140 = Cast_342FA0(GuiWidget_FindChild_charP(o, "hat2"), D_004A9870);
    o->f144 = Cast_342FA0(GuiWidget_FindChild_charP(o, D_004B9F58), D_004A9870);
    o->f148 = Cast_342FA0(GuiWidget_FindChild_charP(o, D_004B9F50), D_004A9870);
    o->f14C = Cast_342FA0(GuiWidget_FindChild_charP(o, D_004B9F60), D_004A9870);
    o->f150 = Cast_342FA0(GuiWidget_FindChild_charP(o, D_004B9F68), D_004A9870);
    o->f154 = GuiWidget_FindChild_charP(o, "createagent_grp");
    o->f78 = Cast_342FA0(GuiWidget_FindChild_charP(o, "selectindicator"), D_004A9C40);
    o->f7C = Cast_342FA0(GuiWidget_FindChild_charP(o, "value_slot"), D_004A7520);
    o->f88 = Cast_342FA0(GuiWidget_FindChild_charP(o, "beard"), D_004A9870);
    o->f80 = Cast_342FA0(GuiWidget_FindChild_charP(o, "bitmap_preview"), D_004B88F0);
    o->f84 = Cast_342FA0(GuiWidget_FindChild_charP(o, "value_name"), D_004A7520);
    GuiAgentModify_MakeChildrenInvisible(o, o->f144);
    GuiAgentModify_MakeChildrenInvisible(o, o->f148);
    GuiAgentModify_MakeChildrenInvisible(o, o->f14C);
    GuiAgentModify_MakeChildrenInvisible(o, o->f150);
    p = Cast_342FA0(GuiWidget_FindChild_charP(o, "playercharacter"), D_004A9BF0);
    if (p) {
        D_005331D0 = o;
        p->f48 = (void*)AgentRenderWrapper;
    }
    a = Cast_342FA0(GuiWidget_FindChild_charP(o, "value_agent"), D_004A7520);
    b = Cast_342FA0(GuiWidget_FindChild_charP(o, "value_rank"), D_004A7520);
    if (cGameSystem_GetAgentData(g_Game, -1)->bB70) {
        GuiTextWidget_SetText(a, cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game, -1)), 0);
        GuiTextWidget_SetText(b, AgentData_GetRankText(cGameSystem_GetAgentData(g_Game, -1)), 0);
    } else {
        GuiTextWidget_SetText(a, "Player", 0);
        GuiTextWidget_SetText(b, nGlobalization_GetString_int(nGlobalization_GetStringIndex("Rank_00") + 1), 0);
    }
    if (o->f7C) GuiTextWidget_SetText(o->f7C, D_004B9F20, 0);
    GuiAgentModify_TattooPatchesLockout(o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342FA0(void) {}
#undef GuiAgentModify_CheckBigPatch /* merge_units */
#undef cGameSystem_GetAgentData /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00342FA0 */

/* merge_units: begin func_00343680 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef union { __int128 q; char c[16]; } Key;




#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

extern int FindTex__7MonsterF1(void *t, __int128 key);
extern void Monster_FindTheTexture(void *t, __int128 key, E *e, short *a, short *b, unsigned char u, signed char s);

void GuiAgentModify_CheckBigPatch(O *o, int idx)
{
    Key k;
    char *lo, *hi, *b;
    int i;
    k.q = o->p->sub.e[idx].key;
    if (FindTex__7MonsterF1(g_AgentPartCache, k.q) != -1)
        return;
    
    b = k.c;
    lo = b + 12;
    hi = b + 11;
    i = 0;
    do {
        if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (FindTex__7MonsterF1(g_AgentPartCache, k.q) != -1) {
            Sub *s = &o->p->sub;
            Monster_FindTheTexture(g_AgentPartCache, k.q, &s->e[idx], &s->a[idx], &s->b[idx], s->u, s->s);
            o->p->sub.e[idx].key = k.q;
            return;
        }
    } while (++i < 0x20);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00343680(void) {}
#undef g_AgentPartCache /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00343680 */
