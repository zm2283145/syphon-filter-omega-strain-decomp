/*
 * main/GuiMissionList: range (2 files, 002ACA00-002ACB70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);

/* merge_units: begin func_002ACA00 */
#pragma push /* merge_units */
typedef struct { int id; int idx; int fl; } It_002ACA00;
typedef struct { char pad0[0x11C]; void* p11C; } S_002ACA00;
typedef struct {
    int f0; char name[0x20]; int f24; char pad28[0x34 - 0x28]; int f34; int f38; char pad3C[0x44 - 0x3C]; int f44;
} E_002ACA00;
extern S_002ACA00* D_005065C0;
#define SFOLobbyList_GetSlot(a0, a1) ((E_002ACA00 *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */
int GuiMissionList_Sort_DisplayGames(const void* a, const void* b)
{
    E_002ACA00* e1 = SFOLobbyList_GetSlot(D_005065C0->p11C, ((It_002ACA00*)a)->idx);
    E_002ACA00* e2 = SFOLobbyList_GetSlot(D_005065C0->p11C, ((It_002ACA00*)b)->idx);
    int r1;
    int r2;
    if (!e1 || !e2)
        return 0;
    r2 = r1 = 5;
    if (e1->f44 == 1)
        r1 = 1;
    if (e2->f44 == 1)
        r2 = 1;
    if (e1->f44 == 2)
        r1 = 2;
    if (e2->f44 == 2)
        r2 = 2;
    if (r1 != r2)
        return r1 - r2;
    if (e1->f24 == 0)
        r1 = 3;
    if (e2->f24 == 0)
        r2 = 3;
    if (e1->f24 == 1)
        r1 = 4;
    if (e2->f24 == 1)
        r2 = 4;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f38 - 4;
    r2 += e2->f38 - 4;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f34 - 4;
    r2 += e2->f34 - 4;
    if (r1 != r2)
        return r1 - r2;
    return strcmp(e1->name, e2->name);
}
#undef SFOLobbyList_GetSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002ACA00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002ACA00 */

/* merge_units: begin func_002ACB70 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_002ACB70 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct S_002ACB70 : W_002ACB70 {
    char pad4[0x48 - 4]; int f48; int f4C; int f50; unsigned int f54; char pad58[0x74 - 0x58];
    int f74; char pad78[0x7C - 0x78]; unsigned int f7C; char pad80[0xCC - 0x80];
    int fCC; char padD0[0x110 - 0xD0]; int count; char pad114[0x11C - 0x114]; void* p11C;
};
extern "C" {
void GuiMissionList_UpdateSelectList(S_002ACB70* self);
void GuiArrayWidget_SetSelected(S_002ACB70* self, int a, int b);
int GuiArrayWidget_IsVisible(S_002ACB70* self, int a, unsigned int b);
void GuiArrayWidget_MakeVisible(S_002ACB70* self, int a, unsigned int b);
void SFOLobbyList_SetUpdateFlag(void* p, int a);
}
static inline void Upd_(S_002ACB70* s, int n) { s->SetCount(s->f48, n); }
#pragma opt_dead_assignments off
extern "C" void GuiMissionList_UpdateLobbyList(S_002ACB70* self)
{
    unsigned int old = 0;
    if (self->f54 > self->f7C)
        old = self->f54 - self->f7C;
    GuiMissionList_UpdateSelectList(self);
    Upd_(self, self->count);
    GuiArrayWidget_SetSelected(self, 0, self->fCC);
    if (self->f54 >= self->f7C) {
        unsigned int d = self->f54 - self->f7C;
        if (d != old) {
            int v;
            d -= old;
            v = d + self->f7C;
            int lim = self->f4C - self->f74;
            if (v >= lim)
                v = lim;
            if (v < 0)
                v = 0;
            self->f7C = v;
        }
    }
    if (!GuiArrayWidget_IsVisible(self, self->f50, self->f54))
        GuiArrayWidget_MakeVisible(self, self->f50, self->f54);
    if (self->p11C)
        SFOLobbyList_SetUpdateFlag(self->p11C, 0);
}



#pragma opt_dead_assignments reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002ACB70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002ACB70 */
