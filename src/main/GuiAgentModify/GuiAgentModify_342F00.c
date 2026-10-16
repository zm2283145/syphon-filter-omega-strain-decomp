/*
 * main/GuiAgentModify: range (3 files, 00342F00-00343680)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00342F00 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short a14; } W342F00;
typedef struct { char pad[0x78]; W342F00* a78; char pad7C[0xDC]; unsigned char a158; } S342F00;
typedef struct { char pad[0x2F]; unsigned char a2F; } G342F00;
typedef struct { char pad[0x68]; unsigned int a68; } M342F00;
typedef struct { char pad[0xB68]; unsigned char aB68; char padB69[9]; unsigned char aB72; } A342F00;
extern G342F00* D_004FFC04;
extern char D_004FFB50[];
extern void func_0041EFA0(S342F00* o);
extern void GuiWidget_SendEvent(void* self, void* w, int a, int b, int c);
extern M342F00* Gui_GetScreenStack(void);
extern A342F00* Agent_GetSelected(void* list, int idx);
void func_00342F00(S342F00* o)
{
    M342F00* m;
    A342F00* ag;
    D_004FFC04->a2F = 1;
    func_0041EFA0(o);
    if (o->a78) GuiWidget_SendEvent(o, o->a78, 10, 0, 0);
    if (o->a78) o->a78->a14 &= ~2;
    m = Gui_GetScreenStack();
    m->a68 |= 0xC;
    ag = Agent_GetSelected(D_004FFB50, -1);
    ag->aB68 = 0;
    ag->aB72 = 1;
    o->a158 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342F00(void) {}
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
void func_00343680(O* o, int idx); /* gsynth: defined below */
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
void GuiWidget_Init(O_342FA0* o);
int Appearance_FindPairByType(void* p, char* name);
void func_003437C0(O_342FA0* o, int v);
#if 0 /* merge_units */
void func_00343680(O_342FA0* o, int v);
#endif /* merge_units */
#define func_00343680(a0, a1) (func_00343680((O *)(a0), (a1))) /* merge_units */

W_342FA0* GuiWidget_FindChildByName(void* o, char* name);
void func_00341170(O_342FA0* o, W_342FA0* w);
void func_00345020(void);
#if 0 /* merge_units */
A_342FA0* Agent_GetSelected(void* p, int i);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((A_342FA0 *)Agent_GetSelected((a0), (a1))) /* merge_units */

