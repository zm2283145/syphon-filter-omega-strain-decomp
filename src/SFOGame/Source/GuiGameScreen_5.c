/*
 * SFOGame/Source/GuiGameScreen: 2 files, 0045C5E0-0045C760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045C5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Wd_5C5E0 { char pad[0x50]; float f50; char pad54[0xC]; char m60[0x40]; char padA0[4]; unsigned char bA4; };
struct Sub_5C5E0 { char pad[0x14]; unsigned short flags; };
struct Scr_5C5E0 {
    char pad[0x6C];
    Sub_5C5E0* sub;
    char pad70[4];
    int count;
    int* items;
    char pad7C[0x90 - 0x7C];
    int cur;
    char pad94[0xA8 - 0x94];
    Wd_5C5E0* panels[5];
    char padBC[0xD8 - 0xBC];
    int xD8;
};
extern "C" {
void GuiWeaponDisplay_SetItem(Wd_5C5E0* w, int item, int a, int b);
void GuiWeaponDisplay_SetWeapon(Wd_5C5E0* w, int item);
void GuiGameScreen_UpdateWeaponPanels(Scr_5C5E0* s);
}
static inline void UM(void* p0) { void* p = p0; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
#pragma opt_rotateloops off
void GuiGameScreen_UpdateWeaponPanels(Scr_5C5E0* s)
{
    int idx;
    bool done;
    int i;
    if (!s->sub || !(s->sub->flags & 4)) return;
    idx = s->cur;
    done = false;
    for (i = 0; i < 5; i++) {
        if (!done) {
            int item = s->items[idx];
            if (item == -2) GuiWeaponDisplay_SetItem(s->panels[i], -2, s->xD8, 0);
            else GuiWeaponDisplay_SetWeapon(s->panels[i], item);
            idx++;
            if (idx >= s->count) idx = 0;
            if (idx == s->cur) done = true;
        } else {
            GuiWeaponDisplay_SetWeapon(s->panels[i], -1);
        }
    }
    { Wd_5C5E0* p = s->panels[0]; p->bA4 = s->items[s->cur] != -2; }
    {
        Wd_5C5E0* w = s->panels[0];
        UM(w->m60);
        w->f50 = 0.0f;
    }
}
static inline void merge_flush_func_0045C5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C5E0 */

/* merge_units: begin func_0045C760 */
#pragma push /* merge_units */
typedef struct { char p0[8]; int id; char pc[4]; } Slot45;
typedef struct { Slot45 e[8]; char p80[4]; unsigned char sel; } Slots45;
typedef struct { char p[0x3524]; Slots45* s; } Gm45;
typedef struct { char p[0x30]; Gm45* g; } Root45;
typedef struct { char p[0x70]; PtrVec vec; char p7c[0x14]; int idx; char p94[0x48]; int vis; } W45C760;
extern Root45* g_LocalPlayer;
extern int D_00497B18;
extern int cWeapon_GetWeaponSlot(int);
extern void std_vector_int_push_back(PtrVec*, int*);
extern int cArray_int_Iterator_opNe(Iter*, Iter*);
extern Iter* func_0045C980(Iter*);
extern Word* func_0045C9A0(Word*, Iter*);
extern int* func_0045C9B0(Iter*);
extern void cArray_int_End(Iter*, PtrVec*);
extern void func_0045C9E0(Iter*, PtrVec*);
extern Word* func_0045C9F0(Word*, Iter*);
extern void std_vector_int_end_void_2(Iter*, PtrVec*);
static inline Word* find45(Word* out, Iter* b, Iter* e, int* v)
{
    while (cArray_int_Iterator_opNe(b, e)) {
        if (*v == *func_0045C9B0(b)) {
            func_0045C9A0(out, b);
            return out;
        }
        func_0045C980(b);
    }
    func_0045C9A0(out, e);
    return out;
}
void GuiGameScreen_BuildWeaponSelectList(W45C760* w)
{
    Slots45* s = g_LocalPlayer->g->s;
    int cur;
    int start, i, n;
    cur = s->sel != 6 ? s->e[s->sel].id : -1;
    w->vec.count = 0;
    w->idx = -1;
    start = cur != -1 ? (unsigned char)cWeapon_GetWeaponSlot(cur) : 0;
    i = start;
    n = 0;
    do {
        int item;
        Word found;
        Word endc;
        Iter tmp;
        Iter b;
        Iter e; Word* r;
        if ((item = s->e[i & 0xFF].id) != -1) {
            std_vector_int_end_void_2(&tmp, &w->vec);
            func_0045C9F0(&endc, &tmp);
            func_0045C9E0(&b, &w->vec);
            cArray_int_End(&e, &w->vec);
            if (r = find45(&found, &b, &e, &item), r->value == endc.value) {
                std_vector_int_push_back(&w->vec, &item);
                if (cur == item) w->idx = n;
                n++;
            }
        }
        i++;
        if (i >= 6) i = 0;
    } while (i != start);
    std_vector_int_push_back(&w->vec, &D_00497B18);
    if (w->idx == -1) w->idx = w->vec.count - 1;
    w->vis = w->vec.count < 5 ? w->vec.count : 5;
}
static inline void merge_flush_func_0045C760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C760 */
