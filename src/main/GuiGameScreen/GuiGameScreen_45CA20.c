/*
 * main/GuiGameScreen: range (2 files, 0045CA20-0045CC90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0045CA20 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W_45CA20;
typedef struct {
    char pad[0x6C]; W_45CA20* w; char pad70[0x20]; int f90; int f94; int f98; unsigned char f9C;
    char pad9D[3]; void* fA0; void* fA4; char padA8[0x28]; int fD0; int fD4; char padD8[4]; int fDC;
} S_45CA20;
typedef struct { char pad[0x6A8]; unsigned char busy; } G_45CA20;
extern G_45CA20* D_004FFC2C;
extern int D_00497ACC[];
extern int D_00497AEC[];
void GuiGameScreen_GatherWeapons(S_45CA20* o);
long long Time_GetMilliseconds(void);
void func_0045C5E0(S_45CA20* o);
void GuiWidget_SendEvent(void* a, void* b, int kind, int v, int f);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* mgr, void* w);
static inline float fmin_45CA20(float a, float b) { float r; asm { min.s r, a, b } return r; }

static inline unsigned char Has_45CA20(unsigned short* p, int m) { return (*p & m) != 0; }
static inline void Set_45CA20(unsigned short* p, int m) { *p |= m; }
void GuiGameScreen_ToggleWeaponSelect(S_45CA20* o, int on)
{
    W_45CA20* w = o->w;
    unsigned short* pf;
    if (w == 0) return;
    pf = &w->flags;
    if ((unsigned char)on == Has_45CA20(pf, 4)) return;
    if (on) {
        if (D_004FFC2C->busy) return;
        Set_45CA20(pf, 2);
        o->w->flags |= 4;
        GuiGameScreen_GatherWeapons(o);
        o->f94 = o->f90;
        o->f98 = Time_GetMilliseconds();
        o->f9C = 0;
        func_0045C5E0(o);
        if (o->fD4 == 0 && o->fD0 == 0) GuiWidget_SendEvent(o, o->fA4, 0xA, D_00497ACC[o->fDC], 0);
        o->fD4 = 1;
        o->fD0 = 2;
        GuiWidget_SendEvent(o, o->fA4, 0xB, D_00497AEC[o->fDC], 0);
        GuiWidget_SendEvent(o, o->fA0, 6, (int)"onWake", 0);
        o->w->flags |= 0x80;
        GuiScreen_SetFocus(Gui_GetScreenStack(), o->w);
        GuiWidget_SendEvent(o->w, Gui_GetScreenStack(), 0x10, 2, 0);
    } else {
        float v;
        o->fD4 = 0;
        o->fD0 = 2;
        v = 0;
        GuiWidget_SendEvent(o, o->fA4, 9, (int)&v, 0);
        v = fmin_45CA20((float)D_00497AEC[o->fDC], v);
        GuiWidget_SendEvent(o, o->fA4, 0xC, (int)v, D_00497ACC[o->fDC]);
        o->w->flags &= ~4;
        GuiWidget_SendEvent(o, o->fA0, 6, (int)"onSleep", 0);
        o->w->flags &= ~0x80;
        GuiScreen_SetFocus(Gui_GetScreenStack(), o);
        GuiWidget_SendEvent(o->w, Gui_GetScreenStack(), 0x10, 3, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CA20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045CA20 */

/* merge_units: begin func_0045CC90 */
#pragma push /* merge_units */
typedef struct { float x, y; } Vec2_45CC90;
typedef struct {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    Vec2_45CC90 pos;
    Vec2_45CC90 size;
    char pad44[0xA4 - 0x44];
    unsigned char fA4;
} W_45CC90;
typedef struct {
    char pad0[0x6C];
    W_45CC90* root;
    char pad70[0x90 - 0x70];
    int f90;
    int f94;
    int f98;
    unsigned char f9C;
    char pad9D[0xA8 - 0x9D];
    W_45CC90* items[5];
    char padBC[0xD0 - 0xBC];
    int fD0;
    int fD4;
    char fD8[4];
    int fDC;
} S_45CC90;
extern char D_004C2210[];
extern char D_004C2228[];
extern void* D_004FFD30;
extern void* D_00497AC0;
extern W_45CC90* GuiFactory_CreateWidget(char*);
extern W_45CC90* GuiWidget_FindChildByName(W_45CC90*, char*);
extern void func_0041EBA0(W_45CC90*, float, float);
extern void GuiWidget_AddChild(W_45CC90*, W_45CC90*);
extern void WeaponDb_LoadModel(void* m, void* a, void* b, int c, int d, int e, int f);

static inline void SetSize(W_45CC90* w, float x, float y)
{
    w->size.x = x;
    w->size.y = y;
}

void GuiGameScreen_InitWeaponSelect(S_45CC90* self)
{
    int i;
    char buf[16];
    if (self->root == 0) {
        return;
    }
    self->f90 = -1;
    self->fDC = 0;
    self->f94 = -1;
    self->f9C = 0;
    self->f98 = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    self->root->flags &= ~2;
    self->root->flags &= ~4;
    for (i = 0; i < 5; i++) {
        W_45CC90* ref;
        Vec2_45CC90 p;
        Vec2_45CC90 s;
        self->items[i] = GuiFactory_CreateWidget(D_004C2210);
        sprintf(buf, D_004C2228, i + 1);
        ref = GuiWidget_FindChildByName(self->root, buf);
        p = ref->pos;
        func_0041EBA0(self->items[i], p.x, p.y);
        s = ref->size;
        SetSize(self->items[i], s.x, s.y);
        GuiWidget_AddChild(self->root, self->items[i]);
        self->items[i]->fA4 = 0;
    }
    WeaponDb_LoadModel(D_004FFD30, D_00497AC0, self->fD8, -1, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045CC90 */