char* AgentData_GetName(A_342FA0* a);
char* AgentData_GetRankText(A_342FA0* a);
void GuiTextWidget_SetText(W_342FA0* w, char* s, int f);
int Loc_FindKeyThunk(char* k);
char* Loc_GetTextById(int id);
void func_00340850(O_342FA0* o);
void func_00342FA0(O_342FA0* o);
}
static inline W_342FA0* Cast_342FA0(W_342FA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_00342FA0(O_342FA0* o)
{
    W_342FA0* p;
    W_342FA0* a;
    W_342FA0* b;
    GuiWidget_Init(o);
    o->f114 = Appearance_FindPairByType(o->f8C->fA0, "TATT1");
    o->f118 = Appearance_FindPairByType(o->f8C->fA0, "TATT2");
    o->f11C = Appearance_FindPairByType(o->f8C->fA0, "TATT3");
    o->f120 = Appearance_FindPairByType(o->f8C->fA0, "PATC1");
    o->f124 = Appearance_FindPairByType(o->f8C->fA0, "PATC2");
    o->f128 = Appearance_FindPairByType(o->f8C->fA0, "PATC3");
    func_003437C0(o, o->f120);
    func_003437C0(o, o->f124);
    func_00343680(o, o->f128);
    o->f12C = Cast_342FA0(GuiWidget_FindChildByName(o, "leftarm"), D_004A9870);
    o->f130 = Cast_342FA0(GuiWidget_FindChildByName(o, "rightarm"), D_004A9870);
    o->f134 = Cast_342FA0(GuiWidget_FindChildByName(o, "back"), D_004A9870);
    o->f138 = Cast_342FA0(GuiWidget_FindChildByName(o, "leftarm2"), D_004A9870);
    o->f13C = Cast_342FA0(GuiWidget_FindChildByName(o, "rightarm2"), D_004A9870);
    o->f140 = Cast_342FA0(GuiWidget_FindChildByName(o, "hat2"), D_004A9870);
    o->f144 = Cast_342FA0(GuiWidget_FindChildByName(o, D_004B9F58), D_004A9870);
    o->f148 = Cast_342FA0(GuiWidget_FindChildByName(o, D_004B9F50), D_004A9870);
    o->f14C = Cast_342FA0(GuiWidget_FindChildByName(o, D_004B9F60), D_004A9870);
    o->f150 = Cast_342FA0(GuiWidget_FindChildByName(o, D_004B9F68), D_004A9870);
    o->f154 = GuiWidget_FindChildByName(o, "createagent_grp");
    o->f78 = Cast_342FA0(GuiWidget_FindChildByName(o, "selectindicator"), D_004A9C40);
    o->f7C = Cast_342FA0(GuiWidget_FindChildByName(o, "value_slot"), D_004A7520);
    o->f88 = Cast_342FA0(GuiWidget_FindChildByName(o, "beard"), D_004A9870);
    o->f80 = Cast_342FA0(GuiWidget_FindChildByName(o, "bitmap_preview"), D_004B88F0);
    o->f84 = Cast_342FA0(GuiWidget_FindChildByName(o, "value_name"), D_004A7520);
    func_00341170(o, o->f144);
    func_00341170(o, o->f148);
    func_00341170(o, o->f14C);
    func_00341170(o, o->f150);
    p = Cast_342FA0(GuiWidget_FindChildByName(o, "playercharacter"), D_004A9BF0);
    if (p) {
        D_005331D0 = o;
        p->f48 = (void*)func_00345020;
    }
    a = Cast_342FA0(GuiWidget_FindChildByName(o, "value_agent"), D_004A7520);
    b = Cast_342FA0(GuiWidget_FindChildByName(o, "value_rank"), D_004A7520);
    if (Agent_GetSelected(D_004FFB50, -1)->bB70) {
        GuiTextWidget_SetText(a, AgentData_GetName(Agent_GetSelected(D_004FFB50, -1)), 0);
        GuiTextWidget_SetText(b, AgentData_GetRankText(Agent_GetSelected(D_004FFB50, -1)), 0);
    } else {
        GuiTextWidget_SetText(a, "Player", 0);
        GuiTextWidget_SetText(b, Loc_GetTextById(Loc_FindKeyThunk("Rank_00") + 1), 0);
    }
    if (o->f7C) GuiTextWidget_SetText(o->f7C, D_004B9F20, 0);
    func_00340850(o);
}
#undef func_00343680 /* merge_units */
#undef Agent_GetSelected /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00342FA0 */

/* merge_units: begin func_00343680 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef union { __int128 q; char c[16]; } Key;




extern char D_0055DDA0[];
extern int func_004027E0(void *t, __int128 key);
extern void func_004022E0(void *t, __int128 key, E *e, short *a, short *b, unsigned char u, signed char s);

void func_00343680(O *o, int idx)
{
    Key k;
    char *lo, *hi, *b;
    int i;
    k.q = o->p->sub.e[idx].key;
    if (func_004027E0(D_0055DDA0, k.q) != -1)
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
        if (func_004027E0(D_0055DDA0, k.q) != -1) {
            Sub *s = &o->p->sub;
            func_004022E0(D_0055DDA0, k.q, &s->e[idx], &s->a[idx], &s->b[idx], s->u, s->s);
            o->p->sub.e[idx].key = k.q;
            return;
        }
    } while (++i < 0x20);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00343680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00343680 */
